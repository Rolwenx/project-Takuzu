//
// Created by nolwen ngassa on 4/20/22.
//

#include "menus.h"
#include "solving_grid.h"

// The submenus when chosing to solve a grid


void submenus_firstpart(int **solution_grid, int **mask_grid, int **game_grid, int arraysize)
{
    int submenu_choice;
    printf("What do you want to do now ?\n"
           "1. Enter a mask manually\n"
           "2. Automatically generate a mask\n"
           "3. Play (the mask will be generated randomly\n>>>");
    scanf(" %d",&submenu_choice);
    switch(submenu_choice)
    {
        case 1 :
        {
            printf("----- SOLUTION GRID -----\n");
            // We choose a solution grid from the solution array in settings.c then we store it
            solution_grid = create_4x4_solution_grid(arraysize);
            display_grid(solution_grid,4);
            mask_grid = create_mask_by_user(arraysize);
            printf("\n\n----- MASK -----\n");
            display_grid(mask_grid,4);
            // We create the game grid according to the solution grid and the mask
            game_grid = create_game_grid(mask_grid, solution_grid,4);
            printf("\n\n----- GAME GRID -----\n");
            display_grid(game_grid,4);
            printf("\n");
            starter_menu();
        }
        case 2:
        {
            int win_output;
            printf("----- MASK -----\n");
            // We choose a mask grid from the mask array in settings.c then we store it
            mask_grid = create_4x4_mask_grid(arraysize);
            display_grid(mask_grid,4);
            // We choose a solution grid from the solution array in settings.c then we store it
            solution_grid = create_4x4_solution_grid(arraysize);
            // We create the game grid according to the solution grid and the mask
            game_grid = create_game_grid(mask_grid, solution_grid,4);
            printf("\n\n----- GAME GRID -----\n");
            display_grid(game_grid,4);
            printf("\n");

            if(win_output == 1)
            {
                printf("Congratulation! You won. ");
            }
            else
            {
                printf("Sory...! You lost. ");
            }
            starter_menu();
        }
        case 3:
        {
            int life = 3;
            printf("A new mask has been choosen randomly, therefore a new grid. Let the game begin\n");
            // We choose a mask grid from the mask array in settings.c then we store it
            mask_grid = create_4x4_mask_grid(arraysize);
            // We choose a solution grid from the solution array in settings.c then we store it
            solution_grid = create_4x4_solution_grid(arraysize);
            // We create the game grid according to the solution grid and the mask
            game_grid = create_game_grid(mask_grid, solution_grid,4);
            printf("\n\n----- GAME GRID -----\n");
            display_grid(game_grid,4);
            printf("\n");
            solving_game_not_automatic(arraysize,game_grid, solution_grid,&life);

            break;
        }
        default :
            printf("The selected choice is not among the given choices. ");
            break;
    }
}

void starter_menu()
{
    int option = 0;

    printf("-----------------------------------------\n");
    printf("-                 MENU                  -\n");
    printf("-----------------------------------------\n");

    printf("- Enter 1 to solve a grid               -\n");
    printf("- Enter 2 to automatically solve a grid -\n");
    printf("- Enter 3 to generate a grid            -\n");
    printf("- Enter 0 to exit app                   -\n");
    printf("-----------------------------------------\n");

    printf(">>");
    scanf(" %d", &option);

    switch(option){
        case 0:
        {
            break;
        }
        case 1:
        {
            int grid_choice;
            printf("Which size of grid do you want to play with ?\n"
                   "1. 4x4\n"
                   "2. 8x8\n>>>");
            scanf(" %d",&grid_choice);
            switch(grid_choice)
            {
                case 1:
                {
                    int **solution_grid_4x4 = NULL, **mask_4x4_grid = NULL, **game_grid4x4 = NULL;
                    submenus_firstpart(solution_grid_4x4,mask_4x4_grid,game_grid4x4,4);
                    break;
                }
                case 2 :
                {
                    int **solution_grid_8x8 = NULL, **mask_8x8_grid, **game_grid8x8;
                    break;
                }
                default:
                    printf("The selected choice is not among the given choices. ");
                    break;
            }
            break;
        }
        case 2:
        {
            printf("2");
            break;
        }
        case 3:
        {
            printf("3");
            break;
        }
        default:
            printf("Choice selected not proposed.");
    }
}