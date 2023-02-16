/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** horizontal_evolution_ships
*/

#include "my_navy.h"

/**
 * @brief pushes a horizontal ship in the grid
 *
 * @param ship_len[in]  length of the ship (greater letter - lower letter + 1)
 * @param map[out]      grid: map of the game
 * @param line_index[in]       the most at left extremity of the ship
 * @param letter_min[in] index of the letter, according to ASCII table
 *
 * @return int NAVY_SUCCESS on success / NAVY_ERR on failure
 * @todo criterion
 */
int push_horizontal_ship(int ship_len, int **map, int line_index,
    int letter_min)
{
    int i = 0;
    while (i < ship_len) {
        if (map[line_index][letter_min + i])
            return NAVY_ERR;
        map[line_index][letter_min + i] = ship_len;
        i++;
    }
    return NAVY_SUCCESS;
}
