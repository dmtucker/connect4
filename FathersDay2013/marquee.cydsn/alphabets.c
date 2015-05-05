#include <stdbool.h>
#include <alphabets.h>

bool equal ( uint8 x[MATRIX_ROWS][MATRIX_COLS] , uint8 y[MATRIX_ROWS][MATRIX_COLS] ) {
    bool equal = true;
    uint16 r ,c;
    for (r=0; equal && r < MATRIX_ROWS ;++r) {
        for (c=0; equal && c < MATRIX_COLS ;++c) {
            if (x[r][c] != y[r][c]) equal = false;
        }   
    }
    return equal;
}
