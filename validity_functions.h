//
// Created by nolwen ngassa on 4/29/22.
//

#ifndef PROJECT_TAKUZU_VALIDITY_FUNCTIONS_H
#define PROJECT_TAKUZU_VALIDITY_FUNCTIONS_H
#include <stdio.h>
#include <stdbool.h>

// Functions about the rule : In a row or column, there cannot be more than two 0s or two 1s in a row
char CheckIf3successiveOccurrences(char** game_grid, char number_to_verify_its_occurrence, int size, int row_or_col_move, char row_or_col);
char Is_there_3Occurrences_in_game_grid_Row(char** game_grid, int size, int row_move);
char Is_there_3Occurrences_in_game_grid_Col(char** game_grid, int size, int col_move);

// Functions about the rule : There must be as many 0s as 1
int Occurrences_in_row_or_col(char** game_grid, char number_to_verify_its_occurrence, int size, int row_or_col_move, char row_or_col);
char CountNumbers_Row(char** game_grid, int size, int row_move);
char CountNumbers_Col(char** game_grid, int size, int col_move);

char check_if_rows_equal(char** game_grid, int rowcolsize, int row_move);
char check_if_cols_equal(char** game_grid, int rowcolsize, int col_move);

// FUNCTIONS RELATED TO PART 3
int Count_Occurrences(char* binary_code, char number_to_verify_occurence, int size);
char Part_3CountNumbers_Row(char* binary_code, int size);

char Part3_CheckIf3successiveOccurrences(char* binary_code, char number_to_verify_occurrence, int size);
char Part3_3Occurrences_Row(char* binary_code, int size);

char check_row(char* binary_code, int size);

char Check_If_3_occurrences(char **solution_grid, char nbr_to_verify_occurrence, int filled_rows_in_array, int size);
char Part3_3Occurrences_Col(char **solution_grid, int size,int filled_rows_in_array);
char Check_col(char **solution_grid, int nb_filled_rows_in_array, int size);

#endif //PROJECT_TAKUZU_VALIDITY_FUNCTIONS_H
