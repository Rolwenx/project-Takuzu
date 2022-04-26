//
// Created by nolwen ngassa on 4/7/22.
//

#include "solving_grid.h"

// Function that will create the game grid according to the mask that has been entered
int** create_game_grid(int **mask_grid, int **solution_grid,int rowcolsize)
{
    int**game_grid = (int**)malloc(sizeof(int*) * rowcolsize);
    for(int row= 0; row < rowcolsize; row++)
    {
        game_grid[row] = (int*)malloc(sizeof(int) * rowcolsize);
        for(int col=0; col < rowcolsize; col++)
        {
            if(mask_grid[row][col] == 0)
            {
                game_grid[row][col] = 7;
            }
            else
            {
                game_grid[row][col] = solution_grid[row][col];
            }
        }
    }
    return game_grid;
}








// These are the functions that are going to ask the user about his desired move
int enter_row_number(int row)
{
    int wanted;
    do
    {
        printf("Enter the row number of your wanted move :");
        printf("If you are asked the question again, that means you entered an incorrect row number\n");
        scanf("%d",&wanted);
    }while(wanted > row || wanted < 0);
    return wanted;
}

int enter_col_number(int col)
{
    int wanted;
    do
    {
        printf("Enter the col number of your wanted move :");
        printf("If you are asked the question again, that means you entered an incorrect col number\n");
        scanf("%d",&wanted);
    }while(wanted > col || wanted < 0);
    return wanted;
}
int enter_desired_move()
{
    int move;
    do
    {
        printf("Enter your desired move (either 1 or 0) :");
        printf("If you are asked the question again, that means you entered an incorrect number\n");
        scanf("%d",&move);
    }while(move < 0 || move > 1);
    return move;
}
