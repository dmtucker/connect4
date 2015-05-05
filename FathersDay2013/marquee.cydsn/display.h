#ifndef LCD_H
#define LCD_H

void LCD_ClearLine     ( uint8 line );
void LCD_UpdateStatus  ( const char string[] );
void LCD_UpdateMessage ( const char string[] );
void LCD_Spin          ( uint8 row , uint8 col , uint8 speed , uint8 count );

#endif
