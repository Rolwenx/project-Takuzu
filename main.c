#include <stdio.h>
#include "generate_grid.h"
#include <stdbool.h>
#include "solving_grid.h"

/*
int row_move, col_move, wanted_move, hint = 3, row_4x4 = 4, col_4x4 = 4;
bool win = false;
int solution_grid[4][4] = {1,0,0,1,
                           1,0,1,0,
                           0,1,1,0,
                           0,1,0,1};

// In this array, 0 =invisible to user and 1 = visible to user
int masK_grid[4][4] = {1,0,0,0,
                       0,0,1,0,
                       1,0,1,1,
                       0,1,0,0};

int grid_game[4][4] = {1,9,9,9,
                       9,9,1,9,
                       1,9,1,1,
                       9,1,9,9};
display_the_grid_4x4(grid_game,col_4x4, row_4x4);
while(win == false)
{
row_move = enter_row_number(row_4x4);
col_move = enter_col_number(col_4x4);
printf("You entered the following case : [%d][%d]",row_move,col_move);
wanted_move = enter_desired_move();
}
*/

int main() {
    int option = 0;

    printf("#########################################\n");
    printf("#                 MENU                  #\n");
    printf("#########################################\n");

    printf("# Enter 1 to solve a grid               #\n");
    printf("# Enter 2 to automatically solve a grid #\n");
    printf("# Enter 3 to generate a grid            #\n");
    printf("# Enter 0 to exit app                   #\n");
    printf("#########################################\n");

    printf(">>");
    scanf(" %d", &option);

    switch(option){
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        default:
            printf("default");
    }
}
