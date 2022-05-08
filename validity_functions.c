//
// Created by nolwen ngassa on 4/29/22.
//

#include "validity_functions.h"
/* This file contains all the functions that verifies if the rules of the takuzu are respected in a given game grid */

char CheckIf3successiveOccurrences(char** game_grid, char number_to_verify_its_occurrence, int size, int row_or_col_move, char row_or_col)
{
    if(row_or_col == 'R')
    {
        for(int col = 0; col < size - 2; col++)
        {
            if((game_grid[row_or_col_move][col] == number_to_verify_its_occurrence) && (game_grid[row_or_col_move][col + 1] == number_to_verify_its_occurrence) && (game_grid[row_or_col_move][col + 2] == number_to_verify_its_occurrence) && (game_grid[row_or_col_move][col] != '_'))
            {
                // We return Y as in 'Yes there are 3 successives occurences
                return 'Y';
            }
        }
    }
        // For Cols
    else
    {
        for(int row = 0; row < size - 2; row++)
        {
            if((game_grid[row][row_or_col_move] == number_to_verify_its_occurrence) && (game_grid[row + 1][row_or_col_move] == number_to_verify_its_occurrence) && (game_grid[row + 2][row_or_col_move] == number_to_verify_its_occurrence) && (game_grid[row][row_or_col_move] != '_'))
            {
                // We return Y as in 'Yes there are 3 successives occurences
                return 'Y';
            }
        }
    }

    // We return N as in 'No there are not 3 successive occurrences'
    return 'N';

}
// This function will check if the row where the player played contains 3 successives 1 or 0
char Is_there_3Occurrences_in_game_grid_Row(char** game_grid, int size, int row_move)
{
    char is_there_in_0, is_there_in_1;
    is_there_in_0 = CheckIf3successiveOccurrences(game_grid, '0', size, row_move, 'R');
    is_there_in_1 = CheckIf3successiveOccurrences(game_grid, '1', size, row_move, 'R');
    if( is_there_in_1 == 'N' && is_there_in_0 == 'N')
    {
        // If there are no successives 1 or 2 in the played row, then it returns Y for 'Yes rule is valid'
        return 'Y';
    }
    else
    {
        printf("\n\n>>> There cannot be more than two 1 or 0 in a row in the Takuzu.\n");
        printf("Hint : Above, below, to the left, to the right of a series of two 0's, there can only be one 1. Same for 0.\n");
        printf("Hint 2 : Between two 0's or two 1's, there can only be one 1 or one 0\n\n");
        return 'N';
    }
}

// This function will check if the column where the player played contains 3 successives 1 or 0
char Is_there_3Occurrences_in_game_grid_Col(char** game_grid, int size, int col_move)
{
    char is_there_in_0, is_there_in_1;
    is_there_in_0 = CheckIf3successiveOccurrences(game_grid, '0', size, col_move, 'C');
    is_there_in_1 = CheckIf3successiveOccurrences(game_grid, '1', size, col_move, 'C');
    if( is_there_in_1 == 'N' && is_there_in_0 == 'N')
    {
        // If there are no successives 1 or 2 in the played column, then it returns Y for 'Yes rule is valid'
        return 'Y';
    }
    else
    {
        printf("\n>>> There cannot be more than two 1 or 0 in a column in the Takuzu.\n");
        printf("Hint : Above, below, to the left, to the right of a series of two 0's, there can only be one 1. Same for 0.\n");
        printf("Hint 2 : Between two 0's or two 1's, there can only be one 1 or one 0\n");
        return 'N';
    }
}


// Functions associated to Rule 1: In a row, there must be as many 0s as 1s

int Occurrences_in_row_or_col(char** game_grid, char number_to_verify_its_occurrence, int size, int row_or_col_move, char row_or_col)
{
    int counter = 0;
    // For Rows
    if(row_or_col == 'R')
    {
        for(int col = 0; col < size; col++)
        {
            if(game_grid[row_or_col_move][col] == number_to_verify_its_occurrence)
            {
                counter += 1;
            }
        }
    }
    // For Cols
    else
    {
        for(int row = 0; row < size; row++)
        {
            if(game_grid[row][row_or_col_move] == number_to_verify_its_occurrence)
            {
                counter += 1;
            }
        }
    }
    return counter;
}

