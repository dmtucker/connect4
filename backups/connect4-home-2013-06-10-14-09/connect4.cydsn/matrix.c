#include <device.h>
#include <stdbool.h>
#include <display.h>
#include <matrix.h>




void matrix_illuminate ( int row , int col , uint8 color ) {
    uint8 off = 0x00, on = 0x01;
    if (SERIAL) {
        uint8 rows = 0b00000001 << row;
        uint8 reds = 0b00000001;
        uint8 grns = 0b00000001;
        uint8 blus = 0b00000001;
        switch (color) {
            case RED:     reds <<= col;
                          grns   = off;
                          blus   = off; break;
            case GREEN:   reds   = off;
                          grns <<= col;
                          blus   = off; break;
            case YELLOW:  reds <<= col;
                          grns <<= col;
                          blus   = off; break;
            case BLUE:    reds   = off;
                          grns   = off;
                          blus <<= col; break;
            case MAGENTA: reds <<= col;
                          grns   = off;
                          blus <<= col; break;
            case CYAN:    reds   = off;
                          grns <<= col;
                          blus <<= col; break;
            case WHITE:   reds <<= col;
                          grns <<= col;
                          blus <<= col; break;
            
            default: LCD_UpdateStatus("error");
                     LCD_UpdateMessage("color mismatch");
        }
        
        rows = ~rows;
        reds = ~reds;
        grns = ~grns;
        blus = ~blus;
        
        Colors_Write(off);
        int i;
        for (i=0; i < 8 ;++i) {
            Row_Write(  (rows & (0b10000000 >> i)) ? on : off);
            Red_Write(  (reds & (0b10000000 >> i)) ? on : off);
            Green_Write((grns & (0b10000000 >> i)) ? on : off);
            Blue_Write( (blus & (0b10000000 >> i)) ? on : off);
            
            //generate a rising edge
            Column_Write(on);
            Column_Write(off);
        }
        Colors_Write(on);
    }
    else {
        uint8 r = on, c = on;
        while (row-- > 0) r *= 2;
        Row_Write(r);
        while (col-- > 0) c *= 2;
        switch (color) {
            case RED:       Red_Write(c); break;
            case GREEN:   Green_Write(c); break;
            case YELLOW:    Red_Write(c);
                          Green_Write(c); break;
            case BLUE:     Blue_Write(c); break;
            case MAGENTA:   Red_Write(c);
                           Blue_Write(c); break;
            case CYAN:    Green_Write(c);
                           Blue_Write(c); break;
            case WHITE:     Red_Write(c);
                          Green_Write(c);
                           Blue_Write(c); break;
            
            default: LCD_UpdateStatus("error");
                     LCD_UpdateMessage("color mismatch");
                     while(true);
                     break;
        }
    }
}




void matrix_deluminate () {
    uint8 off = 0x00, on = 0x01;
    if (SERIAL) {
        Colors_Write(off);
        int i;
        for (i=0; i < 8 ;++i) {
            Row_Write(0xFF);
            Red_Write(0xFF);
            Green_Write(0xFF);
            Blue_Write(0xFF);
            
            //generate a rising edge
            Column_Write(on);
            Column_Write(off);
        }
        Colors_Write(on);
    }
    else {
        Row_Write(off);
        Red_Write(off);
        Green_Write(off);
        Blue_Write(off);
    }
}




void matrix_test ( bool extended , bool slow ) {
    matrix_deluminate();
    uint8 color = 0x01;
    while (color < 0x08) {
        uint8 i, j;
        for (i=0; i < MATRIX_ROWS ;++i) {
            for (j=0; j < MATRIX_COLS ;++j) {
                LCD_ClearLine(1);
                LCD_Position(1,0);
                LCD_PrintNumber(i);
                LCD_Position(1,1);
                LCD_PutChar(',');
                LCD_Position(1,2);
                LCD_PrintNumber(j);
                LCD_Position(1,4);
                LCD_PrintString("       ");
                LCD_Position(1,4);
                switch (color) {
                    case RED:     LCD_PrintString("Red");     break;
                    case GREEN:   LCD_PrintString("Green");   break;
                    case YELLOW:  LCD_PrintString("Yellow");  break;
                    case BLUE:    LCD_PrintString("Blue");    break;
                    case MAGENTA: LCD_PrintString("Magenta"); break;
                    case CYAN:    LCD_PrintString("Cyan");    break;
                    case WHITE:   LCD_PrintString("White");   break;
                    
                    default: LCD_UpdateStatus("error");
                             LCD_UpdateMessage("color mismatch");
                             while(true);
                             break;
                }
                matrix_illuminate(i,j,color);
                CyDelay((slow) ? 1000/MATRIX_COLS : 5);
                matrix_deluminate();
            }
        }
        color = (extended) ? color+1 : color*2;
    }
}
