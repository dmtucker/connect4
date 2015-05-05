#define SIZE 4096
#define VERBOSE true
#define SHOW_ALL false

#include <device.h>
#include <stdbool.h>



static const uint16 POST = 2000;

uint8 outgoing[SIZE];
uint8 incoming[SIZE];
uint16 tx_cursor = SIZE;
uint16 tx_count = 0;




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
    if (VERBOSE) CyDelay(500);
}




CY_ISR (ISR_tx) {
    ++tx_count;
    //if (tx_cursor < 4096) {
        while (UART_GetTxBufferSize() > 63);
        UART_WriteTxData(outgoing[tx_cursor++]);
        if (VERBOSE && SHOW_ALL) {
            LCD_UpdateMessage("sending");
            LCD_Position(1,8);
            LCD_PrintInt8(outgoing[tx_cursor-1]);
            LCD_Position(1,12);
            LCD_PrintInt16(tx_cursor-1);
            CyDelay(1);
        }
    //}
}




void main () {
    LCD_Start();
    
    
    LCD_UpdateStatus("initializing...");
    LCD_UpdateMessage("interrupts");
    CyGlobalIntEnable;
    txISR_StartEx(ISR_tx);
    txISR_Disable();
    LCD_UpdateMessage("UART");
    UART_Start();
    UART_DisableRxInt();
    LCD_UpdateMessage("packets");
    uint16 i;
    for (i=0; i < SIZE ;++i) {
        outgoing[i] = (uint8) i;
        incoming[i] = 0;
    }
    
    
    LCD_UpdateStatus("running...");
    while (true) {
        UART_ClearTxBuffer();
        UART_ClearRxBuffer();
        uint16 errors = 0;
        tx_cursor = 0;
        tx_count = 0;
        LCD_UpdateMessage("transferring");
        txISR_Enable();
        for (i=0; i < SIZE ;++i) {
            CyDelay(1);
            //while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
            incoming[i] = UART_ReadRxData();
            if (incoming[i] != outgoing[i]) ++errors;
            if (VERBOSE && SHOW_ALL) {
                LCD_Position(0,14);
                LCD_PrintInt8((uint8) (i>>8));
                LCD_Position(1,14);
                LCD_PrintInt8(incoming[i]);
                CyDelay(1);
            }
        }
        txISR_Disable();
        LCD_UpdateMessage("transfer done");
        CyDelay(POST);
        /*
        uint16 errors = 0;
        for (i=0; i < SIZE ;++i) {
            if (incoming[i] != outgoing[i]) ++errors;
            if (VERBOSE &&false) {
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
                CyDelay(10);
            }
        }
        */
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
        
        if (SHOW_ALL ||true) {
            LCD_ClearLine(1);
            LCD_Position(1,1);
            LCD_PrintInt16(tx_count);
            LCD_Position(1,6);
            LCD_PrintString("IRQs");
            CyDelay(POST);
        }
    }
    
    
    LCD_UpdateStatus("cleaning...");
    UART_Stop();
    LCD_Stop();
}
