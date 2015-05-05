#define SIZE 4096
#define VERBOSE false
#define SHOW_IRQ_COUNT true

#include <device.h>
#include <stdbool.h>



static const uint16 POST = (VERBOSE || SHOW_IRQ_COUNT) ? 3000 : 1000;

uint8 outgoing[SIZE];
uint8 incoming[SIZE];
uint16 tx_cursor = SIZE;
uint16 rx_cursor = SIZE;
bool packet = false;
uint16 tx_count = 0;
uint16 rx_count = 0;




void LCD_Spin (int row, int col, int speed, int count) {
    for (; count > 0 ;--count) {
        LCD_Position(row,col);
        LCD_PutChar('|');
        CyDelay(speed*3/8);
        LCD_Position(row,col);
        LCD_PutChar('/');
        CyDelay(speed/4);
        LCD_Position(row,col);
        LCD_PutChar('-');
        CyDelay(speed*3/8);
        //LCD_Position(row,col);
        //LCD_PutChar('\\');
        //CyDelay(speed/4);
    }
}




void LCD_ClearLine (int line) {
    LCD_Position(line,0);
    LCD_PrintString("                ");
}




void LCD_UpdateStatus (const char string[]) {
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString(string);
}




void LCD_UpdateMessage (const char string[]) {
    LCD_ClearLine(1);
    LCD_Position(1,0);
    LCD_PrintString(string);
}




CY_ISR (ISR_tx) {
    ++tx_count;
    if (tx_cursor < 4096) {
        if (VERBOSE) LCD_UpdateMessage("sending");
        int i;
        for (i = 0; i < 4 && tx_cursor < SIZE ;++i) {
            UART_WriteTxData(outgoing[tx_cursor++]);
            if (VERBOSE) {
                LCD_Position(1,8);
                LCD_PrintInt8(outgoing[tx_cursor-1]);
                LCD_Position(1,12);
                LCD_PrintInt16(tx_cursor-1);
                CyDelay(100);
            }
        }
    }
}




CY_ISR (ISR_rx) {
    ++rx_count;
    if (rx_cursor < 4096) {
        if (VERBOSE) LCD_UpdateMessage("received");
        incoming[rx_cursor++] = UART_ReadRxData();
        if (rx_cursor == 4096) packet = true;
        if (VERBOSE) {
            LCD_Position(1,9);
            LCD_PrintInt8(incoming[rx_cursor-1]);
            LCD_Position(1,12);
            LCD_PrintInt16(rx_cursor-1);
            CyDelay(200);
        }
    }
}




void main () {
    LCD_Start();
    
    
    LCD_UpdateStatus("initializing...");
    LCD_UpdateMessage("UART");
    if (VERBOSE) CyDelay(500);
    UART_Start();
    UART_ClearTxBuffer();
    UART_ClearRxBuffer();
    LCD_UpdateMessage("packets");
    if (VERBOSE) CyDelay(500);
    uint16 i;
    for (i=0; i < SIZE ;++i) {
        outgoing[i] = (uint8) i;
        incoming[i] = 0;
    }
    LCD_UpdateMessage("interrupts");
    if (VERBOSE) CyDelay(500);
    CyGlobalIntEnable;
    txISR_StartEx(ISR_tx);
    rxISR_StartEx(ISR_rx);
    
    
    LCD_UpdateStatus("running...");
    while (true) {
        tx_cursor = 0;
        rx_cursor = 0;
        packet = false;
        LCD_UpdateMessage("transferring");
        ISR_tx();
        while (!packet);
        LCD_UpdateMessage("transfer done");
        CyDelay(POST);
        uint16 errors = 0;
        for (i=0; i < SIZE ;++i) {
            if (incoming[i] != outgoing[i]) ++errors;
            if (VERBOSE) {
                LCD_ClearLine(1);
                LCD_Position(1,0);
                LCD_PrintInt8(incoming[i]);
                LCD_Position(1,3);
                if (incoming[i] == outgoing[i]) LCD_PrintString("==");
                else LCD_PrintString("!=");
                LCD_Position(1,6);
                LCD_PrintInt8(incoming[i]);
                LCD_Position(1,12);
                LCD_PrintInt16(errors);
                CyDelay(100);
            }
        }
        LCD_ClearLine(1);
        LCD_Position(1,0);
        if (errors == 0) {
            LCD_PrintString("no");
            LCD_Position(1,3);
        }
        else {
            LCD_PrintInt16(errors);
            LCD_Position(1,5);
        }
        LCD_PrintString("errors");
        CyDelay(POST);
        
        if (SHOW_IRQ_COUNT) {
            LCD_ClearLine(1);
            LCD_Position(1,1);
            LCD_PrintInt16(tx_count);
            LCD_Position(1,5);
            LCD_PrintString("tx");
            LCD_Position(1,9);
            LCD_PrintInt16(rx_count);
            LCD_Position(1,13);
            LCD_PrintString("rx");
            LCD_Position(0,12);
            LCD_PrintString("IRQs");
            CyDelay(POST);
            LCD_Position(0,12);
            LCD_PrintString("    ");
            tx_count = 0;
            rx_count = 0;
        }
    }
    
    
    LCD_UpdateStatus("cleaning...");
    UART_Stop();
    LCD_Stop();
}
