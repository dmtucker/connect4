#include <device.h>


void main () {
	int on=100, off=100; // ms
	while (1) {
    
		Controller_Write(0x00);
		//per-pin
        CyPins_SetPin(LED_1); // CYREG_PRT6_PC3
		CyDelay(on);
		CyPins_ClearPin(LED_1);
		CyDelay(off);
        
	    Controller_Write(0x01);
        //component
		LED_Write(0x02);
		CyDelay(on);
		LED_Write(0x00);
		CyDelay(off);
        
	}
}
