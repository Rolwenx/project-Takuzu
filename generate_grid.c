//
// Created by nolwen ngassa on 4/7/22.
//

#include "generate_grid.h"

// Display a 4 x 4 array
void display_the_grid_4x4(int list[4][4], int col, int row)
{
    printf("=================\n");
    for(int i = 0; i < row; i++)
    {
        printf("| ");
        for(int j = 0; j < col; j++)
        {
            printf("%d | ",list[i][j]);
        }
        printf("\n");
    }
    printf("=================\n");
}

// Display a 8 x 8 array

void display_the_grid_8x8(int list[8][8], int col, int row)
{
    printf("==================================\n");
    for(int i = 0; i < row; i++)
    {
        printf("| ");
        for(int j = 0; j < col; j++)
        {
            printf("%d | ",list[i][j]);
        }
        printf("\n");
    }
    printf("==================================\n");
}
