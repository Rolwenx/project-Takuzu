//
// Created by nolwen ngassa on 4/20/22.
//

#include "menus.h"
#include "solving_grid.h"

// The submenus when chosing to solve a grid


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
            FirstChoice_Submenu_One();
        }
        case 2:
        {
            SecondChoice_Submenu_One();
        }
        case 3:
        {
            ThirdChoice_Submenu_One();
        }
        default:
        {
            printf("Choice selected not proposed.\n");
            starter_menu();
        }
    }
}

void FirstChoice_Submenu_One() {
    int grid_choice;
    printf("Which size of grid do you want to play with ?\n"
           "1. Enter 1 for a 4x4 grid\n"
           "2. Enter 2 for a 8x8 grid\n"
           "3. Enter 3 to return to starter menu\n>>>");
    scanf(" %d",&grid_choice);
    switch(grid_choice)
    {
        case 1:
        {
            char **solution_grid_4x4, **mask_4x4_grid, **game_grid4x4 = NULL;
            int size = 4;
            // We choose a mask grid from the mask array in settings.c then we store it
            mask_4x4_grid = create_4x4_mask_grid(size);
            // We choose a solution grid from the solution array in settings.c then we store it
            solution_grid_4x4 = create_4x4_solution_grid(size);
            FirstChoice_Submenu_Two(solution_grid_4x4, mask_4x4_grid, game_grid4x4, size);
            break;
        }
        case 2 :
        {
            char **solution_grid_8x8, **mask_8x8_grid, **game_grid8x8 = NULL;
            int size =8;
            // We choose a mask grid from the mask array in settings.c then we store it
            mask_8x8_grid = create_8x8_mask_grid(size);
            // We choose a solution grid from the solution array in settings.c then we store it
            solution_grid_8x8 = create_8x8_solution_grid(size);
            FirstChoice_Submenu_Two(solution_grid_8x8, mask_8x8_grid, game_grid8x8, size);
            break;
        }
        case 3:
        {
            starter_menu();
        }
        default:
        {
            printf("Choice selected not proposed.\n");
            starter_menu();
        }
    }
}


void FirstChoice_Submenu_Two(char **solution_grid, char **mask_grid, char **game_grid, int rowcolsize) {
    int submenu_choice;
    printf("What do you want to do now ?\n"
           "1. Enter 1 to fill a mask manually\n"
           "2. Enter 2 to automatically generate a mask\n"
           "3. Enter 3 to play (the mask will be generated randomly)\n"
           "4. Enter 4 to return to previous menu.\n"
           "5. Enter 5 to return to starter menu\n>>>");
    scanf(" %d", &submenu_choice);
    switch (submenu_choice) {
        case 1 : {
            printf("----- SOLUTION GRID -----\n");
            display_grid(solution_grid, rowcolsize);
            // We call the function that allows the user to manually enter their grid
            mask_grid = create_mask_by_user(rowcolsize);
            printf("\n\n----- SOLUTION GRID -----\n");
            display_grid(solution_grid, rowcolsize);
            printf("\n\n----- MASK -----\n");
            display_grid(mask_grid, rowcolsize);
            // We create the game grid according to the solution grid and the mask
            game_grid = create_game_grid(mask_grid, solution_grid, rowcolsize);
            printf("\n\n----- GAME GRID -----\n");
            display_grid(game_grid, rowcolsize);
            printf("\n");
            starter_menu();
        }
        case 2: {
            printf("----- MASK -----\n");
            display_grid(mask_grid, rowcolsize);
            // We create the game grid according to the solution grid and the mask
            game_grid = create_game_grid(mask_grid, solution_grid, rowcolsize);
            printf("\n\n----- GAME GRID -----\n");
            display_grid(game_grid, rowcolsize);
            printf("\n");
            starter_menu();

            case 3: {
                int life = 3;
                printf("A new mask has been choosen randomly, therefore a new grid. Let the game begin\n");
                // We create the game grid according to the solution grid and the mask
                game_grid = create_game_grid(mask_grid, solution_grid, rowcolsize);
                solving_game_not_automatic(rowcolsize, game_grid, solution_grid, &life);
                starter_menu();
            }
            case 4 :
            {
                FirstChoice_Submenu_One();
            }
            case 5 :
            {
                starter_menu();
            }
            default :
            {
                printf("Choice selected not proposed.\n");
                starter_menu();
            }
        }
    }
}

