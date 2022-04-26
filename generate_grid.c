//
// Created by nolwen ngassa on 4/7/22.
//

#include "generate_grid.h"

int** create_mask_by_user(int rowcolsize)
{
    printf("\nWe will show you one of the many solution grid in our database.\n"
           "You'll now be able to create your own mask.\nA mask just represents how the game grid will be.\n"
           "If you enter 0 when asked, the game box will be invisible in your game grid. If you enter 1, it will be visible.\n"
           "You can make visible 6 game box or less in total.\n");
    int verif = 6;
    int mask_value;
    int**mask = (int**)malloc(sizeof(int*) * rowcolsize);

    for(int row= 0; row < rowcolsize ; row++)
    {
        mask[row] = (int*)malloc(sizeof(int) * rowcolsize);
        for(int col=0; col < rowcolsize; col++)
        {
            printf("Current box : [%d][%d]\nWhat's do you want as your mask value >>",row,col);
            scanf(" %d",&mask_value);
            if(verif == 0 && mask_value == 1)
                printf("You already entered too many 1 in your mask. You can't enter another one.\n");
            if( (mask_value == 1 && verif != 0))
            {
                verif-= 1;
                mask[row][col] = 1;
            }
            if(mask_value == 0)
            {
                mask[row][col] = 0;
            }
        }
    }
    return mask;
}
int** create_4x4_mask_grid(int rowcolsize)
{
    srand(time(NULL));
    int**mask = (int**)malloc(sizeof(int*) * rowcolsize);
    // We generate a number between 0 and 3 to select one of the 4 grids up above
    int index = rand()%4;
    // We fill a 4x4 array from one of the 4x4 grid up above in the 3D array
    for(int i = index; i < index+1; i++)
    {
        for(int row= 0;row < rowcolsize; row++)
        {
            mask[row] = (int*)malloc(sizeof(int) * rowcolsize);
            for(int col=0; col < rowcolsize; col++)
            {
                mask[row][col] = random_4x4_mask_grid[i][row][col];
            }
        }
    }
    return mask;
}

int** create_4x4_solution_grid(int rowcolsize)
{
    srand(time(NULL));
    int **solution = (int**)malloc(sizeof(int*) * rowcolsize);

    // We generate a number between 0 and 3 to select one of the 4 grids up above
    int index = rand()%4;
    // We fill a 4x4 array from one of the 4x4 grid up above in the 3D array
    for(int i = index; i < index+1; i++)
    {
        for(int row= 0; row < rowcolsize; row++)
        {
            solution[row] = (int*)malloc(sizeof(int) * rowcolsize);
            for(int col=0; col < rowcolsize; col++)
            {
                solution[row][col] = random_4x4_solution_grid[i][row][col];
            }
        }
    }
    return solution;
}


void display_grid(int **grid,int rowcolsize)
{
    // char Letter[9] = {'A','B','C','D','E','F','G','H'};
    // We print the column numbers
    for(int number = 0; number < rowcolsize;number ++)
    {
        if(number == 0)
            printf("%6d  ",number);
        if(number != 0)
            printf("%d  ",number);

    }
    printf("\n");
    // we print a number of "-" adapted for the size of the grid that we want to print
    for(int symbol = 0; symbol < rowcolsize*3; symbol++)
    {
        if(symbol == 0)
            printf("    _");
        if(symbol != 0)
            printf("_");
    }
    printf("\n");
    // We print the grid
    for(int row= 0; row < rowcolsize; row++)
    {
        printf("%d |",row);
        // print each row of the grid
        for(int col=0; col < rowcolsize; col++)
        {
            printf("  %d",grid[row][col]);
        }
        printf("  |\n");
    }
    // we print a number of "-" adapted for the size of the grid that we want to print
    for(int symbol = 0; symbol < rowcolsize*3; symbol++)
    {
        if(symbol == 0)
            printf("    _");
        if(symbol != 0)
            printf("_");
    }
}

