/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** help
*/

#include "my.h"

/**
 * @brief display help on the stdout
 */
void print_help(void)
{
    my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\n\
DESCRIPTION\n\tfirst_player_pid: only for the 2nd player. pid of the first\
player.\n\tnavy_positions: file representing the positions of the ships.");
}
