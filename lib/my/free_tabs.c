/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myradar-jules.fradin
** File description:
** free_str_tab
*/

#include <stdlib.h>

void free_str_tab(char **str_tab)
{
    int i = 0;
    while (str_tab[i] != NULL) {
        free(str_tab[i]);
        i++;
    }
}

void free_int_tab(char **sea_map)
{
    for (int i = 0; i < 8; i++) {
        free(sea_map[i]);
    }
    free(sea_map);
}
