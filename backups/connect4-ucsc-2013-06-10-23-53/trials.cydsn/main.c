#include <device.h>
#include <stdbool.h>

#define BUS_CLK_FREQ    24000000 // Hz
#define REFRESH_RATE    350      // Hz

uint16 count = 0;
bool testing = false;
CY_ISR (test) {
    if (testing) ++count;
}

void check () {
    uint8 t;
    for (t=5; t > 0 ;--t) {
        LCD_Position(1,0);
        LCD_PrintNumber(t);
        CyDelay(1000);
    }
}

void main () {
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("initializing...");
    CyGlobalIntEnable;
    ISR_StartEx(test);
    Timer_Start();
    
    LCD_Position(0,0);
    LCD_PrintString("testing timer...");
    testing = true;
    check();
    Timer_WritePeriod(BUS_CLK_FREQ/REFRESH_RATE);
    check();
    testing = false;
    LCD_Position(1,0);
    LCD_PrintString("done");
    LCD_Position(1,8);
    LCD_PrintNumber(count);
    
    while (true);
    Timer_Stop();
    ISR_Stop();
    LCD_Stop();
}
