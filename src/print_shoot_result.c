/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** print_shoot_result
*/

#include "my_navy.h"
#include "my.h"
#include <stdint.h>

void print_shoot_result(int input[2], instance_t *instance, uint8_t msg)
{
    if (IS_HIT(msg)) {
        instance->enemy_map[input[1]][input[0]] = -1;
        my_printf("%c%d: hit\n\n", input[0] + 'A', input[1] + 1);
    }
    if (!IS_HIT(msg)) {
        if (instance->enemy_map[input[1]][input[0]] != -1)
            instance->enemy_map[input[1]][input[0]] = -2;
        my_printf("%c%d: missed\n\n", input[0] + 'A', input[1] + 1);
    }
}
