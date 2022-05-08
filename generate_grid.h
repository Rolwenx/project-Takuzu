//
// Created by nolwen ngassa on 4/7/22.
//

#ifndef TESTTAKUZU_GENERATE_GRID_H
#define TESTTAKUZU_GENERATE_GRID_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "settings.h"

int generate_a_decimal_number(int size);
char is_number_in_list(int size, int number, int* list);
char* generate_row(int size, int decimal_number);
void display_a_row(char *row,int size);
char** generate_a_2D_array(int size);



char** create_game_grid(char **mask_grid, char **solution_grid,int rowcolsize);
char** create_mask_by_user(int rowcolsize);
char** create_4x4_solution_grid(int rowcolsize);
char** create_4x4_mask_grid(int rowcolsize);
char** create_8x8_solution_grid(int rowcolsize);
char** create_8x8_mask_grid(int rowcolsize);
void display_grid(char **A,int rowcolsize);
#endif //TESTTAKUZU_GENERATE_GRID_H
