#define SIZE 4096
#define VERBOSE false

#include <device.h>
#include <stdbool.h>




static const uint16 POST = 1000;




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
    uint8 outgoing[SIZE];
    uint8 incoming[SIZE];
    uint16 i;
    for (i=0; i < SIZE ;++i) {
        outgoing[i] = (uint8) i;
        incoming[i] = 0;
    }
    
    
    LCD_UpdateStatus("running...");
    while (true) {
        uint16 errors = 0;
        for (i=0; i < SIZE ;++i) {
            UART_WriteTxData(outgoing[i]);
            while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
            incoming[i] = UART_ReadRxData();
            if (i == 0) LCD_UpdateMessage("transferring");
            if (VERBOSE) {
                if (i == 0) {
                    LCD_Position(1,9);
                    LCD_PrintString("ed ");
                }
                LCD_Position(1,12);
                LCD_PrintInt16(i);
            }
            if (incoming[i] != outgoing[i]) {
                LCD_UpdateMessage("error");
                ++errors;
                CyDelay(POST);
                if (VERBOSE) LCD_UpdateMessage("transferred");
                else LCD_UpdateMessage("transferring");
            }
        }
        LCD_UpdateMessage("transfer done");
        CyDelay(POST);
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
    }
    
    
    LCD_UpdateStatus("cleaning...");
    UART_Stop();
    LCD_Stop();
}
