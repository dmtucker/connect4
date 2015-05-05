#include <device.h>
#include <stdbool.h>
#include <display.h>
#include <PID.h>

#define SLOWEST  5000
#define FASTEST 22000




CY_ISR (toggle) {
    Indicator_Write((PID_toggle() == AUTOMATIC) ? 0x01 : 0x00);
}

CY_ISR (sample) {
    PID_controller();
    if (PID_mode() == AUTOMATIC) PWM_WriteCompare((uint16) (PID_output()-SLOWEST)*PWM_ReadPeriod()/(FASTEST-SLOWEST));
}




void main () {
    LCD_Start();
    LCD_UpdateStatus("initializing...");
    LCD_UpdateMessage("Clock");
    Clock_Start();
    LCD_UpdateMessage("ADC");
    ADC_Start();
    ADC_StartConvert();
    LCD_UpdateMessage("PWM");
    PWM_Start();
    LCD_UpdateMessage("Counter");
    Counter_Start();
    LCD_UpdateMessage("Timer");
    Timer_Start();
    LCD_UpdateMessage("PID");
    set_PID_tunings(0.24,0.12,0.06); //P oscillates at 0.5 = Ku
    set_PID_limits(SLOWEST,FASTEST);
    LCD_UpdateMessage("Interrupts");
    CyGlobalIntEnable;
    Sample_StartEx(sample);
    Mode_StartEx(toggle);
    
    
    LCD_UpdateStatus("  RPM:");
    LCD_Position(1,14);
    LCD_PrintInt8(PWM_ReadPeriod());
    while (ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)) {
        uint16 speed = ADC_GetResult16();
        uint16 rpm   = Counter_ReadCapture()*60/2;
        if (PID_mode() == MANUAL) {
            LCD_Position(1,0);
            LCD_PrintString("speed:   %  ");
            LCD_Position(1,7);
            LCD_PrintNumber(speed*100/65535);
            PWM_WriteCompare(speed*PWM_ReadPeriod()/65535);
        }
        else {
            uint16 setpoint = (speed*(FASTEST-SLOWEST)/65535)+SLOWEST;
            LCD_Position(1,0);
            LCD_PrintString("setPt:      ");
            LCD_Position(1,7);
            LCD_PrintNumber(setpoint);
            set_PID_input((double) rpm);
            set_PID_setpoint((double) setpoint);
        }
        LCD_Position(0,7);
        LCD_PrintString("     ");
        LCD_Position(0,7);
        LCD_PrintNumber(rpm);
        LCD_Position(0,14);
        LCD_PrintInt8(PWM_ReadCounter());
    }
    
    
    LCD_UpdateStatus("cleaning...");
    LCD_UpdateMessage("Interrupts");
    Mode_Stop();
    Sample_Stop();
    LCD_UpdateMessage("Timer");
    Timer_Stop();
    LCD_UpdateMessage("Counter");
    Counter_Stop();
    LCD_UpdateMessage("PWM");
    PWM_Stop();
    LCD_UpdateMessage("ADC");
    ADC_Stop();
    LCD_UpdateMessage("Clock");
    Clock_Stop();
}
