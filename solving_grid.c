//
// Created by nolwen ngassa on 4/7/22.
//

#include "solving_grid.h"

// Same system as number 1
// If the generated number is wrong well it says the problem then says that 'we wanted to play this but we can't bc of the
// reasons above so the answer is the other number

void solving_game_automatic(int size,char **game_grid, char **solution_grid)
{
    int row_move, col_move, desired_move;
    char right_answer, desired_move_char;
    char stop_condition = compareArray(game_grid, solution_grid,size);
    while(stop_condition == 'F')
    {
        srand(time(NULL));
        do {
            row_move = rand()%size;
            col_move = rand()%size;
            desired_move = rand()%2;
        }while( ( (game_grid[row_move][col_move] == '1') || (game_grid[row_move][col_move] == '0') ) );

        printf("Current box : [%d][%d]\n",row_move,col_move);
        printf("Current answer in that box : %d\n\n",desired_move);
        // We convert the desired move (which is an int) into a char since our grid is an array of char
        desired_move_char = desired_move + '0';
        game_grid[row_move][col_move] = desired_move_char;
        right_answer = check_if_move_is_the_right_move(solution_grid,game_grid, row_move, col_move, desired_move_char, size);
        if(right_answer == 'Y')
        {
            printf("We added a %d in box [%d][%d]\n",desired_move,row_move,col_move);
            printf("It follows all the rules of the Takuzu and it's the right answer.\n");

        }
        else if(right_answer == 'L')
        {
            // If the move is not correct and invalid, we put the opposite answer (if the computer said 1, but it's wrong, we put 0)
            printf("We added a %d in box [%d][%d]\n",desired_move,row_move,col_move);
            if(desired_move == 1)
            {
                game_grid[row_move][col_move] = '0';
                printf("Since it wasn't valid, we now replace it with 0.\n");
            }
            if(desired_move == 0)
            {
                game_grid[row_move][col_move] = '1';
                printf("Since it wasn't valid, we now replace it with 1.\n");
            }
        }
        else
        {
            // If the move is not correct, we put the previously entered move as empty again
            printf("We added a %d in box [%d][%d]\n",desired_move,row_move,col_move);
            printf("This move follows the rules of the Takuzu but is not the right answer.\n");
            if(desired_move == 1)
            {
                game_grid[row_move][col_move] = '0';
                printf("We therefore replace it with 0.\n");
            }
            if(desired_move == 0)
            {
                game_grid[row_move][col_move] = '1';
                printf("We therefore replace it with 1.\n");
            }
        }
        printf("--------------------------------------------\n\n");
        printf("----- CURRENT GAME GRID -----\n");
        display_grid(game_grid, size);
        printf("\n");
        stop_condition = compareArray(game_grid, solution_grid,size);

    }
    printf("--------------------------------------------\n");
    printf("The game grid has been completed.\n");
}
// Function to compare if the current game grid is the same as the solution grid [So that we can change the win boolean)

char compareArray(char **game_grid, char **solution_grid,int size)	{
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            if(game_grid[row][col] != solution_grid[row][col])
                return 'F';
        }
    }
    return 'T';
}

// Function of the main game (when not automatic, must be played by the player

