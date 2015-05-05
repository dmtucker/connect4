#include <stdbool.h>

#ifndef MATRIX_H
#define MATRIX_H

#define SERIAL true

#define MATRIX_ROWS 8
#define MATRIX_COLS 8

#define RED     0x01
#define GREEN   0x02
#define YELLOW  0x03
#define BLUE    0x04
#define MAGENTA 0x05
#define CYAN    0x06
#define WHITE   0x07

#include <alphabet-mosaic.h>
#define MATRIX_MARQUEE_MESSAGE {H,A,P,P,Y,SP,F,A,T,H,E,R,S,SP,D,A,Y,SP,D,A,D,EX,SP}

void matrix_illuminate  ( uint8 row , uint8 col , uint8 color );
void matrix_deluminate  ();
void matrix_test        ( bool extended , bool slow );
void matrix_refresh     ( uint8 display[MATRIX_ROWS][MATRIX_COLS] );
void matrix_marquee     ( uint8 display[MATRIX_ROWS][MATRIX_COLS] , uint8 count );

#endif
