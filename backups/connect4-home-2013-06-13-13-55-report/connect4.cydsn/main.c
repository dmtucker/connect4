#include <device.h>
#include <stdbool.h>
#include <display.h>
#include <matrix.h>

#define BUS_CLK_FREQ    24000000 // Hz
#define REFRESH_RATE    3000     // [370,BUS_CLK_FREQ] Hz
#define XBEE_CONFIGURED false
#define XBEE_VERIFY     true
#define XBEE_GUARD_TIME 1000     // ms
#define XBEE_CHANNEL    0x0C     // [0x0B,0x1A]
#define XBEE_REMEMBER   false
#define PLAYER1_ID      0xDA     // [0x00,0xFF]
#define PLAYER2_ID      0x85     // ID > max(MATRIX_ROWS,MATRIX_COLS) recommended
#define PACKET_TYPE     0x00     // version

typedef struct play {
    uint8  row;
    uint8  col;
} play_t;

bool  player1_turn  = true;
bool  player2_local = true;
uint8 player1_color = RED;
uint8 player2_color = BLUE;
//uint8 XBee_channel  = XBEE_CHANNEL;

bool  player1[MATRIX_ROWS][MATRIX_COLS];
bool  player2[MATRIX_ROWS][MATRIX_COLS];
play_t last_move;

void  initialize     ( );
void  clear_board    ( );
void  configure_XBee ( );//uint8 channel );
uint8 get_move       ( );
uint8 receive_move   ( ); 
void  receive_packet ( play_t * move );
void  send_packet    ( play_t * move );
void  send_move      ( uint8 row , uint8 col );
uint8 animate        ( uint8 c );
void  winner_check   ( );
void  cleanup        ( );

//void  receive_packet ( packet_t * move );
//void  show_packet    ( packet_t * move );
//void  send_packet    ( packet_t * move );
//void  send_move      ( uint8 r , uint8 c ); 




bool locating = false;//, channel_change = false;
CY_ISR (toggle) {
    if (locating) player2_local = !player2_local;
    //else channel_change = true;
}




uint8 rPos = -1, cPos = -1;
CY_ISR (refresh) {
    if (false) {
    //if (SERIAL) {
        /**/
        matrix_deluminate();
        if (++cPos > MATRIX_COLS) cPos = 0;
        for (rPos=0; rPos < MATRIX_ROWS ;++rPos) {
            if (player1[rPos][cPos]) matrix_illuminate(rPos,cPos,player1_color);
            if (player2[rPos][cPos]) matrix_illuminate(rPos,cPos,player2_color);
        }
        /**
        matrix_deluminate();
        if (++rPos > MATRIX_ROWS) rPos = 0;
        for (cPos=0; cPos < MATRIX_COLS ;++cPos) {
            if (player1[rPos][cPos]) matrix_illuminate(rPos,cPos,player1_color);
            if (player2[rPos][cPos]) matrix_illuminate(rPos,cPos,player2_color);
        }
        /**/
    }
    else {
        uint16 cells = MATRIX_ROWS*MATRIX_COLS;
        while (cells-- > 0) {
            if (++cPos > MATRIX_COLS) {
                cPos = 0;
                if (++rPos > MATRIX_ROWS) rPos = 0;
            }
            if (player1[rPos][cPos]) {
                //matrix_deluminate();
                matrix_illuminate(rPos,cPos,player1_color);
                break;
            }
            if (player2[rPos][cPos]) {
                matrix_deluminate();
                matrix_illuminate(rPos,cPos,player2_color);
                break;
            }
        }
    }
}




void main () {
    initialize();
    LCD_UpdateStatus("Connect 4");
    while (true) {
        uint8 row, col;
        if (player1_turn || player2_local) {
            LCD_UpdateStatus((player1_turn) ? "Player 1" : "Player 2");
            col = get_move();
            row = animate(col);
            if (!player2_local) send_move(MATRIX_ROWS-row,col+1);
        }
        else {
            LCD_UpdateStatus("Player 2");
            col = receive_move();
            row = animate(col);
        }
        winner_check();
        player1_turn = !player1_turn;
        
        /*
        if (channel_change) {
            if (++XBee_channel > 0x1A) XBee_channel = 0x0B;
            configure_XBee(XBee_channel);
            channel_change = false;
            LCD_UpdateStatus("Change Channel");
            LCD_ClearLine(1);
            LCD_PrintString("0x");
            LCD_PrintInt8(XBee_channel);
            CyDelay(500);
        }
        */
    }
    cleanup();
}




