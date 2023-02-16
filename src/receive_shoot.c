/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** recieve_shoot
*/

#include <stdint.h>
#include <unistd.h>
#include "my_navy.h"

/**
 * @brief Recieve shooting coords and check in seamap.
 *
 * @param map The player's map.
 * @param recieved_message The message sent by the opponent.
 *
 * @retval SHIP_MISSED if missed.
 * @retval SHIP_TOUCHE if touche.
 */
int receive_shoot(instance_t *instance, uint8_t received_message)
{
    int column = GET_COLUMN(received_message);
    int line = GET_LINE(received_message);
    char out[3] = {column + 'A', line + '1', ':'};
    write(1, out, 3);
    if (instance->seamap[line][column] > 0) {
        write(1, " hit\n\n", 6);
        instance->seamap[line][column] = -1;
        return SHIP_TOUCHE;
    }
    instance->seamap[line][column] = -2;
    write(1, " missed\n\n", 9);
    return SHIP_MISSED;
}
