#include <device.h>


void main () {
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("initializing...");
    ISR_Start();
    ADC_Start();
    ADC_StartConvert();
    PWM_Start();
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    LCD_ClearDisplay();
    while (1) {
        
    }
}