//
char CountNumbers_Row(char** game_grid, int size, int row_move)
{
    int nb_of_0, nb_of_1;
    nb_of_0 = Occurrences_in_row_or_col(game_grid, '0', size, row_move, 'R');
    nb_of_1 = Occurrences_in_row_or_col(game_grid, '1', size, row_move, 'R');
    if(nb_of_0 != nb_of_1)
    {
        printf(">>> In a row, there must be as many 0s as 1s. It's not the case for your matrix.\n");
        printf("Hint : Count the number of 1 or 0 in row [%d]\n",row_move);
        // We therefore return N for 'No the rule is NOT validated'
        return 'N';
    }
    // We therefore return Y for 'Yes the rule is validated'
    return 'Y';

}

// Functions associated to this rule : In a column, there must be as many 0s as 1s

char CountNumbers_Col(char** game_grid, int size, int col_move)
{
    int nb_of_0, nb_of_1;
    nb_of_0 = Occurrences_in_row_or_col(game_grid, '0', size, col_move, 'C');
    nb_of_1 = Occurrences_in_row_or_col(game_grid, '1', size, col_move, 'C');
    if(nb_of_0 != nb_of_1)
    {
        printf(">>> In a column, there must be as many 0s as 1s. It's not the case for your matrix.\n");
        printf("Hint : Count the number of 1 or 0 in column [%d]",col_move);
        // We therefore return N for 'No the rule is NOT validated'
        return 'N';
    }
    // We therefore return Y for 'Yes the rule is validated'
    return 'Y';
}

// Functions associated to this rule : There cannot be two identical rows in a grid

char check_if_rows_equal(char** game_grid, int rowcolsize, int row_move)
{
    char temp_list[10] = {0}, temp_list2[10] = {0};
    // We fill the temp list with the row where the user played
    for(int i = 0; i < rowcolsize; i++)
    {
        temp_list[i] = game_grid[row_move][i];
    }

    // We now check if the other rows are similar with our current row stored in temp_list
    for(int row = 0; ( (row < rowcolsize) ); row++) {
        int same = 1;
        // If the current row that the For loop is going through is already the one in the temp_list, we skip it
        if(row == row_move)
            continue;
        // We fill temp_list2 with the current row that the loop is going through
        for(int col = 0; (col < rowcolsize); col++)
        {
            temp_list2[col] = game_grid[row][col];
        }
        // We now compare if our row (played by the user) is the same as the current row
        for(int element = 0; ( (element < rowcolsize) && (same == 1)) ; element++)
        {
            if(temp_list[element] != temp_list2[element])
            {
                same = 0;
            }
        }
        // If same == 1, that meant that our lists are identical
        if(same == 1)
        {
            printf(">>> There are two similar rows in your game grid and it's against one of the Takuzu Rules. The following rows are row %d and row %d.\n",row_move,row);
            // We therefore return N for 'No the rule is NOT validated'
            return 'N';
        }
        // If it's 0, then they're not and we continue to compare our current row with the other rows of the game grid
    }
    // We therefore return Y for 'Yes the rule is validated'
    return 'Y';
}


// Functions associated to this rule : There cannot be two identical columns in a grid

char check_if_cols_equal(char** game_grid, int rowcolsize, int col_move)
{
    char temp_list[10] = {0}, temp_list2[10] = {0};

    // We fill the temp list with the column where the user played
    for(int i = 0; i < rowcolsize; i++)
    {
        temp_list[i] = game_grid[i][col_move];
    }

    // We now check if the other columns are similar with our current column stored in temp_list
    for(int col = 0; ( (col < rowcolsize) ); col++) {
        int same = 1;
        // If the current column that the For loop is going through is already the one in the temp_list, we skip it
        if(col == col_move)
            continue;
        // We fill temp_list2 with the current column that the loop is going through
        for(int row = 0; (row < rowcolsize); row++)
        {
            temp_list2[row] = game_grid[row][col];
        }
        // We now compare if our column (played by the user) is the same as the current column
        for(int element = 0; ( (element < rowcolsize) && (same == 1)) ; element++)
        {
            if(temp_list[element] != temp_list2[element])
            {
                same = 0;
            }
        }
        // If same == 1, that meant that our lists are identical
        if(same == 1)
        {
            printf(">>> There are two similar columns in your game grid and it's against one of the Takuzu Rules. The following columns are col %d and col %d.\n",col_move,col);
            // We therefore return N for 'No the rule is NOT validated'
            return 'N';
        }
    }
    // We therefore return Y for 'Yes the rule is validated'
    return 'Y';
}

// FUNCTIONS RELATED TO THE THIRD PART

int Count_Occurrences(char* binary_code, char number_to_verify_occurence, int size)
{
    int counter = 0;
    for(int element = 0; element < size; element++)
    {
        if(binary_code[element] == number_to_verify_occurence)
        {
            counter += 1;
        }
    }
    return counter;
}

