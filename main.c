//--------------//
// MAIN PROGRAM //
//--------------//

/* Includes */
#include <stdio.h>
#include "generate_grid.h"
#include "solving_grid.h"
#include "menus.h"

int main(){
    /* Main function */
    srand(time(NULL)); // selecting a random number for mask and grid
    starter_menu();
    return 0;
}
