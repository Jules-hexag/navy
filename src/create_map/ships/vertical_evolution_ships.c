/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** vertical_evolution_ships
*/

#include "my_navy.h"

/**
 * @brief pushes a vertical ship in the grid
 *
 * @param ship_len[in]  length of the ship (greater number - lower numer + 1)
 * @param map[out]      grid: map of the game
 * @param min[in]       the most at top extremity of the ship
 * @param letter_index[in] index of the letter, according to ASCII table
 *
 * @return int NAVY_SUCCESS on success / NAVY_ERR on failure
 * @todo criterion
 */
int push_vertical_ship(int ship_len, int **map, int min, int letter_index)
{
    int i = 0;
    while (i < ship_len) {
        if (map[i + min][letter_index]) return NAVY_ERR;
        map[i + min][letter_index] = ship_len;
        i++;
    }
    return NAVY_SUCCESS;
}
