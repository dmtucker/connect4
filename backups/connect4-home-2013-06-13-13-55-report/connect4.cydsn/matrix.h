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

void matrix_illuminate  ( int row , int col , uint8 color );
void matrix_deluminate  ();
void matrix_test        ( bool extended , bool slow );
#endif