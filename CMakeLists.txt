cmake_minimum_required(VERSION 3.21)
project(project-Takuzu C)

set(CMAKE_C_STANDARD 99)

add_executable(project-Takuzu main.c solving_grid.c solving_grid.h generate_grid.c generate_grid.h menus.c menus.h settings.c settings.h)
