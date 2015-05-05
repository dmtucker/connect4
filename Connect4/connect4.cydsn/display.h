#ifndef DISPLAY_H
#define DISPLAY_H
void LCD_ClearLine     ( int line );
void LCD_UpdateStatus  ( const char string[] );
void LCD_UpdateMessage ( const char string[] );
void LCD_Spin          ( int row , int col , int speed , int count );
#endif
