#include <stdio.h>
#include "generate_grid.h"
#include "solving_grid.h"
#include "menus.h"

int main() {
    int test[4][4] = {1,0,0,1,
                  1,0,1,0,
                  0,1,1,0,
                  0,1,0,1};
    int temporary_row[4]= {};

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            temporary_row[j] = test[i][j];
        }
        // We now compare if this array is the same as
    }
    return 0;
}
