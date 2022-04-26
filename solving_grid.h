//
// Created by nolwen ngassa on 4/7/22.
//

#ifndef TESTTAKUZU_SOLVING_GRID_H
#define TESTTAKUZU_SOLVING_GRID_H

#include <stdio.h>
#include <stdlib.h>
#include "generate_grid.h"

int** create_game_grid(int **mask_grid, int **solution_grid,int rowcolsize);
int enter_row_number(int row);
int enter_col_number(int col);
int enter_desired_move();
void solving_game_not_automatic(int size,int **game_grid, int **solution_grid,int *life);
int check_if_move_is_the_right_move(int **solution_grid,int **game_grid, int row_move, int col_move, int move);


#endif //TESTTAKUZU_SOLVING_GRID_H
