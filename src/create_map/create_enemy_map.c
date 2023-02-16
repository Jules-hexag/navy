/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** create_enemy_map
*/

#include <malloc.h>
#include <unistd.h>
#include "my.h"

/**
 * @brief Create a enemy map tab filled with 0's
 *
 * @return int** The enemy map
 */
int **create_enemy_map(void)
{
    int **map = malloc(sizeof(int *) * 9);
    if (!map) return NULL;
    map[8] = NULL;
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(int) * 9);
    }
    fill_with_zeros(map);

    return map;
}
