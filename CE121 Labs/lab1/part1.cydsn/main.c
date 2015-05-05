#include <device.h>

void main () {
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("initializing...");
    ADC_Start();
    ADC_StartConvert();
    PWM_Start();
    LCD_ClearDisplay();
    
    LCD_Position(0,0);
    LCD_PrintString("running...");
    LCD_Position(1,0);
    LCD_PrintString("brightness: ");
    while (ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)) {
        uint16 brightness = ADC_GetResult16();
        LCD_Position(1,12);
        LCD_PrintString("  %");
        LCD_Position(1,12);
        LCD_PrintNumber((brightness*100)/0xFFFF);
        PWM_WriteCompare((brightness*999)/0xFFFF);
    }
}