void SecondChoice_Submenu_One() {
    int grid_choice;
    printf("Which size of grid do you want to automatically solve ?\n"
           "1. Enter 1 for a 4x4 grid\n"
           "2. Enter 2 for a 8x8 grid\n"
           "3. Enter 3 to return to starter menu\n>>>");
    scanf(" %d",&grid_choice);
    switch(grid_choice)
    {
        case 1:
        {
            char **solution_grid_4x4, **mask_4x4_grid, **game_grid4x4 = NULL;
            int size= 4;
            // We choose a mask grid from the mask array in settings.c then we store it
            mask_4x4_grid = create_4x4_mask_grid(size);
            // We choose a solution grid from the solution array in settings.c then we store it
            solution_grid_4x4 = create_4x4_solution_grid(size);

            printf("A new mask has been choosen randomly, therefore a new game grid. Let the game begin.\n");
            // We create the game grid according to the solution grid and the mask
            game_grid4x4 = create_game_grid(mask_4x4_grid, solution_grid_4x4, size);

            printf("\n\n----- GAME GRID -----\n");
            display_grid(game_grid4x4, size);
            printf("\n");

            solving_game_automatic(size,game_grid4x4, solution_grid_4x4);

            starter_menu();
        }
        case 2 :
        {
            char **solution_grid_8x8, **mask_8x8_grid, **game_grid8x8 = NULL;
            int size = 8;
            // We choose a mask grid from the mask array in settings.c then we store it
            mask_8x8_grid = create_8x8_mask_grid(size);
            // We choose a solution grid from the solution array in settings.c then we store it
            solution_grid_8x8 = create_8x8_solution_grid(size);

            printf("A new mask has been choosen randomly, therefore a new game grid. Let the game begin.\n");
            // We create the game grid according to the solution grid and the mask
            game_grid8x8 = create_game_grid(mask_8x8_grid, solution_grid_8x8, size);

            printf("\n\n----- GAME GRID -----\n");
            display_grid(game_grid8x8, size);
            printf("\n");

            solving_game_automatic(size,game_grid8x8, solution_grid_8x8);

            starter_menu();
        }
        case 3:
        {
            starter_menu();
        }
        default:
        {
            printf("Choice selected not proposed.\n");
            starter_menu();
        }
    }
}

void ThirdChoice_Submenu_One() {
    int grid_choice;
    printf("Which size of grid do you want to play with ?\n"
           "1. Enter 1 for a 4x4 grid\n"
           "2. Enter 2 for a 8x8 grid\n"
           "3. Enter 3 to return to starter menu\n>>>");
    scanf(" %d",&grid_choice);
    switch(grid_choice)
    {
        case 1:
        {
            int size = 4;
            ThirdChoice_Submenu_Two(size);
        }
        case 2 :
        {
            int size = 8;
            ThirdChoice_Submenu_Two(size);
        }
        case 3:
        {
            starter_menu();
        }
        default:
        {
            printf("Choice selected not proposed.\n");
            starter_menu();
        }
    }
}