void initialize () {
    LCD_Start();
    LCD_UpdateStatus("initializing...");
    
    LCD_UpdateMessage("board");
    clear_board();
    
    LCD_UpdateMessage("matrix");
    matrix_test(true,false);
    matrix_deluminate();
    
    LCD_UpdateMessage("interrupts");
    CyGlobalIntEnable;
    
    LCD_UpdateMessage("timer");
    Timer_Start();
    Timer_WritePeriod(BUS_CLK_FREQ/REFRESH_RATE);
    
    LCD_UpdateMessage("CapSense");
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    
    LCD_UpdateStatus("locate opponent");
    ISR_StartEx(toggle);
    locating = true;
    uint8 t;
    for (t=5; t > 0 ;--t) {
        LCD_UpdateMessage((player2_local) ? "local" : "remote");
        CyDelay(500);
        LCD_Position(1,15);
        LCD_PrintNumber(t);
        CyDelay(500);
    }
    locating = false;
    ISR_Stop();
    if (!player2_local) {
        LCD_UpdateStatus("initializing...");
        LCD_UpdateMessage("UART");
        UART_Start();
        UART_ClearTxBuffer();
        UART_ClearRxBuffer();
        LCD_UpdateMessage("XBee");
        if (!XBEE_CONFIGURED) configure_XBee();//XBee_channel);
    }
    
    LCD_UpdateMessage("display");
    Beam_StartEx(refresh);
}




void clear_board () {
    uint8 row, col;
    for (row=0; row < MATRIX_ROWS ;++row) {
        for (col=0; col < MATRIX_COLS ;++col) {
            player1[row][col] = false;
            player2[row][col] = false;
        }
    }
}




void configure_XBee () {//uint8 channel ) {
    //if (!channel_change) {
        LCD_Position(1,5);
        LCD_PrintString("Config");
    //}
    CyDelay(XBEE_GUARD_TIME);
    UART_PutString("+++");
    CyDelay(XBEE_GUARD_TIME*3);
    if (XBEE_VERIFY) {
        while (UART_GetRxBufferSize() < 3);
        if (UART_ReadRxData() != 'O'
        ||  UART_ReadRxData() != 'K'
        ||  UART_ReadRxData() != '\r') Error_Write(0x01);
    }
    
    //if (!channel_change) {
        LCD_Position(1,5);
        LCD_PrintString("API Mode");
    //}
    UART_PutString("ATAP1\r");
    if (XBEE_VERIFY) {
        while (UART_GetRxBufferSize() < 3);
        if (UART_ReadRxData() != 'O'
        ||  UART_ReadRxData() != 'K'
        ||  UART_ReadRxData() != '\r') Error_Write(0x01);
    }
    
    //if (!channel_change) {
        LCD_Position(1,5);
        LCD_PrintString("Channel ");
    //}
    UART_PutString("ATCH");
    UART_WriteTxData(XBEE_CHANNEL);//channel);
    UART_PutChar('\r');
    if (XBEE_VERIFY) {
        while (UART_GetRxBufferSize() < 3);
        if (UART_ReadRxData() != 'O'
        ||  UART_ReadRxData() != 'K'
        ||  UART_ReadRxData() != '\r') Error_Write(0x01);
    }
    
    if (XBEE_REMEMBER) {
        //if (!channel_change) {
            LCD_Position(1,5);
            LCD_PrintString("Write   ");
        //}
        UART_PutString("ATWR\r");
        if (XBEE_VERIFY) {
            while (UART_GetRxBufferSize() < 3);
        if (UART_ReadRxData() != 'O'
        ||  UART_ReadRxData() != 'K'
        ||  UART_ReadRxData() != '\r') Error_Write(0x01);
        }
    }
    
    //if (!channel_change) {
        LCD_Position(1,5);
        LCD_PrintString("Ready   ");
    //}
    UART_PutString("ATCN\r");
    if (XBEE_VERIFY) {
        while (UART_GetRxBufferSize() < 3);
        if (UART_ReadRxData() != 'O'
        ||  UART_ReadRxData() != 'K'
        ||  UART_ReadRxData() != '\r') Error_Write(0x01);
    }
    
    Remote_Write(0x01);
}




