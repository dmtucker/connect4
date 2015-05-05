#define DURATION 3 //seconds
#define TRIALS   1 //[0,9]

#define GO   0x04
#define IDLE 0x00
#define REV  0x01
#define STOP 0x02

#include <device.h>
#include <stdbool.h>
#include <display.h>


uint16 gear = STOP;




char gear_label (uint16 gear) {
    switch (gear) {
        case STOP: return 'P';
        case REV:  return 'R';
        case IDLE: return 'N';
        case GO:   return 'D';
        default:   return '?';
    }
}




void shift_gear (uint16 next) {
    Controller_Write(IDLE); //clutch
    gear = next;
    Controller_Write(gear);
}




void test_motor (trials, duration) {
    uint16 triali, geari = 0x00;
	for (triali = trials*4; triali > 0 ;--triali) {
        switch (geari) {
            case IDLE:
                LCD_UpdateMessage("idle");
        		Controller_Write(IDLE);
                break;
            case GO:
                LCD_UpdateMessage("forward");
        		Controller_Write(GO);
                break;
            case REV:
                LCD_UpdateMessage("reverse");
        		Controller_Write(REV);
                break;
            case STOP:
                LCD_UpdateMessage("stop");
        		Controller_Write(STOP);
                break;
            default:
                LCD_UpdateStatus("stopped");
                LCD_UpdateMessage("error");
        		Controller_Write(IDLE);
                while (true);
        }
        
        uint16 i;
        for (i=0; i < duration ;++i) {
            LCD_Position(1,15);
            LCD_PrintNumber(duration-i);
		    CyDelay(1000);
        }
        
        if (geari == 0x00) geari = 0x01;
        else geari *= (geari == 0x04) ? 0 : 2;
	}
}




CY_ISR (transmission) {
    shift_gear((gear == GO) ? REV : GO);
    ISR_ClearPending();
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
    LCD_UpdateMessage("Motor");
    test_motor(TRIALS, DURATION);
    LCD_UpdateMessage("Interrupts");
    CyGlobalIntEnable;
    ISR_StartEx(transmission);
    
    
    shift_gear(GO);
    LCD_UpdateStatus(" gear:");
    LCD_UpdateMessage("speed:");
    LCD_Position(1,12);
    LCD_PrintInt16(PWM_ReadPeriod());
    while (ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)) {
        uint16 speed = ADC_GetResult16();
        LCD_Position(1,8);
        LCD_PrintString(" %");
        LCD_Position(1,7);
        LCD_PrintNumber(speed*100/65535);
        PWM_WriteCompare(speed*PWM_ReadPeriod()/65535);
        LCD_Position(0,7);
        LCD_PutChar(gear_label(gear));
        LCD_Position(0,12);
        LCD_PrintInt16(PWM_ReadCounter());
    }
    
    
    LCD_UpdateStatus("cleaning...");
    LCD_UpdateMessage("Interrupts");
    ISR_Stop();
    LCD_UpdateMessage("PWM");
    PWM_Stop();
    LCD_UpdateMessage("ADC");
    ADC_Stop();
    LCD_UpdateMessage("Clock");
    Clock_Stop();
}