void solving_game_not_automatic(int size,char **game_grid, char **solution_grid,int *life)
{
    int row_move, col_move, desired_move, nb_of_tries = 0;
    char right_answer, name[50];
    char win_output, desired_move_char;

    while( (*life > 0) )
    {
        printf("\n\n----- GAME GRID -----\n");
        display_grid(game_grid, size);
        printf("\n");
        // We check with the while if the move wanted is empty or not (so that the user can't edit the fixed grid)

        do {
            row_move = enter_row_number(size);
            col_move = enter_col_number(size);
            printf("Current box : [%d][%d]\n",row_move,col_move);
            desired_move = enter_desired_move();
            printf("\n");
            printf("After this, if you do not see your game grid and are instead ask the same questions, that means you wanted to edit an existing move.\n\n");
        }while( ( (game_grid[row_move][col_move] == '1') || (game_grid[row_move][col_move] == '0') ) );
        nb_of_tries++;

        printf("This is the current state of your grid with what you entered :");
        // We convert the desired move (which is an int) into a char since our grid is an array of char
        desired_move_char = desired_move + '0';
        //printf("%c",desired_move_char);
        game_grid[row_move][col_move] = desired_move_char;

        printf("\n\n----- GAME GRID -----\n");
        display_grid(game_grid,size);
        printf("\n");

        right_answer = check_if_move_is_the_right_move(solution_grid,game_grid, row_move, col_move, desired_move_char, size);
        //printf("right answer : %c\n",right_answer);
        //printf("life = %d\n",*life);
        if(right_answer == 'Y')
        {
            printf("\nYou got the right answer. Here's your new game grid.");
        }
        else if(right_answer == 'L')
        {
            *life -= 1;
            // If the move is not correct and invalid, we put the previously entered move as empty again
            game_grid[row_move][col_move] = '_';
            //printf("life = %d\n",*life);
            printf("Time to play another move\n");
        }
        else
        {
            // If the move is not correct, we put the previously entered move as empty again
            printf("Move valid but incorrect!\n");
            game_grid[row_move][col_move] = '_';
            printf("Time to play another move\n");
            // ASK IF WANT HINTS IIF POSSIBLE THEN DO HINT SYSTEM
        }

        // We launch this only if the player still has life left and didn't lose yet
        if( *life > 0)
        {
            win_output = compareArray(game_grid, solution_grid,size);
            //printf("win_output = %c\n",win_output);
            if(win_output == 'T')
            {
                // If win_output == True, that means the 2 grids are the same so the player won
                printf("\nCongratulations! You won.\n");

                printf("Enter your name :\n>>");
                scanf("%s",name);
                printf("Game Data :\n");
                printf(">>> Player name : %s\n",name);
                printf(">>> Number of tries : %d\n",nb_of_tries);
                printf(">>> Life left : %d/3\n",*life);
                break;
            }
            // If it's false, that means that the game grid and solution grid are not the same, so we continue playing
        }
        else
        {
            printf("Sorry...! You lost.\n");
            printf("Enter your name :\n>>");
            scanf("%s",name);
            printf("Game Data :\n");
            printf(">>> Player name : %s\n",name);
            printf(">>> Number of tries : %d\n",nb_of_tries);
            printf(">>> Life left : %d/3\n",*life);
        }

    }
}

// These are the functions that are going to ask the user about his desired move
int enter_row_number(int size)
{
    int wanted;
    do
    {
        printf("Enter the row number of your wanted move :\n");
        printf("If you are asked the question again, that means you entered an incorrect row number.\n>>");
        scanf(" %d",&wanted);
    }while(wanted >= size || wanted < 0);
    return wanted;
}

int enter_col_number(int size)
{
    int wanted;
    do
    {
        printf("Enter the col number of your wanted move :\n");
        printf("If you are asked the question again, that means you entered an incorrect col number.\n>>");
        scanf(" %d",&wanted);
    }while(wanted >= size || wanted < 0);
    return wanted;
}
int enter_desired_move()
{
    int move;
    do
    {
        printf("Enter your desired move (either 1 or 0) :\n");
        printf("If you are asked the question again, that means you entered an incorrect move.\n>>");
        scanf(" %d",&move);
    }while(move < 0 || move > 1);
    return move;
}

/* 1. In a row, there must be as many 0s as 1s
2. In a column, there must be as many 0s as 1s
3. There cannot be two identical rows in a grid
4. There cannot be two identical columns in a grid
5. In a row or column, there cannot be more than two 0s or two 1s in a row (there cannot be three 0s or three
1s in a row) */

char validity_of_move_If_Row_Complete(int row_move,char** game_grid, int size)
{
    char is_rule1_valid, isrule3_valid, isrule5_valid;
    is_rule1_valid = CountNumbers_Row(game_grid, size, row_move);
    isrule3_valid = check_if_rows_equal(game_grid,size,row_move);
    isrule5_valid = Is_there_3Occurrences_in_game_grid_Row(game_grid, size, row_move);

    if( (isrule3_valid == 'N') && (is_rule1_valid == 'N') && (isrule5_valid == 'N') )
        return 'N';
    else if( (isrule3_valid == 'Y') && (is_rule1_valid == 'Y') && (isrule5_valid == 'Y') )
        return 'Y';
    else
        return 'N';
}

