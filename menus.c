//
// Created by nolwen ngassa on 4/20/22.
//

#include "menus.h"
#include "solving_grid.h"

// The submenus when chosing to solve a grid

void submenus()
{
    int submenu_choice;
    int **solution_grid_4x4 = NULL, **mask_4x4_grid, **game_grid4x4;
    printf("What do you want to do now ?\n"
           "1. Enter a mask manually\n"
           "2. Automatically generate a mask\n"
           "3. Play (the mask will be generated randomly\n>>>");
    scanf(" %d",&submenu_choice);
    switch(submenu_choice)
    {
        case 1 :
        {
            break;
        }
        case 2:
        {
            mask_4x4_grid = create_4x4_mask_grid();
            display_grid(mask_4x4_grid,4);
            solution_grid_4x4 = create_4x4_solution_grid();
            printf("\n");
            display_grid(solution_grid_4x4,4);
            game_grid4x4 = create_game_grid(mask_4x4_grid, solution_grid_4x4,4);
            printf("\n");
            display_grid(game_grid4x4,4);
            break;
        }
        case 3:
        {
            mask_4x4_grid = create_4x4_mask_grid();
            display_grid(mask_4x4_grid,4);

            break;
        }
        default :
            printf("The selected choice is not among the given choices. ");
            break;
    }
}