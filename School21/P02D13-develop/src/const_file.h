#ifndef SRC_CONST_FILE_H_
#define SRC_CONST_FILE_H_

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#define X 80
#define Y 25
#define SYMBOL_BORD_VERT "|"
#define SYMBOL_BORD_GHOR "_"
#define LIVE_CELL "■"
#define DEAD_CELL " "
#define SYMBOL_BORD_GHOR1 "_"

int draw(int old[Y][X], int rows, int col);
int start(int old[Y][X]);
void control(int old[Y][X]);
void extra_mas(int old[Y][X], int neww[Y][X]);
void check_cell(int old[Y][X], int neww[Y][X]);
int life_cell(int neww[Y][X], int i, int j);
int death_cell(int neww[Y][X], int i, int j);
int getch();

struct Arr {
    int old[Y][X];
} arr;

#endif  // SRC_CONST_FILE_H_
