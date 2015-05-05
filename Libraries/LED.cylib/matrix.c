#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <matrix.h>
#include <LCD.h>




void matrix_illuminate ( uint8 row , uint8 col , uint8 color ) {
    uint8 off = 0x00, on = 0x01;
    if (SERIAL) {
        uint8 rows = 0b00000001 << row;
        uint8 reds = 0b00000001;
        uint8 grns = 0b00000001;
        uint8 blus = 0b00000001;
        switch (color) {
            case OFF:     reds   = off;
                          grns   = off;
                          blus   = off; break;
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
            
            default: LCD_UpdateStatus("serial error");
                     LCD_UpdateMessage("color mismatch");
                     LCD_Position(1,14);
                     LCD_PrintInt8(color);
                     while (true);
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
            Shifter_Write(on);
            Shifter_Write(off);
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
            
            default:  LCD_UpdateStatus("parallel error");
                      LCD_UpdateMessage("color mismatch");
                      LCD_Position(1,14);
                      LCD_PrintInt8(color);
                      while (true);
            case OFF: break;
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
            Shifter_Write(on);
            Shifter_Write(off);
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




uint16 rPos = MATRIX_ROWS, cPos = MATRIX_COLS;
void matrix_refresh ( uint8 display[MATRIX_ROWS][MATRIX_COLS] ) {
    uint16 cells = MATRIX_ROWS*MATRIX_COLS;
    while (cells-- > 0) {
        if (++cPos >= MATRIX_COLS) {
            cPos = 0;
            if (++rPos >= MATRIX_ROWS) rPos = 0;
        }
        matrix_deluminate();
        if (display[rPos][cPos]) matrix_illuminate(rPos,cPos,display[rPos][cPos]);
        break;
    }
}




void matrix_marquee ( uint8 display[MATRIX_ROWS][MATRIX_COLS] , uint8 count ) {
    LCD_UpdateStatus("scrolling...");
    uint8 message[][MATRIX_ROWS][MATRIX_COLS] = MARQUEE_MESSAGE;
    bool endless = (count == 0) ? true : false;
    while (endless || count-- != 0) {
        uint8 letter, mc, dc, dr;
        for (letter=0; letter < sizeof(message)/(MATRIX_ROWS*MATRIX_COLS) ;++letter) {
            for (mc=0; mc < MATRIX_COLS ;++mc) {
                for (dc=0; dc < MATRIX_COLS ;++dc) {
                    for (dr=0; dr < MATRIX_ROWS ;++dr) {
                        display[dr][dc] = (dc < (MATRIX_COLS-1)) ?
                                          display[dr][dc+1] :
                                          message[letter][dr][mc];
                    }
                }
                if (ADC_IsEndConversion(ADC_RETURN_STATUS)) {
                    uint16 slowest = 96, fastest = 3;
                    uint16 reading = ADC_GetResult16();
                    uint16 speed   = slowest-((reading*(slowest-fastest))/0xFFFF)+(2*fastest);
                    LCD_UpdateMessage("speed:   %");
                    LCD_Position(1,7);
                    LCD_PrintNumber((reading*100)/0xFFFF);
                    CyDelay(speed);
                }
            }
        }
    }
}




void matrix_rave ( uint8 display[MATRIX_ROWS][MATRIX_COLS] {
    (void) srand (time(NULL));
    while (true) {
        int row, col;
        for (row=0; row < MATRIX_ROWS ;++row) {
            for (col=0; col < MATRIX_COLS ;++col) {
                 display[row][col] = rand()%8;
                if (ADC_IsEndConversion(ADC_RETURN_STATUS)) {
                    uint16 slowest = 50, fastest = 0;
                    uint16 reading = ADC_GetResult16();
                    uint16 speed   = slowest-((reading*(slowest-fastest))/0xFFFF)+(2*fastest);
                    LCD_UpdateMessage("speed:   %");
                    LCD_Position(1,7);
                    LCD_PrintNumber((reading*100)/0xFFFF);
                    CyDelay(speed);
                }
            }
        }
    }
}
