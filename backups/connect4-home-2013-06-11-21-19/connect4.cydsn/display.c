#include <device.h>




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




void LCD_Spin (int row, int col, int speed, int count) {
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
