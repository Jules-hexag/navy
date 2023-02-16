/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** create_map
*/

/**
 * @file create_map.c
 * @brief Function to create map.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "my.h"
#include "my_navy.h"

/**
 * @see static void retrieve_line(FILE *file_ptr, int **map);
 *
 * @brief determine if the ship evolves either in the vertical or horizontal
 *        axis
 *
 * @param line the line currently under reading
 * @param map the tab that represents the game of the player
 *
 * @return int NAVY_SUCCESS on success / NAVY_ERR on failure
 * @todo criterion
 */
static int determine_ship_orientation(char **line, int **map)
{
    bool vertical_evolution = false;
    line[1][0] == line[2][0] ? vertical_evolution = true : false;
    if (vertical_evolution) {
        int letter_index = line[1][0] - ('A');
        int min = find_min(my_getnbr(line[1]), my_getnbr(line[2]));
        int max = find_max(my_getnbr(line[1]), my_getnbr(line[2]));
        int ship_len = max - min + 1;
        if (ship_len != my_getnbr(line[0])) return NAVY_ERR;
        if (push_vertical_ship(ship_len, map, min - 1, letter_index))
            return NAVY_ERR;
    }
    if (!vertical_evolution) {
        int line_index = my_getnbr(line[1]) - 1;
        int letter_min = find_min(line[1][0], line[2][0]) - 'A';
        int letter_max = find_max(line[1][0], line[2][0]) - 'A';
        int ship_len = letter_max - letter_min + 1;
        if (ship_len != my_getnbr(line[0])) return NAVY_ERR;
        if (push_horizontal_ship(ship_len, map, line_index, letter_min))
            return NAVY_ERR;
    } return NAVY_SUCCESS;
}

/**
 * @see int **create_map(const int argc, char *const *const argv);
 *
 * @brief read the file line by line and pushes the ships in the int** map
 *
 * @param file_ptr pointer to the file to be opened
 * @param map the tab that represents the game of the player
 *
 * @return int NAVY_SUCCESS on success / NAVY_ERR on failure
 * @todo criterion
 */
static int retrieve_line(FILE *file_ptr, int **map)
{
    char *line_ptr = NULL;
    size_t len = 0;
    for (int i = 0; i < 4; i++) {
        getline(&line_ptr, &len, file_ptr);
        char **line = my_str_to_word_array_free_delimiter(line_ptr);
        if (char_tab_len(line) != 3) {
            my_printf("%d\n", char_tab_len(line));
            write(2, "Invalid number of columns in one or more line: must be \
3.\n", 58);
            return NAVY_ERR;
        }
        if (determine_ship_orientation(line, map)) return NAVY_ERR;
        free_str_tab(line);
    }
    return NAVY_SUCCESS;
}

/**
 * @brief Create the tab that represents the game of the player
 *
 * @return int** : the tab that represents the game of the player
 * @todo criterion
 */
int **create_map(const int argc, char const *const *argv)
{
    FILE *file_ptr = NULL;
    char const *path = "";
    if (argc == 2) path = argv[1];
    if (argc == 3) path = argv[2];

    int **map = malloc(sizeof(int *) * 9);
    if (!map) return NULL;
    map[8] = NULL;
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(int) * 9);
    }
    fill_with_zeros(map);

    file_ptr = fopen(path, "r");
    if (file_ptr == NULL) return NULL;
    if (retrieve_line(file_ptr, map)) return NULL;
    fclose(file_ptr);
    return map;
}
