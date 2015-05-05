#ifndef ALPHABET_MOSAIC_H
#define ALPHABET_MOSAIC_H

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

#endif