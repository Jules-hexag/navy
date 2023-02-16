/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** print_map
*/

/**
 * @file print_map.c
 * @brief Function for printing the map.
 */

#include <unistd.h>
#include "my_navy.h"
#include "my.h"

static void what_to_print(int map_number, int j)
{
    if (j != 7) {
        if (map_number == 0) my_printf(". ");
        if (map_number == -1) my_printf("x ");
        if (map_number == -2) my_printf("o ");
        if (map_number > 0)
            my_printf("%d ", map_number);
        return;
    }
    if (map_number == 0) my_printf(".");
    if (map_number == -1) my_printf("x");
    if (map_number == -2) my_printf("o");
    if (map_number > 0)
        my_printf("%d", map_number);
}

/**
 * @fn void print_map(int **map)
 * @brief Prints the map.
 * @param map Map.
 * @todo doc
 * @todo criterion
 */
void print_map(int **map)
{
    my_printf(
        " |A B C D E F G H\n"
        "-+---------------\n");
    for (int i = 0; map[i] != NULL; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            what_to_print(map[i][j], j);
        }
        my_printf("\n");
    }
    my_printf("\n");
}
