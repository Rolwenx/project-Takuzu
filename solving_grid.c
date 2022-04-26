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

// SO VALIDITY = 1 then move is valid, IF = 0 then move is not valid
// IF VALIDITY = 10 then move is valid but answer not correct, IF 11 then move is valid and answer correct
void solving_game_not_automatic(int size,int **game_grid, int **solution_grid,int *life)
{
    int row_move, col_move, desired_move, validity, right_answer;
    while(life != 0)
    {
        row_move = enter_row_number(size);
        col_move = enter_col_number(size);
        desired_move = enter_desired_move();
        right_answer = check_if_move_is_the_right_move(solution_grid,game_grid,row_move, col_move, desired_move);
        if(right_answer == 1)
        {
            printf("You got the right answer. Here's your new game grid.\n");
            display_grid(game_grid,size);
            solving_game_not_automatic(size,game_grid, solution_grid,*(&life));
        }
        else
        {
            *(&life) -= 1;
            printf("Wrong answer. Here's why :\n");
        }

    }
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
        printf("If you are asked the question again, that means you entered an incorrect move.\n");
        scanf("%d",&move);
    }while(move < 0 || move > 1);
    return move;
}

int rule_check_if_rows_equal(int** game_grid)
{

}
/* Thiis function will return a number that will be assigned to one of the rule of the takuzu
So that the program can know which hint to give */
int validity_of_move(int desired_move, int row, int col, int** game_grid, int** solution_grid)
{

    // In a row, there must be as many 0s as 1s

    // In a column, there must be as many 0s as 1s

    // There cannot be two identical rows in a grid


    // There cannot be two identical columns in a grid

    /* In a row or column, there cannot be more than two 0s or two 1s in a row (there cannot be three 0s or three
    1s in a row) */
}

int check_if_move_is_the_right_move(int **solution_grid,int **game_grid, int row_move, int col_move, int move)
{
    if(solution_grid[row_move][col_move] == move)
    {
        return 1;
        game_grid[row_move][col_move] = move;

    }
    else
        return 0;
}
