/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** find_min
*/

#include <unistd.h>

int char_tab_len(char **tab)
{
    int len = 0;
    while (tab[len] != NULL)
        len++;
    return len;
}

int find_min(int a, int b)
{
    if (a < b) return a;
    return b;
}

int find_max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int fill_with_zeros(int **map)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[i][j] = 0;
        }
    }
    return 0;
}