uint8 get_move () {
    LCD_UpdateMessage("Place a disc!");
    
    //guide
    uint8 disc = 0;
    while (player1[1][disc] || player2[1][disc]) {
        if (++disc >= MATRIX_COLS) {
            LCD_UpdateStatus("Game Over");
            LCD_UpdateMessage("Board Full");
            while (true);
        }
    }
    
    bool selected = false, dropped = false;
    do {
        CapSense_UpdateEnabledBaselines();
        CapSense_ScanEnabledWidgets();
        while (CapSense_IsBusy());
        if (CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN)) {
            if (player1[1][disc] || player2[1][disc]) LCD_UpdateMessage("Column Full");
            else selected = true;
        }
        else {
            if (selected) dropped = true;
            else {
                player1[0][disc] = player2[0][disc] = false;
                uint16 reading = (CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS)*(MATRIX_COLS-1))/97; // DEBUG 97?
                if (reading < 8) disc = reading;
                
                //guide
                int dir = 1;
                while (player1[1][disc] || player2[1][disc]) {
                    if (disc >= MATRIX_COLS-1)  dir = -1;
                    if (disc == 0 && dir == -1) dir =  1; // DEBUG redundant?
                    disc += dir;
                }
                if (player1_turn) player1[0][disc] = true;
                else              player2[0][disc] = true;
            }
        }
    } while (!dropped);
    player1[0][disc] = player2[0][disc] = false;
    return disc;
}




uint8 receive_move () {
    play_t move;
    while (true) {
        receive_packet(&move);
        move.row = MATRIX_ROWS-move.row;
        --move.col;
        if (player2[move.row][move.col]) send_packet(&last_move);
        else break;
    }
    UART_ClearRxBuffer();
    return move.col; 
}




void receive_packet ( play_t * move ) {
    UART_ClearRxBuffer();
    while (true) {
        LCD_UpdateMessage("waiting");
        LCD_Position(1,7);
        LCD_PrintString("         ");
        LCD_Position(1,7);
        uint8 vol;
        for (vol=(UART_GetRxBufferSize()*8)/128; vol > 0 ;--vol) LCD_PutChar('.');
        
        do if (UART_GetTxBufferSize() == 0) {
            send_packet(&last_move);
            CyDelay(50);
        }
        while (UART_GetRxBufferSize() < 4);
        if (UART_ReadRxData() != PLAYER2_ID) continue;
        
        while (UART_GetRxBufferSize() == 0);
        if (UART_ReadRxData() != PACKET_TYPE); // DEBUG newer?
        
        while (UART_GetRxBufferSize() == 0);
        move->row = UART_ReadRxData();
        if (move->row < 1 || move->row > MATRIX_ROWS-1) continue;
        
        while (UART_GetRxBufferSize() == 0);
        move->col = UART_ReadRxData();
        if (move->col < 1 || move->row > MATRIX_COLS) continue;
        
        break;
    }
}




