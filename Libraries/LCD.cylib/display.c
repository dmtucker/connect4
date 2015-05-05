#include <LCD.h>




void LCD_ClearLine ( uint8 line ) {
    LCD_Position(line,0);
    LCD_PrintString("                ");
    LCD_Position(line,0);
}




void LCD_UpdateStatus ( const char string[] ) {
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString(string);
}




void LCD_UpdateMessage ( const char string[] ) {
    LCD_ClearLine(1);
    LCD_PrintString(string);
}




void LCD_Spin ( uint8 row , uint8 col , uint8 speed , uint8 count ) {
    while (count-- > 0) {
        LCD_Position(row,col);
        LCD_PutChar('|');
        CyDelay(speed/4);
        LCD_Position(row,col);
        LCD_PutChar('/');
        CyDelay(speed/4);
        LCD_Position(row,col);
        LCD_PutChar('-');
        CyDelay(speed/4);
        LCD_Position(row,col);
        LCD_PutChar('\\');
        CyDelay(speed/4);
    }
}
