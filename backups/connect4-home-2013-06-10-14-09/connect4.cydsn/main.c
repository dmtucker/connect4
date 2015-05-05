#include <device.h>
#include <stdbool.h>
#include <display.h>
#include <matrix.h>

#define BUS_CLK_FREQ    1000000 // Hz
#define REFRESH_RATE    3500    // Hz
#define XBEE_GUARD_TIME 1000    // ms
#define XBEE_CHANNEL    0x0F
#define PLAYER1_ID      0xDA
#define PLAYER2_ID      0x07

bool  player1[MATRIX_ROWS][MATRIX_COLS];
bool  player2[MATRIX_ROWS][MATRIX_COLS];
uint8 player1_color = RED;
uint8 player2_color = BLUE;
bool  player1_turn  = true;
bool  player2_local = true;

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




void configure_XBee () {
    do {
        CyDelay(XBEE_GUARD_TIME);
        UART_PutString("+++");
        CyDelay(XBEE_GUARD_TIME);
        while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    }
    while (UART_ReadRxData() != 'O' && UART_ReadRxData() != 'K' && UART_ReadRxData() != '\r');
    UART_PutString("ATAP1\r");
    while (UART_ReadRxData() != 'O' && UART_ReadRxData() != 'K' && UART_ReadRxData() != '\r');
    UART_PutString("ATCH");
    UART_WriteTxData(XBEE_CHANNEL);
    UART_PutChar('\r');
    while (UART_ReadRxData() != 'O' && UART_ReadRxData() != 'K' && UART_ReadRxData() != '\r');
    //UART_PutString("ATWR\r");
    //while (UART_ReadRxData() != 'O' && UART_ReadRxData() != 'K' && UART_ReadRxData() != '\r');
    UART_PutString("ATCN\r");
    RemoteLED_Write(0x01);
}




void clear_board () {
    uint8 r, c;
    for (r=0; r < MATRIX_ROWS ;++r) {
        for (c=0; c < MATRIX_COLS ;++c) {
            player1[r][c] = false;
            player2[r][c] = false;
        }
    }
}




bool locating = false;
CY_ISR (toggle) { if (locating) player2_local = !player2_local; }




uint8 row, col;
CY_ISR (refresh) {
    int cells = MATRIX_ROWS*MATRIX_COLS;
    while (cells-- > 0) {
        if (++col > MATRIX_COLS) {
            col = 0;
            if (++row > MATRIX_ROWS) row = 0;
        }
        if (player1[row][col]) {
            matrix_deluminate();
            matrix_illuminate(row,col,player1_color);
            break;
        }
        if (player2[row][col]) {
            matrix_deluminate();
            matrix_illuminate(row,col,player2_color);
            break;
        }
    }
}




void winner_check () {
    int r, c;
    for (r=1; r < MATRIX_ROWS ;++r) {
        for (c=0; c < MATRIX_COLS ;++c) {
            int offset;
            
            //vertical
            if (r < MATRIX_ROWS-3) {
                bool win = true;
                for (offset=0; win && offset < 4 ;++offset) {
                    if (player1_turn) { if (!player1[r+offset][c]) win = false; }
                    else              { if (!player2[r+offset][c]) win = false; }
                }
                if (win) {
                    LCD_UpdateMessage("You win!");
                    bool blink = false;
                    while (true) {
                        for (offset=0; win && offset < 4 ;++offset) {
                            if (player1_turn) player1[r+offset][c] = blink;
                            else              player2[r+offset][c] = blink;
                        }
                        CyDelay(100);
                        blink = !blink;
                    }
                }
            }
            
            //lateral
            if (c < MATRIX_COLS-3) {
                bool win = true;
                for (offset=0; win && offset < 4 ;++offset) {
                    if (player1_turn) { if (!player1[r][c+offset]) win = false; }
                    else              { if (!player2[r][c+offset]) win = false; }
                }
                if (win) {
                    LCD_UpdateMessage("You win!");
                    bool blink = false;
                    while (true) {
                        for (offset=0; win && offset < 4 ;++offset) {
                            if (player1_turn) player1[r][c+offset] = blink;
                            else              player2[r][c+offset] = blink;
                        }
                        CyDelay(100);
                        blink = !blink;
                    }
                }
            }
            
            //down-diagonal
            if (r < MATRIX_ROWS-3 && c < MATRIX_COLS-3) {
                bool win = true;
                for (offset=0; win && offset < 4 ;++offset) {
                    if (player1_turn) { if (!player1[r+offset][c+offset]) win = false; }
                    else              { if (!player2[r+offset][c+offset]) win = false; }
                }
                if (win) {
                    LCD_UpdateMessage("You win!");
                    bool blink = false;
                    while (true) {
                        for (offset=0; win && offset < 4 ;++offset) {
                            if (player1_turn) player1[r+offset][c+offset] = blink;
                            else              player2[r+offset][c+offset] = blink;
                        }
                        CyDelay(100);
                        blink = !blink;
                    }
                }
            }
            
            //up-diagonal
            if (r > 3 && c < MATRIX_COLS-3) {
                bool win = true;
                for (offset=0; win && offset < 4 ;++offset) {
                    if (player1_turn) { if (!player1[r-offset][c+offset]) win = false; }
                    else              { if (!player2[r-offset][c+offset]) win = false; }
                }
                if (win) {
                    LCD_UpdateMessage("You win!");
                    bool blink = false;
                    while (true) {
                        for (offset=0; win && offset < 4 ;++offset) {
                            if (player1_turn) player1[r-offset][c+offset] = blink;
                            else              player2[r-offset][c+offset] = blink;
                        }
                        CyDelay(100);
                        blink = !blink;
                    }
                }
            }  
        }
    }
}




