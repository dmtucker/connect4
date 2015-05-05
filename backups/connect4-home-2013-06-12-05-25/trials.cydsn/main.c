#include <device.h>
#include <stdbool.h>

#define XBEE_GUARD_TIME 1000 // ms
#define XBEE_CHANNEL    0x0F

void configure_XBee () {
    LCD_Position(0,0);
    LCD_PrintString("                ");
    LCD_Position(0,0);
    LCD_PrintString("XBee Config");
    uint8 x, y, z;
    do {
        //do {
            TestLED_Write(0xFF);
            CyDelay(XBEE_GUARD_TIME);
            UART_PutString("+++");
            TestLED_Write(0x00);
            CyDelay(XBEE_GUARD_TIME);
        //}
        while (!(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY));
        /*
        x = UART_ReadRxData();
        y = UART_ReadRxData();
        z = UART_ReadRxData();
        LCD_Position(1,0); // DEBUG
        LCD_PutChar(x); // DEBUG
        LCD_PutChar('('); // DEBUG
        LCD_PrintInt8(x);
        LCD_PrintString(") "); // DEBUG
        LCD_PutChar(y); // DEBUG
        LCD_PutChar('('); // DEBUG
        LCD_PrintInt8(y);
        LCD_PrintString(") "); // DEBUG
        LCD_PutChar(y); // DEBUG
        LCD_PutChar('('); // DEBUG
        LCD_PrintInt8(z);
        uint8 t;
        for (t=9; t > 0 ;--t) {
            LCD_Position(0,15);
            LCD_PrintNumber(t);
            CyDelay(1000);
        }
        LCD_Position(0,15);
        LCD_PutChar(' ');
        
        */
        LCD_Position(1,0); // DEBUG
        LCD_PrintString("                ");
        uint16 k;
        for (k=UART_GetRxBufferSize(); k > 0 ;--k) {
            LCD_Position(1,0); // DEBUG
            LCD_PutChar(k); // DEBUG
            LCD_PutChar('('); // DEBUG
            LCD_PrintInt8(k);
            LCD_PutChar(')'); // DEBUG
            
            LCD_Position(0,12);
            LCD_PrintString("    "); // DEBUG
            LCD_Position(0,12);
            LCD_PrintNumber(k);
            CyDelay(2000);
        }
        LCD_Position(0,12);
        LCD_PrintString("    "); // DEBUG
        LCD_Position(1,0); // DEBUG
        LCD_PrintString("                ");
        
    }
    while (true);
    //while (x != 'O' && y != 'K' && z != '\r');
    LCD_Position(1,8); // DEBUG
    LCD_PrintString("ATAP1"); // DEBUG
    UART_PutString("ATAP1\r");
    while (UART_ReadRxData() != 'O' && UART_ReadRxData() != 'K' && UART_ReadRxData() != '\r');
    LCD_Position(1,8); // DEBUG
    LCD_PrintString("ATCH 0x0F"); // DEBUG
    UART_PutString("ATCH");
    UART_WriteTxData(XBEE_CHANNEL);
    UART_PutChar('\r');
    while (UART_ReadRxData() != 'O' && UART_ReadRxData() != 'K' && UART_ReadRxData() != '\r');
    //UART_PutString("ATWR\r");
    //while (UART_ReadRxData() != 'O' && UART_ReadRxData() != 'K' && UART_ReadRxData() != '\r');
    LCD_Position(1,8); // DEBUG
    LCD_PrintString("ATCN"); // DEBUG
    UART_PutString("ATCN\r");
    //while (UART_ReadRxData() != 'O' && UART_ReadRxData() != 'K' && UART_ReadRxData() != '\r');
    RemoteLED_Write(0x01);
}

void jordan () {
    UART_Start();
    UART_PutString("+++");
    CyDelay(3000);
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("+++ Sent");
    for (;;) {
        if (UART_GetRxBufferSize() > 0) {
            uint8 test = UART_ReadRxData();
            LCD_Position(1,0);
            LCD_PrintString("                ");
            LCD_Position(1,0);
            LCD_PrintNumber(test);
            CyDelay(4000);
        }
        else {
            LCD_Position(1,0);
            LCD_PrintString("                ");
            LCD_Position(1,0);
            LCD_PrintString("FUUUCK");
        }
            
    }
}

void main () {
    LCD_Start();
    jordan();
    LCD_Position(0,0);
    LCD_PrintString("initializing...");
    CyGlobalIntEnable;
    UART_Start();
    UART_ClearTxBuffer();
    UART_ClearRxBuffer();
    configure_XBee();
    while (true);
    UART_Stop();
    LCD_Stop();
}