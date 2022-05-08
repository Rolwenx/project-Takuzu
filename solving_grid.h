//
// Created by nolwen ngassa on 4/7/22.
//

#ifndef TESTTAKUZU_SOLVING_GRID_H
#define TESTTAKUZU_SOLVING_GRID_H

#include <stdio.h>
#include <stdlib.h>
#include "generate_grid.h"
#include <stdbool.h>
#include "validity_functions.h"
#include <unistd.h>


void solving_game_automatic(int size,char **game_grid, char **solution_grid);
char compareArray(char **game_grid, char **solution_grid,int size);
void solving_game_not_automatic(int size,char **game_grid, char **solution_grid,int *life);

int enter_row_number(int row);
int enter_col_number(int col);
int enter_desired_move();


char validity_of_move_If_Row_Complete(int row_move,char** game_grid, int size);
char validity_of_move_If_Col_Complete( int col_move, char** game_grid,int size);

char Check_if_row_or_col_complete(char** game_grid, int rowcolsize, int row_or_col_move, char row_or_col);
char check_if_move_is_the_right_move(char **solution_grid,char **game_grid, int row_move, int col_move, int move, int rowcolsize);

#endif //TESTTAKUZU_SOLVING_GRID_H
