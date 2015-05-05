#include <device.h>
#include <stdbool.h>
#include <display.h>
#include <matrix.h>

#define BUS_CLK_FREQ    24000000 // Hz
#define REFRESH_RATE    2500     // [370,BUS_CLK_FREQ] Hz
#define XBEE_GUARD_TIME 1000     // ms
#define XBEE_CHANNEL    0x0F
#define PLAYER1_ID      0xDA
#define PLAYER2_ID      0x07

bool  player1[MATRIX_ROWS][MATRIX_COLS];
bool  player2[MATRIX_ROWS][MATRIX_COLS];
uint8 player1_color = RED;
uint8 player2_color = BLUE;
bool  player1_turn  = true;
bool  player2_local = true;

/* remote play */
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




bool locating = false;
CY_ISR (toggle) { if (locating) player2_local = !player2_local; }




void configure_XBee () {    
    CyDelay(XBEE_GUARD_TIME);
    UART_PutString("+++");
    //UART_PutChar('+');UART_PutChar('+');UART_PutChar('+');
    CyDelay(XBEE_GUARD_TIME*3);
    uint8 d, result; // DEBUG
    while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY) && UART_GetRxBufferSize() < 3) {
        switch (d++%3) {
            case 0: LCD_Position(1,13); LCD_PrintString("   "); LCD_Position(1,13);
            default: LCD_PutChar('.'); break;
        }
    }
    if (UART_ReadRxData() != 'O' || UART_ReadRxData() != 'K' || UART_ReadRxData() != '\r') {
        LED_Write(0x01);
        result += 1;
    }
    
    UART_PutString("ATAP1\r");
    if (UART_ReadRxData() != 'O' || UART_ReadRxData() != 'K' || UART_ReadRxData() != '\r') LED_Write(0x01);
    
    UART_PutString("ATCH");
    UART_WriteTxData(XBEE_CHANNEL);
    UART_PutChar('\r');
    if (UART_ReadRxData() != 'O' || UART_ReadRxData() != 'K' || UART_ReadRxData() != '\r') LED_Write(0x01);
    
    //UART_PutString("ATWR\r");
    //if (UART_ReadRxData() != 'O' || UART_ReadRxData() != 'K' || UART_ReadRxData() != '\r') LED_Write(0x01);
    
    UART_PutString("ATCN\r");
    if (UART_ReadRxData() != 'O' || UART_ReadRxData() != 'K' || UART_ReadRxData() != '\r') LED_Write(0x01);
    
    Remote_Write(0x01);
}




void show_packet (packet_t * move) {
    uint16 delay = 1000;
    
    LCD_UpdateStatus("Delimiter");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PutChar(move->delimiter);
    LCD_Position(1,2);
    LCD_PrintNumber(move->delimiter);
    CyDelay(delay);
    
    LCD_UpdateStatus("Length");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintNumber(move->length);
    CyDelay(delay);
    
    LCD_UpdateStatus("API ID");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->api_id);
    CyDelay(delay);
    
    LCD_UpdateStatus("Frame ID");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->frame_id);
    CyDelay(delay);
    
    LCD_UpdateStatus("Destination");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintString("0x");
    LCD_PrintInt16(move->destination);
    CyDelay(delay);
    
    LCD_UpdateStatus("Disable ACK");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->disable_ack);
    CyDelay(delay);
    
    LCD_UpdateStatus("Player ID");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->player_id);
    CyDelay(delay);
    
    LCD_UpdateStatus("Packet Type");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->packet_type);
    CyDelay(delay);
    
    LCD_UpdateStatus("Row");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintNumber(move->row);
    CyDelay(delay);
    
    LCD_UpdateStatus("Column");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintNumber(move->col);
    CyDelay(delay);
    
    LCD_UpdateStatus("Checksum");
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintString("0x");
    LCD_PrintInt8(move->checksum);
    CyDelay(delay);
}