void send_packet ( packet_t * move ) {
    UART_WriteTxData(move->delimiter);
    UART_WriteTxData((uint8) (move->length >> 4));
    UART_WriteTxData((uint8) move->length);
    UART_WriteTxData(move->api_id);
    UART_WriteTxData(move->frame_id);
    UART_WriteTxData((uint8) (move->destination >> 4));
    UART_WriteTxData((uint8) (move->destination));
    UART_WriteTxData(move->disable_ack);
    UART_WriteTxData(move->player_id);
    UART_WriteTxData(move->packet_type);
    UART_WriteTxData(move->row);
    UART_WriteTxData(move->col);
    UART_WriteTxData(move->checksum);
}




void receive_packet ( packet_t * move ) {
    
    do { while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY)); }
    while (UART_ReadRxData() != '~');
    move->delimiter = '~';
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->length = UART_ReadRxData();
    move->length <<= 8;
    //while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->length = UART_ReadRxData(); //not quite
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->api_id = UART_ReadRxData();
    if (move->api_id != 0x01); //???
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->frame_id = UART_ReadRxData();
    if (move->frame_id != 0x00); //maybe this needs to be a sequence #?
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->destination = UART_ReadRxData();
    move->destination <<= 8;
    //while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->destination = UART_ReadRxData(); //not quite
    if (move->destination != 0xFFFF); //???
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->disable_ack = UART_ReadRxData();
    if (move->disable_ack != 0x01); //ack?
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->player_id = UART_ReadRxData();
    if (move->player_id != PLAYER2_ID); //not meant for me?
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->packet_type = UART_ReadRxData();
    if (move->packet_type != 0x00); //a later version is trying to play with this game
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->row = UART_ReadRxData();
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->col = UART_ReadRxData();
    
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
    move->checksum = UART_ReadRxData();
    if ((move->api_id +
         move->frame_id +
         move->destination +
         move->disable_ack +
         move->player_id +
         move->packet_type +
         move->row +
         move->col + 
         move->checksum) == 0xFF);//bad checksum, silently discard?
}




