//
// Created by nolwen ngassa on 4/7/22.
//

#ifndef TESTTAKUZU_SOLVING_GRID_H
#define TESTTAKUZU_SOLVING_GRID_H

#include <stdio.h>
#include <stdlib.h>

int** create_game_grid(int **mask_grid, int **solution_grid,int rowcolsize);
int enter_row_number(int row);
int enter_col_number(int col);
int enter_desired_move();


#endif //TESTTAKUZU_SOLVING_GRID_H