void ThirdChoice_Submenu_Two(int size)
{
    int grid_choice;
    printf("What do you want to do?\n"
           "1. Enter 1 to display all valid rows (columns)\n"
           "2. Enter 2 to generate a valid Takuzu grid\n"
           "3. Enter 3 to return to starter menu\n>>>");
    scanf(" %d",&grid_choice);
    switch(grid_choice)
    {
        case 1:
        {
            char *generated_row;
            int size_for_random;
            char is_row_good;
            int decimal_number;

            /* We create this list to store the decimal numbers already generated as rows so that we don't have
             * similar rows since it's againt the rules of the takuzu */

            // If Size = 4, the decimal numbers goes from 0 to 15
            if(size == 4)
                size_for_random = 16;
            // If Size = 8, the decimal numbers goes from 0 to 255
            if(size == 8)
                size_for_random = 256;


            printf("------------------------------------------------------------------------------------\n");
            printf("-                 Here's the list of all valid Rows for a %dx%d grid               -\n",size,size);
            printf("------------------------------------------------------------------------------------\n");
            printf("\n");
            sleep(3);
            for(int rows = 1; rows < size_for_random; rows++)
            {
                decimal_number = rows;
                //printf("decimal number: %d\n",decimal_number);
                // GENERATION OF THE ROW
                // We then generate a row by transforming that decimal into binary
                generated_row = generate_row(size, decimal_number);
                // We check if the row is valid according to the rules of the Takuzu
                is_row_good = check_row(generated_row,size);
                //printf("is_row_good: %c\n",is_row_good);
                if(is_row_good == 'Y')
                    display_a_row(generated_row,size);
            }
            sleep(3);
            starter_menu();
        }
        case 2 :
        {
            char **solution_grid;
            char *generated_row;
            char is_row_good, is_decimal_in_list;
            int decimal_number, stop_condition = 0, filled_rows_in_array=0;

            /* We create this list to store the decimal numbers already generated as rows so that we don't have
             * similar rows since it's against the rules of the takuzu */

            int *decimal_number_list = (int*) malloc(size * sizeof(int));
            solution_grid =  generate_a_2D_array(size);

            printf("------------------------------------------------------------------------------------\n");
            printf("-                 Here's the list of all valid Rows for a %dx%d grid               -\n",size,size);
            printf("------------------------------------------------------------------------------------\n");
            printf("\n");
            for(int rows = 0; rows < size; rows++)
            {
                do
                {
                    // GENERATION OF THE DECIMAL NUMBER
                    do
                    {
                        // We first generate a decimal number number
                        decimal_number= generate_a_decimal_number(size);

                        // We check if the number is in the list to avoid displaying the same rows
                        is_decimal_in_list = is_number_in_list(size, decimal_number, decimal_number_list);

                        // If decimal is not in the list, we add it then we continue forward
                        if(is_decimal_in_list == 'N')
                        {
                            // We add that decimal number to a list so that the program doesn't reuse it for other rows
                            decimal_number_list[rows] = decimal_number;
                            //printf("decimal_number_list[%d] : %d\n",rows,decimal_number_list[rows]);
                            stop_condition = 1;
                        }
                        // If it's in the list, we generate a new one until that one isn't in the list
                    }while(stop_condition == 0 );

                    // GENERATION OF THE ROW

                    // We then generate a row by transforming that decimal into binary
                    generated_row = generate_row(size, decimal_number);
                    // We check if the row is valid according to the rules of the Takuzu
                    is_row_good = check_row(generated_row,size);
                    //printf("is_row_good: %c\n",is_row_good);
                }while(is_row_good == 'N');

                // When the generated row is seen as valid, we display it
                display_a_row(generated_row,size);

                // When the generated row is seen as valid, we store it in a 2D array solution grid
                for(int col = 0; col < size; col++)
                {
                    solution_grid[rows][col] = generated_row[col];
                }
                filled_rows_in_array++;

            }

            // We display the final grid
            printf("----- FINAL VALID GRID -----\n");
            display_grid(solution_grid, size);
            printf("\n");
            starter_menu();

        }
        case 3:
        {
            starter_menu();
        }
        default:
        {
            printf("Choice selected not proposed.\n");
            starter_menu();
        }
    }
}