void main () {
    LCD_Start();
    LCD_UpdateStatus("initializing...");
    LCD_UpdateMessage("board");
    clear_board();
    LCD_UpdateMessage("matrix");
    matrix_test(true,false);
    matrix_deluminate();
    LCD_UpdateMessage("interrupts");
    row = col = -1;
    CyGlobalIntEnable;
    Beam_StartEx(refresh);
    Location_StartEx(toggle);
    LCD_UpdateMessage("timer");
    Timer_Start();
    Timer_WritePeriod(BUS_CLK_FREQ/REFRESH_RATE);
    LCD_UpdateMessage("capsense");
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    
    LCD_UpdateStatus("locate opponent");
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
    if (!player2_local) {
        LCD_UpdateStatus("initializing...");
        LCD_UpdateMessage("UART");
        UART_Start();
        UART_ClearTxBuffer();
        UART_ClearRxBuffer();
        LCD_UpdateMessage("XBee");
        configure_XBee();
    }
    
    
    LCD_UpdateStatus("Connect 4");
    while (true) {
        if (player1_turn || player2_local) {
            LCD_UpdateStatus((player1_turn) ? "Player 1" : "Player 2");
            LCD_UpdateMessage("Place a disc!");
            uint8 disc = 0;
            while (player1[1][disc] || player2[1][disc]) {
                if (++disc >= MATRIX_COLS) {
                    LCD_UpdateStatus("Game Over");
                    LCD_UpdateMessage("Board Full");
                    while (true);
                }
            }
            bool dropped = false;
            do {
                CapSense_UpdateEnabledBaselines();
                CapSense_UpdateEnabledBaselines(); //Helps avoid auto-dropping for some reason.
                CapSense_ScanEnabledWidgets();
                while (CapSense_IsBusy());
                if ((player1_turn && CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN))
                || (!player1_turn && CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN))) { //Helps avoid auto-dropping for some reason.
                    if (player1[1][disc] || player2[1][disc]) LCD_UpdateMessage("Column Full");
                    else dropped = true;
                }
                else {
                    player1[0][disc] = player2[0][disc] = false;
                    uint16 reading = (CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS)*(MATRIX_COLS-1))/97;
                    if (reading < 8) disc = reading;
                    
                    //guide the disc
                    int dir = 1;
                    while (player1[1][disc] || player2[1][disc]) {
                        if (disc >= MATRIX_COLS-1)  dir = -1;
                        if (disc == 0 && dir == -1) dir =  1; // There may be redundancy here.
                        disc += dir;
                    }
                    if (player1_turn) player1[0][disc] = true;
                    else              player2[0][disc] = true;
                }
            } while (!dropped);
            
            //animate drop
            player1[0][disc] = player2[0][disc] = false;
            uint8 r;
            for (r=1; r < MATRIX_ROWS ;++r) {
                if (player1_turn) player1[r][disc] = true;
                else              player2[r][disc] = true;
                if (player1[r+1][disc] || player2[r+1][disc] || r+1 == MATRIX_ROWS) break;
                else CyDelay(100);
                if (player1_turn) player1[r][disc] = false;
                else              player2[r][disc] = false;
            }
            if (!player2_local) {
                packet_t move;
                move.delimiter   = '~';
                move.length      = sizeof(move) - (sizeof(move.delimiter) +
                                                   sizeof(move.length) +
                                                   sizeof(move.checksum));
                move.api_id      = 0x01;
                move.frame_id    = 0x00;
                move.destination = 0xFFFF;
                move.disable_ack = 0x01;
                move.player_id   = PLAYER1_ID;
                move.packet_type = 0x00;
                move.row         = r;
                move.col         = disc;
                move.checksum    = 0xFF - (uint8) (move.api_id +
                                                   move.frame_id +
                                                   move.destination +
                                                   move.disable_ack +
                                                   move.player_id +
                                                   move.packet_type +
                                                   move.row +
                                                   move.col);
                send_packet(&move);
                
                LCD_UpdateStatus("IMPLEMENTED"); // DEBUG
                LCD_UpdateMessage("move sent"); // DEBUG
                while (true); // DEBUG
            }
            
            winner_check();
            player1_turn = !player1_turn;
        }
        else {
            LCD_UpdateMessage("Player 2");
            packet_t move;
            receive_packet(&move);
            
            LCD_UpdateStatus("UNIMPLEMENTED"); // DEBUG
            LCD_UpdateMessage("waiting for move"); // DEBUG
            while (true); // DEBUG
            
            player1_turn = true;
        }
    }
    
    if (!player2_local) {
        LCD_UpdateMessage("UART");
        UART_Stop();
    }
    LCD_UpdateMessage("capsense");
    CapSense_Stop();
    LCD_UpdateMessage("timer");
    Timer_Stop();
    LCD_UpdateMessage("interrupts");
    Location_Stop();
    Beam_Stop();
    LCD_UpdateStatus("cleaning...");
    LCD_Stop();
}
