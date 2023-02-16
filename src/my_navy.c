/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** my_navy
*/

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "my_navy.h"

/**
 * @file my_navy.c
 * @brief Main functions of the game.
 */

global_t globale;
/**
 * @brief
 * @param input
 */
uint8_t scan_input(int input[2])
{
    char *line = NULL;
    size_t n = 0;
    bool check = false;
    size_t read = 0;
    while (read != 3 || check == false) {
        write(1, "attack: ", 8);
        read = getline(&line, &n, stdin);
        input[0] = line[0] - 'A';
        input[1] = line[1] - '1';
        check = true;
        if (input[0] > 8 || input[0] < 0 || input[1] > 8 || input[1] < 0) {
            write(1, "wrong position\n", 15);
            check = false;
        }
    }
    uint8_t msg = 0;
    SET_TORP(msg, input[0], input[1]);
    return msg;
}

void enemy_is_playing(instance_t *instance)
{
    write(1, "waiting for enemy's attack...\n", 30);
    uint8_t msg = receive_byte();
    uint8_t mesg = RETURN << 6 | receive_shoot(instance, msg);
    usleep(100);
    send_byte(mesg);
    i_lose(instance);
}

void map_printer(instance_t *instance)
{
    write(1, "my positions:\n", 14);
    print_map(instance->seamap);
    write(1, "enemy's positions:\n", 19);
    print_map(instance->enemy_map);
}

/**
 * @brief
 * @param player_id
 * @param instance
 */
void game_loop(int player_id, instance_t *instance)
{
    bool my_turn = !player_id;
    while (globale.start == true) {
        if (my_turn == !player_id)
            map_printer(instance);
        if (my_turn == true) {
            int input[2] = {0};
            uint8_t msg = scan_input(input);
            usleep(10000);
            send_byte(msg);
            msg = receive_byte();
            print_shoot_result(input, instance, msg);
            my_turn = false;
            i_won(instance);
            continue;
        }
        if (my_turn == false) {
            enemy_is_playing(instance);
            my_turn = true;
        }
    }
}

/**
 * @brief processes the main steps of the navy program
 *
 * @retval NAVY_SUCCESS on success
 * @retval NAVY_ERR on failure
 * @todo criterion
 */
int my_navy(int argc, char const *const *argv)
{
    instance_t instance;

    if (user_input(argc, argv, &instance) == NAVY_ERR)
        return NAVY_ERR;
    instance.seamap = create_map(argc, argv);
    instance.enemy_map = create_enemy_map();
    if (instance.seamap == NULL) {
        write(2, "Map failed to load or two or more ships are being superposed"
            " or ship length does not match with the first column\n", 113);
        return NAVY_ERR;
    }
    handshake(instance.player, globale.opponent);
    game_loop(instance.player, &instance);
    free_int_tab(instance.seamap);
    free_int_tab(instance.enemy_map);
    return instance.winner;
}