void send_packet ( play_t * move ) {

    /**************************/
    char   delimiter   = '~';
    uint8  api_id      = 0x01;
    uint8  frame_id    = 0x00;
    uint16 destination = 0xFFFF; //broadcast
    uint8  disable_ack = 0x01;
    /**************************/
    
    uint16 length = sizeof(destination) +
                    sizeof(api_id) +
                    sizeof(frame_id) +
                    sizeof(disable_ack) +
                    4; //Payload: Player ID, Packet Type, Row, Column
    
    uint8 checksum = 0xFF - (uint8) (api_id +
                                     frame_id +
                                    ((uint8) (destination >> 8)) +
                                    ((uint8)  destination) +
                                     disable_ack +
                                     PLAYER1_ID +
                                     PACKET_TYPE +
                                     move->row +
                                     move->col);
    
    
    /* DEBUG *
    uint16 delay = 100;
    
    LCD_UpdateStatus("Delimiter");
    LCD_ClearLine(1);
    LCD_PutChar(delimiter);
    LCD_Position(1,2);
    LCD_PrintNumber(delimiter);
    CyDelay(delay);
    
    LCD_UpdateStatus("Length");
    LCD_ClearLine(1);
    LCD_PrintNumber(length);
    CyDelay(delay);
    
    LCD_UpdateStatus("API ID");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(api_id);
    CyDelay(delay);
    
    LCD_UpdateStatus("Frame ID");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(frame_id);
    CyDelay(delay);
    
    LCD_UpdateStatus("Destination");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt16(destination);
    CyDelay(delay);
    
    LCD_UpdateStatus("Disable ACK");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(disable_ack);
    CyDelay(delay);
    
    LCD_UpdateStatus("Player ID");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(PLAYER1_ID);
    CyDelay(delay);
    
    LCD_UpdateStatus("Packet Type");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(PACKET_TYPE);
    CyDelay(delay);
    
    LCD_UpdateStatus("Row");
    LCD_ClearLine(1);
    LCD_PrintNumber(move->row);
    CyDelay(delay);
    
    LCD_UpdateStatus("Column");
    LCD_ClearLine(1);
    LCD_PrintNumber(move->col);
    CyDelay(delay);
    
    LCD_UpdateStatus("Checksum");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(checksum);
    CyDelay(delay);
    /**/
    
    
    UART_ClearTxBuffer();
    UART_WriteTxData(delimiter);
    UART_WriteTxData((uint8) (length >> 8));
    UART_WriteTxData((uint8)  length);
    UART_WriteTxData(api_id);
    UART_WriteTxData(frame_id);
    UART_WriteTxData((uint8) (destination >> 8));
    UART_WriteTxData((uint8)  destination);
    UART_WriteTxData(disable_ack);
    UART_WriteTxData(PLAYER1_ID);
    UART_WriteTxData(PACKET_TYPE);
    UART_WriteTxData(move->row);
    UART_WriteTxData(move->col);
    UART_WriteTxData(checksum);
}




void send_move ( uint8 row , uint8 col )  {
    last_move.row = row;
    last_move.col = col;
    send_packet(&last_move);
}




uint8 animate ( uint8 col ) {
    uint8 row;
    for (row=1; row < MATRIX_ROWS ;++row) {
        if (player1_turn) player1[row][col] = true;
        else              player2[row][col] = true;
        if (player1[row+1][col] || player2[row+1][col] || row+1 == MATRIX_ROWS) break;
        else CyDelay(20);
        if (player1_turn) player1[row][col] = false;
        else              player2[row][col] = false;
    }
    return row;
}




void winner_check () {
    uint8 row, col;
    uint16 strobe = 100;
    for (row=1; row < MATRIX_ROWS ;++row) {
        for (col=0; col < MATRIX_COLS ;++col) {
            int offset;
            
            //vertical
            if (row < MATRIX_ROWS-3) {
                bool win = true;
                for (offset=0; win && offset < 4 ;++offset) {
                    if (player1_turn) { if (!player1[row+offset][col]) win = false; }
                    else              { if (!player2[row+offset][col]) win = false; }
                }
                if (win) {
                    LCD_UpdateMessage("You win!");
                    bool blink = false;
                    while (true) {
                        for (offset=0; win && offset < 4 ;++offset) {
                            if (player1_turn) player1[row+offset][col] = blink;
                            else              player2[row+offset][col] = blink;
                        }
                        CyDelay(strobe);
                        blink = !blink;
                    }
                }
            }
            
            //lateral
            if (col < MATRIX_COLS-3) {
                bool win = true;
                for (offset=0; win && offset < 4 ;++offset) {
                    if (player1_turn) { if (!player1[row][col+offset]) win = false; }
                    else              { if (!player2[row][col+offset]) win = false; }
                }
                if (win) {
                    LCD_UpdateMessage("You win!");
                    bool blink = false;
                    while (true) {
                        for (offset=0; win && offset < 4 ;++offset) {
                            if (player1_turn) player1[row][col+offset] = blink;
                            else              player2[row][col+offset] = blink;
                        }
                        CyDelay(strobe);
                        blink = !blink;
                    }
                }
            }
            
            //down-diagonal
            if (row < MATRIX_ROWS-3 && col < MATRIX_COLS-3) {
                bool win = true;
                for (offset=0; win && offset < 4 ;++offset) {
                    if (player1_turn) { if (!player1[row+offset][col+offset]) win = false; }
                    else              { if (!player2[row+offset][col+offset]) win = false; }
                }
                if (win) {
                    LCD_UpdateMessage("You win!");
                    bool blink = false;
                    while (true) {
                        for (offset=0; win && offset < 4 ;++offset) {
                            if (player1_turn) player1[row+offset][col+offset] = blink;
                            else              player2[row+offset][col+offset] = blink;
                        }
                        CyDelay(strobe);
                        blink = !blink;
                    }
                }
            }
            
            //up-diagonal
            if (row > 3 && col < MATRIX_COLS-3) {
                bool win = true;
                for (offset=0; win && offset < 4 ;++offset) {
                    if (player1_turn) { if (!player1[row-offset][col+offset]) win = false; }
                    else              { if (!player2[row-offset][col+offset]) win = false; }
                }
                if (win) {
                    LCD_UpdateMessage("You win!");
                    bool blink = false;
                    while (true) {
                        for (offset=0; win && offset < 4 ;++offset) {
                            if (player1_turn) player1[row-offset][col+offset] = blink;
                            else              player2[row-offset][col+offset] = blink;
                        }
                        CyDelay(strobe);
                        blink = !blink;
                    }
                }
            }  
        }
    }
}




