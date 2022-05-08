//
// Created by nolwen ngassa on 4/7/22.
//

#include "generate_grid.h"

// ---------- Generating valid TAKUZU rows ----------


int generate_a_decimal_number(int size)
{
    int decimal_number;
    // If it's a 4x4 grid, we want to generate a decimal number from 0 to 15
    if(size == 4)
    {
        decimal_number = rand()%16;
        return decimal_number;
    }
    // If it's a 8x8 grid, we want to generate a binary number from 0 to 15
    if(size == 8)
    {
        decimal_number = rand()%256;
        return decimal_number;
    }
    return 0;
}

// A function that checks if a number belongs to a list
char is_number_in_list(int size, int number, int* list)
{
    for(int i = 0; i < size; i++)
    {
        if(list[i] == number)
            return 'Y';
    }
    return 'N';

}

char* generate_row(int size, int decimal_number)
{
    // We create the array that's going to contain the generated number
    char*binary_code = (char*) malloc(size * sizeof(char));

    int temp;
    // We convert the decimal number to binary
    while( decimal_number > 0)
    {
        if( decimal_number != 0)
        {
            // We fill the array with the rest of the division of the decimal number by 2 because the rest constitute the binary number of the number
            for(int i=0; i < size; i++)
            {
                temp =  decimal_number % 2;
                // We transform the number that we just obtain into a char so that it will fit our array of characters
                binary_code[i] = temp + '0';
                decimal_number = decimal_number/2 ;
            }
        }
        else
        {
            for(int i=0; i < size; i++)
            {
                binary_code[i] = '0';
            }
        }
    }
    // We then reverse the array because it's by reversing it that we obtain the binary number of our decimal number
    char temp_storage;
    for(int i=0; i < size/2; i++)
    {
        temp_storage = binary_code[i];
        binary_code[i] = binary_code[size-i-1];
        binary_code[size-i-1] = temp_storage;
    }
    return binary_code;
}

// We generate a 2D Array, and we initialized it at 0;
char** generate_a_2D_array(int size)
{
    char**Array = (char**)malloc(sizeof(char*) * size);
    for(int row= 0;row < size; row++)
    {
        Array[row] = (char*)malloc(sizeof(char) * size);
        for(int col=0; col < size; col++)
        {
            Array[row][col] = '0';
        }
    }
    return Array;
}

void display_a_row(char *row,int size)
{
    printf("                                  ");
    for(int element_in_row= 0; element_in_row < size; element_in_row++)
    {
        printf("%c  ",row[element_in_row]);
    }
    printf("\n");
}



// ---------- Generating grids from existings grids in setting.c ----------


// Function that will create the game grid according to the mask that has been entered
char** create_game_grid(char **mask_grid, char **solution_grid,int rowcolsize)
{
    char**game_grid = (char**)malloc(sizeof(char*) * rowcolsize);
    for(int row= 0; row < rowcolsize; row++)
    {
        game_grid[row] = (char*)malloc(sizeof(char) * rowcolsize);
        for(int col=0; col < rowcolsize; col++)
        {
            if(mask_grid[row][col] == '0')
            {
                game_grid[row][col] = '_';
            }
            else
            {
                game_grid[row][col] = solution_grid[row][col];
            }
        }
    }
    return game_grid;
}

char** create_mask_by_user(int rowcolsize)
{
    printf("\nWe will show you one of the many solution grid in our database.\n"
           "You'll now be able to create your own mask.\nA mask just represents how the game grid will be.\n"
           "If you enter 0 when asked, the game box will be invisible in your game grid. If you enter 1, it will be visible.\n");
    int mask_value;
    char**mask = (char**)malloc(sizeof(char*) * rowcolsize);
    for(int row= 0; row < rowcolsize ; row++)
    {
        mask[row] = (char*)malloc(sizeof(char) * rowcolsize);
        for(int col=0; col < rowcolsize; col++)
        {
            printf("Current box : [%d][%d]\nWhat's do you want as your mask value >>",row,col);
            scanf(" %d",&mask_value);
            while(mask_value < 0 || mask_value > 1)
            {
                printf("You can only enter either 1 and 0. Please re-enter an input.\n");
                printf(">>>");
                scanf(" %d",&mask_value);
            }
            char mask_value_as_character;
            mask_value_as_character = mask_value + '0';
            mask[row][col] = mask_value_as_character;

        }
    }
    return mask;
}
char** create_4x4_mask_grid(int rowcolsize)
{
    srand(time(NULL));
    char**mask = (char**)malloc(sizeof(char*) * rowcolsize);
    // We generate a number between 0 and 3 to select one of the 4 grids up above
    int index = rand()%rowcolsize;
    // We fill a 4x4 array from one of the 4x4 grid up above in the 3D array
    for(int i = index; i < index+1; i++)
    {
        for(int row= 0;row < rowcolsize; row++)
        {
            mask[row] = (char*)malloc(sizeof(char) * rowcolsize);
            for(int col=0; col < rowcolsize; col++)
            {
                mask[row][col] = random_4x4_mask_grid[i][row][col];
            }
        }
    }
    return mask;
}

char** create_4x4_solution_grid(int rowcolsize)
{
    srand(time(NULL));
    char **solution = (char**)malloc(sizeof(char*) * rowcolsize);

    // We generate a number between 0 and 3 to select one of the 4 grids up above
    int index = rand()%rowcolsize;
    // We fill a 4x4 array from one of the 4x4 grid up above in the 3D array
    for(int i = index; i < index+1; i++)
    {
        for(int row= 0; row < rowcolsize; row++)
        {
            solution[row] = (char*)malloc(sizeof(char) * rowcolsize);
            for(int col=0; col < rowcolsize; col++)
            {
                solution[row][col] = random_4x4_solution_grid[i][row][col];
            }
        }
    }
    return solution;
}

char** create_8x8_mask_grid(int rowcolsize)
{
    char**mask = (char**)malloc(sizeof(char*) * rowcolsize);
    // We generate a number between 0 and 1 to select one of the 2 grids in settings.c
    int index = rand()%2;
    // We fill a 8x8 array from one of the 8x8 grid 3D array in settings.c
    for(int i = index; i < index+1; i++)
    {
        for(int row= 0;row < rowcolsize; row++)
        {
            mask[row] = (char*)malloc(sizeof(char) * rowcolsize);
            for(int col=0; col < rowcolsize; col++)
            {
                mask[row][col] = random_8x8_mask_grid[i][row][col];
            }
        }
    }
    return mask;
}

char** create_8x8_solution_grid(int rowcolsize)
{
    char **solution = (char**)malloc(sizeof(char*) * rowcolsize);

    // We generate a number between 0 and 1 to select one of the 2 grids in settings.c
    int index = rand()%2;
    // We fill a 8x8 array from one of the 8x8 grid 3D array in settings.c
    for(int i = index; i < index+1; i++)
    {
        for(int row= 0; row < rowcolsize; row++)
        {
            solution[row] = (char*)malloc(sizeof(char) * rowcolsize);
            for(int col=0; col < rowcolsize; col++)
            {
                solution[row][col] = random_8x8_solution_grid[i][row][col];
            }
        }
    }
    return solution;
}

void display_grid(char **grid,int rowcolsize)
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
            printf("  %c",grid[row][col]);
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

