//
// Created by nolwen ngassa on 4/20/22.
//

#include <stdio.h>
#include "generate_grid.h"
#include "settings.h"
#include <unistd.h>

#ifndef PROJECT_TAKUZU_MENUS_H
#define PROJECT_TAKUZU_MENUS_H

void FirstChoice_Submenu_One();
void FirstChoice_Submenu_Two(char **solution_grid, char **mask_grid, char **game_grid, int rowcolsize);

void SecondChoice_Submenu_One();
void starter_menu();

void ThirdChoice_Submenu_One();
void ThirdChoice_Submenu_Two(int size);
#endif //PROJECT_TAKUZU_MENUS_H
