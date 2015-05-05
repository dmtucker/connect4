#include <stdbool.h>
#include <device.h>



#define SERIAL true

#define MATRIX_ROWS 8
#define MATRIX_COLS 8

#define OFF     0x00
#define RED     0x01
#define GREEN   0x02
#define YELLOW  0x03
#define BLUE    0x04
#define MAGENTA 0x05
#define CYAN    0x06
#define WHITE   0x07

#define MATRIX_MARQUEE_MESSAGE {H,A,P,P,Y,SP,F,A,T,H,E,R,S,SP,D,A,Y,SP,D,A,D,EX,SP}



#define GRN GREEN
#define YLW YELLOW
#define BLU BLUE
#define MAG MAGENTA
#define CYA CYAN
#define WHI WHITE

#define H  {{OFF,BLU,RED,OFF,OFF,RED,YLW,OFF},\
            {OFF,MAG,GRN,OFF,OFF,GRN,CYA,OFF},\
            {OFF,YLW,RED,OFF,OFF,WHI,BLU,OFF},\
            {OFF,CYA,BLU,WHI,GRN,MAG,RED,OFF},\
            {OFF,GRN,WHI,YLW,RED,CYA,GRN,OFF},\
            {OFF,RED,MAG,OFF,OFF,BLU,RED,OFF},\
            {OFF,BLU,GRN,OFF,OFF,YLW,GRN,OFF},\
            {OFF,CYA,YLW,OFF,OFF,WHI,MAG,OFF}}

#define A  {{OFF,OFF,WHI,RED,GRN,BLU,OFF,OFF},\
            {OFF,YLW,CYA,GRN,MAG,CYA,GRN,OFF},\
            {OFF,GRN,BLU,OFF,OFF,YLW,RED,OFF},\
            {OFF,MAG,GRN,OFF,OFF,GRN,MAG,OFF},\
            {OFF,BLU,RED,MAG,YLW,WHI,CYA,OFF},\
            {OFF,WHI,GRN,CYA,BLU,RED,GRN,OFF},\
            {OFF,CYA,YLW,OFF,OFF,WHI,YLW,OFF},\
            {OFF,RED,WHI,OFF,OFF,MAG,BLU,OFF}}

#define P  {{OFF,CYA,GRN,WHI,BLU,CYA,OFF,OFF},\
            {OFF,RED,BLU,CYA,YLW,MAG,BLU,OFF},\
            {OFF,YLW,MAG,OFF,OFF,GRN,RED,OFF},\
            {OFF,WHI,BLU,OFF,OFF,CYA,BLU,OFF},\
            {OFF,MAG,RED,GRN,WHI,YLW,WHI,OFF},\
            {OFF,YLW,BLU,MAG,RED,BLU,OFF,OFF},\
            {OFF,CYA,GRN,OFF,OFF,OFF,OFF,OFF},\
            {OFF,RED,BLU,OFF,OFF,OFF,OFF,OFF}}

#define Y  {{OFF,RED,CYA,OFF,OFF,YLW,MAG,OFF},\
            {OFF,BLU,MAG,OFF,OFF,BLU,RED,OFF},\
            {OFF,YLW,GRN,OFF,OFF,WHI,YLW,OFF},\
            {OFF,RED,CYA,WHI,YLW,MAG,RED,OFF},\
            {OFF,OFF,BLU,RED,MAG,WHI,OFF,OFF},\
            {OFF,OFF,OFF,GRN,BLU,OFF,OFF,OFF},\
            {OFF,OFF,OFF,YLW,RED,OFF,OFF,OFF},\
            {OFF,OFF,OFF,MAG,CYA,OFF,OFF,OFF}}

#define SP {{OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF},\
            {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF},\
            {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF},\
            {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF},\
            {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF},\
            {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF},\
            {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF},\
            {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF}}