void cleanup () {
    LCD_UpdateStatus("cleaning...");
    
    LCD_UpdateMessage("display");
    Beam_Stop();
    
    if (!player2_local) {
        LCD_UpdateMessage("UART");
        UART_Stop();
    }
    
    LCD_UpdateMessage("CapSense");
    CapSense_Stop();
    
    LCD_UpdateMessage("timer");
    Timer_Stop();
    
    LCD_UpdateMessage("matrix");
    matrix_deluminate();
    
    LCD_UpdateMessage("board");
    clear_board();
    
    LCD_Stop();
}









/*
typedef struct packet {
    char   delimiter;
    uint16 length;
    uint8  api_id;
    uint8  frame_id;
    uint16 destination;
    uint8  disable_ack;
    uint8  player_id;
    uint8  packet_type;
    uint8  row;
    uint8  col;
    uint8  checksum;
} packet_t;




packet_t last_move;




void receive_move () {
    packet_t move;
    while (true) {
        receive_packet(&move);
        if (player2[MATRIX_ROWS-move.row][move.col-1]) send_packet(&last_move);
        else break;
    }
    player2[MATRIX_ROWS-move.row][move.col-1] = true;
    UART_ClearRxBuffer(); 
}




void receive_packet ( packet_t * move ) {
    UART_ClearRxBuffer();
    while (true) {
        LCD_UpdateMessage("waiting"); // DEBUG
        
        while (UART_GetRxBufferSize() == 0);
        do move->delimiter = UART_ReadRxData();
        while (move->delimiter != '~' && UART_GetRxBufferSize() > 0);
        
        
        /* DEBUG *
        LCD_UpdateMessage("received");
        LCD_Position(1,12);
        uint16 tst = UART_GetRxBufferSize();
        LCD_PrintNumber(tst);
        CyDelay(1000);
        /**
        
        
        if (move->delimiter != '~') continue;
        
        while (UART_GetRxBufferSize() == 0);
        move->length   = UART_ReadRxData();
        move->length <<= 8;
        while (UART_GetRxBufferSize() == 0);
        move->length  |= UART_ReadRxData();
        
        while (UART_GetRxBufferSize() == 0);
        move->api_id = UART_ReadRxData();
        //if (move->api_id != 0x01) continue; //means what??? 0,1,2?
        
        while (UART_GetRxBufferSize() == 0);
        move->frame_id = UART_ReadRxData();
        //if (move->frame_id != 0x00) continue; //maybe this needs to be a sequence #?
        
        while (UART_GetRxBufferSize() == 0);
        move->destination   = UART_ReadRxData();
        move->destination <<= 8;
        while (UART_GetRxBufferSize() == 0);
        move->destination  |= UART_ReadRxData();
        if (move->destination != 0xFFFF) continue; //compare to xbee src addr
        
        while (UART_GetRxBufferSize() == 0);
        move->disable_ack = UART_ReadRxData();
        //if (move->disable_ack != 0x01) continue; //ack?
        
        while (UART_GetRxBufferSize() == 0);
        move->player_id = UART_ReadRxData();
        if (move->player_id != PLAYER2_ID) continue;
        
        while (UART_GetRxBufferSize() == 0);
        move->packet_type = UART_ReadRxData();
        //if (move->packet_type != 0x00); //a later version is trying to play with this game
        
        while (UART_GetRxBufferSize() == 0);
        move->row = UART_ReadRxData();
        if (move->row < 1 || move->row > MATRIX_ROWS-1) continue;
        
        while (UART_GetRxBufferSize() == 0);
        move->col = UART_ReadRxData();
        if (move->col < 1 || move->row > MATRIX_COLS) continue;
        
        while (UART_GetRxBufferSize() == 0);
        move->checksum = UART_ReadRxData();
        /*
        if ((move->api_id +
             move->frame_id +
             move->destination +
             move->disable_ack +
             move->player_id +
             move->packet_type +
             move->row +
             move->col + 
             move->checksum) != 0xFF) continue;
        *
        
        break;
    }
}




void show_packet ( packet_t * move ) {
    uint16 delay = 100;
    
    LCD_UpdateStatus("Delimiter");
    LCD_ClearLine(1);
    LCD_PutChar(move->delimiter);
    LCD_Position(1,2);
    LCD_PrintNumber(move->delimiter);
    CyDelay(delay);
    
    LCD_UpdateStatus("Length");
    LCD_ClearLine(1);
    LCD_PrintNumber(move->length);
    CyDelay(delay);
    
    LCD_UpdateStatus("API ID");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->api_id);
    CyDelay(delay);
    
    LCD_UpdateStatus("Frame ID");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->frame_id);
    CyDelay(delay);
    
    LCD_UpdateStatus("Destination");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt16(move->destination);
    CyDelay(delay);
    
    LCD_UpdateStatus("Disable ACK");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->disable_ack);
    CyDelay(delay);
    
    LCD_UpdateStatus("Player ID");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->player_id);
    CyDelay(delay);
    
    LCD_UpdateStatus("Packet Type");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->packet_type);
    CyDelay(delay);
    
    LCD_UpdateStatus("Row");
    LCD_ClearLine(1);
    LCD_PrintNumber(move->row);
    CyDelay(delay);
    
    LCD_UpdateStatus("Column");
    LCD_ClearLine(1);
    LCD_PrintNumber(move->col);
    CyDelay(delay);
    
    LCD_UpdateStatus("Checksum");
    LCD_ClearLine(1);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->checksum);
    CyDelay(delay);
}




void send_packet ( packet_t * move ) {
    UART_ClearTxBuffer();
    UART_WriteTxData(move->delimiter);
    UART_WriteTxData((uint8) (move->length >> 8)); //was 4! changed to 8 after migrating @ 5am
    UART_WriteTxData((uint8) move->length);
    UART_WriteTxData(move->api_id);
    UART_WriteTxData(move->frame_id);
    UART_WriteTxData((uint8) (move->destination >> 8)); //was 4! changed to 8 after migrating @ 5am
    UART_WriteTxData((uint8) (move->destination));
    UART_WriteTxData(move->disable_ack);
    UART_WriteTxData(move->player_id);
    UART_WriteTxData(move->packet_type);
    UART_WriteTxData(move->row);
    UART_WriteTxData(move->col);
    UART_WriteTxData(move->checksum);
}




void send_move ( uint8 r , uint8 c )  {
    last_move.delimiter   = '~';
    last_move.length      = 13 - (sizeof(last_move.delimiter) +
                                  sizeof(last_move.length) +
                                  sizeof(last_move.checksum));
    last_move.api_id      = 0x01;
    last_move.frame_id    = 0x00;
    last_move.destination = 0xFFFF;
    last_move.disable_ack = 0x01;
    last_move.player_id   = PLAYER1_ID;
    last_move.packet_type = 0x00;
    last_move.row         = r;
    last_move.col         = c;
    last_move.checksum    = 0xFF - (uint8) (last_move.api_id +
                                            last_move.frame_id +
                                           (last_move.destination >> 8) +
                                           ((uint8) last_move.destination) +
                                            last_move.disable_ack +
                                            last_move.player_id +
                                            last_move.packet_type +
                                            last_move.row +
                                            last_move.col);
    send_packet(&last_move);
}
*/
