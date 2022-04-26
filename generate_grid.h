//
// Created by nolwen ngassa on 4/7/22.
//

#ifndef TESTTAKUZU_GENERATE_GRID_H
#define TESTTAKUZU_GENERATE_GRID_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "settings.h"

int** create_mask_by_user(int rowcolsize);
int** create_4x4_solution_grid(int rowcolsize);
int** create_4x4_mask_grid(int rowcolsize);
void display_grid(int **A,int rowcolsize);
#endif //TESTTAKUZU_GENERATE_GRID_H