#define F  {{OFF,RED,BLU,GRN,CYA,RED,MAG,OFF},\
            {OFF,MAG,YLW,MAG,GRN,WHI,BLU,OFF},\
            {OFF,BLU,RED,OFF,OFF,OFF,OFF,OFF},\
            {OFF,GRN,WHI,OFF,OFF,OFF,OFF,OFF},\
            {OFF,RED,CYA,GRN,MAG,CYA,YLW,OFF},\
            {OFF,GRN,MAG,RED,WHI,BLU,WHI,OFF},\
            {OFF,BLU,YLW,OFF,OFF,OFF,OFF,OFF},\
            {OFF,CYA,RED,OFF,OFF,OFF,OFF,OFF}}

#define T  {{OFF,WHI,BLU,MAG,YLW,MAG,GRN,OFF},\
            {OFF,MAG,RED,GRN,BLU,WHI,CYA,OFF},\
            {OFF,OFF,OFF,CYA,YLW,OFF,OFF,OFF},\
            {OFF,OFF,OFF,MAG,RED,OFF,OFF,OFF},\
            {OFF,OFF,OFF,WHI,BLU,OFF,OFF,OFF},\
            {OFF,OFF,OFF,GRN,MAG,OFF,OFF,OFF},\
            {OFF,OFF,OFF,RED,CYA,OFF,OFF,OFF},\
            {OFF,OFF,OFF,YLW,WHI,OFF,OFF,OFF}}

#define E  {{OFF,CYA,YLW,WHI,BLU,MAG,CYA,OFF},\
            {OFF,RED,BLU,MAG,GRN,WHI,RED,OFF},\
            {OFF,WHI,RED,OFF,OFF,OFF,OFF,OFF},\
            {OFF,BLU,MAG,CYA,RED,GRN,CYA,OFF},\
            {OFF,GRN,RED,YLW,BLU,RED,MAG,OFF},\
            {OFF,MAG,WHI,OFF,OFF,OFF,OFF,OFF},\
            {OFF,CYA,YLW,MAG,CYA,GRN,YLW,OFF},\
            {OFF,RED,BLU,GRN,RED,BLU,WHI,OFF}}

#define R  {{OFF,YLW,MAG,GRN,WHI,CYA,OFF,OFF},\
            {OFF,GRN,WHI,CYA,MAG,BLU,GRN,OFF},\
            {OFF,MAG,GRN,OFF,OFF,WHI,MAG,OFF},\
            {OFF,YLW,RED,OFF,OFF,RED,BLU,OFF},\
            {OFF,CYA,GRN,WHI,YLW,GRN,OFF,OFF},\
            {OFF,RED,BLU,MAG,BLU,WHI,YLW,OFF},\
            {OFF,GRN,WHI,OFF,OFF,CYA,MAG,OFF},\
            {OFF,MAG,RED,OFF,OFF,RED,GRN,OFF}}

#define S  {{OFF,OFF,YLW,BLU,WHI,RED,GRN,OFF},\
            {OFF,WHI,MAG,RED,YLW,BLU,WHI,OFF},\
            {OFF,GRN,BLU,OFF,OFF,OFF,OFF,OFF},\
            {OFF,RED,WHI,BLU,WHI,CYA,OFF,OFF},\
            {OFF,OFF,MAG,GRN,RED,YLW,BLU,OFF},\
            {OFF,OFF,OFF,OFF,OFF,MAG,RED,OFF},\
            {OFF,GRN,RED,MAG,YLW,WHI,GRN,OFF},\
            {OFF,YLW,CYA,WHI,BLU,RED,OFF,OFF}}