void send_packet ( packet_t * move ) {
    UART_ClearTxBuffer();
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
    while (true) {
        UART_ClearRxBuffer();
        LCD_UpdateMessage("waiting"); // DEBUG
        while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
        LCD_UpdateMessage("received"); // DEBUG
        CyDelay(500); // DEBUG?
        
        LCD_Position(1,12); // DEBUG
        uint16 tst = UART_GetRxBufferSize(); // DEBUG
        LCD_PrintNumber(tst); // DEBUG
        CyDelay(2000); // DEBUG
        
        /* DEBUG */
        uint16 tmp;
        for (tmp=tst; tmp > 0 ;--tmp) {
            LCD_ClearLine(1);
            LCD_Position(1,0);
            LCD_PrintNumber(UART_GetChar());
            LCD_Position(1,12);
            LCD_PrintInt16(tst-tmp);
            CyDelay(1000);
        }
        /**/
        
        //if (tst != 13) continue; // DEBUG
        //if (UART_GetRxBufferSize() != 13) continue;
        
        move->delimiter = UART_ReadRxData();
        if (move->delimiter != '~') continue;
        
        LCD_UpdateMessage("~"); // DEBUG
        CyDelay(500); // DEBUG
        
        move->length   = UART_ReadRxData();
        move->length <<= 8;
        move->length  |= UART_ReadRxData();
        
        LCD_ClearLine(1); // DEBUG
        LCD_Position(1,0); // DEBUG
        LCD_PrintNumber(move->length); // DEBUG
        CyDelay(500); // DEBUG
        
        move->api_id = UART_ReadRxData();
        if (move->api_id != 0x01); //means what???
        
        move->frame_id = UART_ReadRxData();
        if (move->frame_id != 0x00); //maybe this needs to be a sequence #?
        
        move->destination   = UART_ReadRxData();
        move->destination <<= 8;
        move->destination  |= UART_ReadRxData();
        if (move->destination != 0xFFFF); //means what???
        
        move->disable_ack = UART_ReadRxData();
        if (move->disable_ack != 0x01); //ack?
        
        move->player_id = UART_ReadRxData();
        if (move->player_id != PLAYER2_ID) continue;
        
        move->packet_type = UART_ReadRxData();
        if (move->packet_type != 0x00); //a later version is trying to play with this game
        
        move->row = UART_ReadRxData();
        if (move->row < 1 || move->row > MATRIX_ROWS-1) continue;
        
        move->col = UART_ReadRxData();
        if (move->col < 1 || move->row > MATRIX_COLS) continue;
        
        move->checksum = UART_ReadRxData();
        if ((move->api_id +
             move->frame_id +
             move->destination +
             move->disable_ack +
             move->player_id +
             move->packet_type +
             move->row +
             move->col + 
             move->checksum) != 0xFF); //bad checksum, silently discard?
        else break;
    }
}
/**/




void clear_board () {
    uint8 r, c;
    for (r=0; r < MATRIX_ROWS ;++r) {
        for (c=0; c < MATRIX_COLS ;++c) {
            player1[r][c] = false;
            player2[r][c] = false;
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




uint8 row = -1, col = -1;
CY_ISR (refresh) {
    if (false) {//if (SERIAL) {
        matrix_deluminate();
        if (++col > MATRIX_ROWS) col = 0;
        for (row=0; row < MATRIX_COLS ;++row) {
            if (player1[row][col]) matrix_illuminate(row,col,player1_color);
            if (player2[row][col]) matrix_illuminate(row,col,player2_color);
        }
    }
    else {
        uint16 cells = MATRIX_ROWS*MATRIX_COLS;
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
    CyGlobalIntEnable;
    LCD_UpdateMessage("timer");
    Timer_Start();
    Timer_WritePeriod(BUS_CLK_FREQ/REFRESH_RATE);
    LCD_UpdateMessage("capsense");
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
        configure_XBee();
    }
    
    
    LCD_UpdateStatus("Connect 4");
    Beam_StartEx(refresh);
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
                else CyDelay(10);
                if (player1_turn) player1[r][disc] = false;
                else              player2[r][disc] = false;
            }
            if (!player2_local) {
                packet_t move;
                move.delimiter   = '~';
                move.length      = 0x0009;/*sizeof(move) - (sizeof(move.delimiter) +
                                                   sizeof(move.length) +
                                                   sizeof(move.checksum));*/
                move.api_id      = 0x01;
                move.frame_id    = 0x00;
                move.destination = 0xFFFF;
                move.disable_ack = 0x01;
                move.player_id   = PLAYER1_ID;
                move.packet_type = 0x00;
                move.row         = MATRIX_ROWS-r;
                move.col         = disc+1;
                move.checksum    = 0xFF - (uint8) (move.api_id +
                                                   move.frame_id +
                                                  (move.destination >> 8) +
                                                  ((uint8) move.destination) +
                                                   move.disable_ack +
                                                   move.player_id +
                                                   move.packet_type +
                                                   move.row +
                                                   move.col);
                send_packet(&move);
            }
            
            winner_check();
            player1_turn = !player1_turn;
        }
        else {
            LCD_UpdateStatus("Player 2");
            LCD_UpdateMessage("waiting...");
            packet_t move;
            receive_packet(&move);
            player2[MATRIX_ROWS-move.row][move.col-1] = true;
            winner_check();
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
    Beam_Stop();
    LCD_UpdateStatus("cleaning...");
    LCD_Stop();
}