char validity_of_move_If_Col_Complete( int col_move, char** game_grid,int size)
{
    char is_rule2_valid, is_rule4_valid, isrule5_valid;
    is_rule2_valid = CountNumbers_Col(game_grid, size, col_move);
    is_rule4_valid = check_if_cols_equal(game_grid, size, col_move);
    isrule5_valid = Is_there_3Occurrences_in_game_grid_Col(game_grid, size, col_move);


    if( (is_rule2_valid == 'N') && (is_rule4_valid == 'N') && (isrule5_valid == 'N') )
        return 'N';
    else if((is_rule2_valid == 'Y') && (is_rule4_valid == 'Y') && (isrule5_valid == 'Y'))
        return 'Y';
    else
        return 'N';
}


char Check_if_row_or_col_complete(char** game_grid, int rowcolsize, int row_or_col_move, char row_or_col)
{
    // For Rows
    if(row_or_col == 'R')
    {
        for(int col = 0; col < rowcolsize; col++)
        {
            if(game_grid[row_or_col_move][col] == '_')
            {
                // We return N (for No the row is not complete) when we found a _ since a _ in the game is an empty case
                return 'N';
            }
        }
    }
    // For Cols
    else
    {
        for(int row = 0; row < rowcolsize; row++)
        {
            if(game_grid[row][row_or_col_move] == '_')
            {
                return 'N';
            }
        }
    }
    // If we didn't find a _ (empty case) hen the col or row is complete, so we return Y for yes
    return 'Y';
}

char check_if_move_is_the_right_move(char **solution_grid,char **game_grid, int row_move, int col_move, int move, int rowcolsize)
{
    char row_complete, col_complete;
    char is_it_valid_row, is_it_valid_col;
    // We first check if the row of the move played by the user is complete
    row_complete = Check_if_row_or_col_complete(game_grid, rowcolsize, row_move, 'R');
    //printf("row_complete : %c\n",row_complete);

    // Same for the column
    col_complete = Check_if_row_or_col_complete(game_grid, rowcolsize, col_move, 'C');
    //printf("col_complete : %c\n",col_complete);
    // If the row/ col not complete, we can only check the rule : (there cannot be three 0s or three 1s in a row/col)
    if(row_complete == 'N' )
    {
        is_it_valid_row = Is_there_3Occurrences_in_game_grid_Row(game_grid, rowcolsize, row_move);
        //printf("is_it_valid_row : %c\n",is_it_valid_row);
    }
    if(col_complete == 'N' )
    {
        is_it_valid_col = Is_there_3Occurrences_in_game_grid_Col(game_grid, rowcolsize, col_move);
        //printf("is_it_valid_col : %c\n",is_it_valid_col);
    }
    // If row is complete, we check other several rules
    if(row_complete == 'Y')
    {
        is_it_valid_row = validity_of_move_If_Row_Complete(row_move,game_grid, rowcolsize);
        //printf("is_it_valid_row : %c\n",is_it_valid_row);
    }

    // Same for columns
    if(col_complete == 'Y' )
    {
        is_it_valid_col = validity_of_move_If_Col_Complete(col_move,game_grid, rowcolsize);
        //printf("is_it_valid_col : %c\n",is_it_valid_col);
    }

    // If move valid, we then check if it's the right move, if it's not : lose life

    if(is_it_valid_row == 'Y' && is_it_valid_col == 'Y') {
        // If move valid, we then check if it's the right move
        if (solution_grid[row_move][col_move] == move) {
            return 'Y';
        }
        else {
            //printf("Your move is valid but it's not correct (not the right answer).\n");
            return 'N';
        }
    }

    // If move not valid, player loses life
    if( (is_it_valid_row =='Y' && is_it_valid_col == 'N') || ( is_it_valid_row =='N' && is_it_valid_col == 'Y') || (is_it_valid_row == 'N' && is_it_valid_col == 'N') )
    {
        // Player loses life because move is not valid
        return 'L';
    }
}

// FUNCTIONS RELATED TO THE THIRD PART