#define D  {{OFF,WHI,GRN,RED,CYA,OFF,OFF,OFF},\
            {OFF,MAG,RED,YLW,MAG,BLU,OFF,OFF},\
            {OFF,CYA,BLU,OFF,WHI,GRN,RED,OFF},\
            {OFF,WHI,GRN,OFF,OFF,CYA,YLW,OFF},\
            {OFF,MAG,RED,OFF,OFF,WHI,MAG,OFF},\
            {OFF,RED,YLW,OFF,CYA,GRN,RED,OFF},\
            {OFF,CYA,MAG,WHI,YLW,BLU,OFF,OFF},\
            {OFF,BLU,RED,GRN,RED,OFF,OFF,OFF}}

#define EX {{OFF,YLW,YLW,OFF,OFF,CYA,CYA,OFF},\
            {OFF,BLU,BLU,OFF,OFF,YLW,YLW,OFF},\
            {OFF,MAG,MAG,OFF,OFF,BLU,BLU,OFF},\
            {OFF,WHI,WHI,OFF,OFF,RED,RED,OFF},\
            {OFF,RED,RED,OFF,OFF,GRN,GRN,OFF},\
            {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF},\
            {OFF,CYA,CYA,OFF,OFF,WHI,WHI,OFF},\
            {OFF,GRN,GRN,OFF,OFF,MAG,MAG,OFF}}







void matrix_illuminate  ( uint8 row , uint8 col , uint8 color );
void matrix_deluminate  ();
void matrix_test        ( bool extended , bool slow );
void matrix_refresh     ( uint8 display[MATRIX_ROWS][MATRIX_COLS] );
void matrix_marquee     ( uint8 display[MATRIX_ROWS][MATRIX_COLS] , uint8 count );
void matrix_rave        ( uint8 display[MATRIX_ROWS][MATRIX_COLS] );




void LCD_ClearLine     ( uint8 line );
void LCD_UpdateStatus  ( const char string[] );
void LCD_UpdateMessage ( const char string[] );
void LCD_Spin          ( uint8 row , uint8 col , uint8 speed , uint8 count );







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
    uint8 message[][MATRIX_ROWS][MATRIX_COLS] = MATRIX_MARQUEE_MESSAGE;
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






void matrix_rave ( uint8 display[MATRIX_ROWS][MATRIX_COLS] ) {
    LCD_UpdateStatus("raving...");
    (void) srand (time(NULL));
    while (true) {
        uint8 row = rand()%MATRIX_ROWS;
        uint8 col = rand()%MATRIX_COLS;
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








#define BUS_CLK_FREQ    24000000 // Hz
#define REFRESH_RATE          60 // [6,375k] Hz

void initialize    ( );
void clear_display ( );
void cleanup       ( );

uint8 display[MATRIX_ROWS][MATRIX_COLS] = {{0}};
CY_ISR (refresh) { matrix_refresh(display); }

void main () {
    initialize();
    //matrix_marquee(display,0);
    matrix_rave(display);
    cleanup();
}

void initialize () {
    LCD_Start();
    LCD_UpdateStatus("initializing...");
    LCD_UpdateMessage("marquee");
    clear_display();
    LCD_UpdateMessage("interrupts");
    CyGlobalIntEnable;
    Beam_StartEx(refresh);
    LCD_UpdateMessage("timer");
    Timer_Start();
    Timer_WritePeriod(BUS_CLK_FREQ/(REFRESH_RATE*MATRIX_ROWS*MATRIX_COLS));
    LCD_UpdateMessage("ADC");
    ADC_Start();
    ADC_StartConvert();
}

void clear_display () {
    uint8 r, c;
    for (r=0 ; r < MATRIX_ROWS ;++r) {
        for (c=0; c < MATRIX_COLS ;++c) {
            display[r][c] = OFF;
        }
    }
}

void cleanup () {
    LCD_UpdateStatus("cleaning...");
    LCD_UpdateMessage("ADC");
    ADC_Stop();
    LCD_UpdateMessage("timer");
    Timer_Stop();
    LCD_UpdateMessage("interrupts");
    Beam_Stop();
    LCD_UpdateMessage("marquee");
    clear_display();
    LCD_Stop();
}