char Part_3CountNumbers_Row(char* binary_code, int size)
{
    int nb_of_0, nb_of_1;
    nb_of_0 = Count_Occurrences(binary_code, '0', size);
    nb_of_1 = Count_Occurrences(binary_code, '1', size);
    if(nb_of_0 != nb_of_1)
    {
        // The rule "There must be as many 0s as 1s. It's not the case for your matrix." is not respected
        return 'N';
    }
    // We return Y for 'Yes the rule is validated'
    return 'Y';

}

char Part3_CheckIf3successiveOccurrences(char* binary_code, char number_to_verify_occurrence, int size)
{
    for(int element = 0; element < size-2; element++)
    {
        if((binary_code[element] == number_to_verify_occurrence) && (binary_code[element + 1] == number_to_verify_occurrence) && (binary_code[element + 2] == number_to_verify_occurrence) )
        {
            // We return Y as in 'Yes there are 3 successive occurrences
            return 'Y';
        }
    }
    return 'N';
}

char Part3_3Occurrences_Row(char* binary_code, int size)
{
    char is_there_in_0, is_there_in_1;
    is_there_in_0 = Part3_CheckIf3successiveOccurrences(binary_code, '0', size);
    is_there_in_1 = Part3_CheckIf3successiveOccurrences(binary_code, '1', size);
    if( is_there_in_1 == 'N' && is_there_in_0 == 'N')
    {
        // If there are no successive 1 or 2 in the played row, then it returns Y for 'Yes rule is valid'
        return 'Y';
    }
    else
        return 'N';
}

/* 1. There must be as many 0s as 1s
2. There cannot be more than two 0s or two 1s in a row (there cannot be three 0s or three
1s in a row) */
char check_row(char* binary_code, int size)
{
    char is_rule1_valid, is_rule2_valid;
    is_rule1_valid = Part_3CountNumbers_Row(binary_code, size);
    is_rule2_valid = Part3_3Occurrences_Row(binary_code, size);

    // If both rules are verified, then the row is valid so we return Y for 'Yes row is valid'
    if( (is_rule1_valid == 'Y') && (is_rule2_valid == 'Y') )
        return 'Y';
        // If not we return N for 'No not valid'
    else
        return 'N';
}

/* en soit c'est pas compliqué, tu fais une fonction qui vérifie que quand tu empiles les lignes il n'y a pas trois valeurs égales qui se suivent dans chaque colonne
et en meme temps tu checks si tu dépasse pas le nombre de 1 ou de 0 dans la colonne
en vérifiant que le nombre de 1 ou de 0 ne dépasse pas la moitié de la dimension*/





char Check_col(char **solution_grid, int nb_filled_rows_in_array, int size)
{
    char is_rule1_valid, is_rule2_valid;
    is_rule1_valid = Part3_3Occurrences_Col(solution_grid, size, nb_filled_rows_in_array);
    is_rule2_valid = Part3_3Occurrences_Row(binary_code, size);

    // If both rules are verified, then the row is valid so we return Y for 'Yes row is valid'
    if( (is_rule1_valid == 'Y') && (is_rule2_valid == 'Y') )
        return 'Y';
        // If not we return N for 'No not valid'
    else
        return 'N';
}

char Check_If_3_occurrences(char **solution_grid, char nbr_to_verify_occurrence, int filled_rows_in_array, int size)
{
    for(int row = 0; ( (row < size) && (row < filled_rows_in_array-2) ); row++)
    {
        for(int col = 0; col < size; col++)
        {
            if( (solution_grid[row][col] == nbr_to_verify_occurrence) && (solution_grid[row][col+1] == nbr_to_verify_occurrence) && (solution_grid[row][col+2] == nbr_to_verify_occurrence) )
            {
                // We return 'Y' for 'Yes there are 3 succ occurrences in a col
                return 'Y';
            }
        }
    }
    return 'N';
}

char Part3_3Occurrences_Col(char **solution_grid, int size,int filled_rows_in_array)
{
    char is_there_in_0, is_there_in_1;
    is_there_in_0 = Check_If_3_occurrences(solution_grid, '0',filled_rows_in_array, size);
    is_there_in_1 = Check_If_3_occurrences(solution_grid, '1',filled_rows_in_array, size);
    if( is_there_in_1 == 'N' && is_there_in_0 == 'N')
    {
        // If there are no successive 1 or 2 in the played row, then it returns Y for 'Yes rule is valid'
        return 'Y';
    }
    else
        return 'N';
}


