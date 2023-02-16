/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** is_there_a_winner
*/

#include <stdbool.h>
#include <unistd.h>
#include "my_navy.h"
#include "my.h"

extern global_t globale;

int i_won(instance_t *instance)
{
    int crossed = 14;
    for (int i = 0; instance->enemy_map[i] != NULL; i++) {
        for (int j = 0; j < 8; j++) {
            instance->enemy_map[i][j] == -1 ? crossed-- : crossed;
        }
    }
    if (crossed <= 0) {
        my_printf("I won\n");
        globale.start = false;
        instance->winner = 0;
        return 0;
    }
    return -1;
}

int i_lose(instance_t *instance)
{
    int crossed = 14;
    for (int i = 0; instance->seamap[i] != NULL; i++) {
        for (int j = 0; j < 8; j++) {
            instance->seamap[i][j] == -1 ? crossed-- : crossed;
        }
    }
    if (crossed <= 0) {
        map_printer(instance);
        my_printf("Enemy won\n");
        globale.start = false;
        instance->winner = 1;
        return 1;
    }
    return -1;
}
