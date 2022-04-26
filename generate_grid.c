//
// Created by nolwen ngassa on 4/7/22.
//

#include "generate_grid.h"

int** create_4x4_mask_grid()
{
    int rowcolsize4x4 = 4;
    srand(time(NULL));
    int**mask = (int**)malloc(sizeof(int*) * rowcolsize4x4);
    // We generate a number between 0 and 3 to select one of the 4 grids up above
    int index = rand()%4;
    // We fill a 4x4 array from one of the 4x4 grid up above in the 3D array
    for(int i = index; i < index+1; i++)
    {
        for(int j= 0; j < rowcolsize4x4; j++)
        {
            mask[j] = (int*)malloc(sizeof(int) * rowcolsize4x4);
            for(int k=0; k < rowcolsize4x4; k++)
            {
                mask[j][k] = random_4x4_mask_grid[i][j][k];
            }
        }
    }
    return mask;
}

int** create_4x4_solution_grid()
{
    int rowcolsize4x4 = 4;
    srand(time(NULL));
    int **solution = (int**)malloc(sizeof(int*) * rowcolsize4x4);

    // We generate a number between 0 and 3 to select one of the 4 grids up above
    int index = rand()%4;
    // We fill a 4x4 array from one of the 4x4 grid up above in the 3D array
    for(int i = index; i < index+1; i++)
    {
        for(int j= 0; j < rowcolsize4x4; j++)
        {
            solution[j] = (int*)malloc(sizeof(int) * rowcolsize4x4);
            for(int k=0; k < rowcolsize4x4; k++)
            {
                solution[j][k] = random_4x4_solution_grid[i][j][k];
            }
        }
    }
    return solution;
}


void display_grid(int **grid,int rowcolsize)
{
    char Letter[9] = {'A','B','C','D','E','F','G','H'};
    // We print the letters corresponding to the col
    for(int letter = 0; letter < rowcolsize;letter ++)
    {
        if(letter == 0)
            printf("%4c  ",Letter[letter]);
        if(letter != 0)
            printf("%c  ",Letter[letter]);

    }
    printf("\n");
    // we print a number of "-" adapted for the size of the grid that we want to print
    for(int symbol = 0; symbol < rowcolsize*3; symbol++)
    {
        if(symbol == 0)
            printf("  _");
        if(symbol != 0)
            printf("_");
    }
    printf("\n");
    for(int row= 0; row < rowcolsize; row++)
    {
        printf("|");
        // print each row of the grid
        for(int col=0; col < rowcolsize; col++)
        {
            printf("  %d",grid[row][col]);
        }
        printf("  |\n");
    }
    for(int symbol = 0; symbol < rowcolsize*3; symbol++)
    {
        if(symbol == 0)
            printf("  _");
        if(symbol != 0)
            printf("_");
    }
}

