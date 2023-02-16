/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** user_input
*/

#include <unistd.h>
#include "my.h"
#include "my_navy.h"

extern global_t globale;

/**
 * @brief check if the user input is valid: including argc and file validity
 *
 * @retval NAVY_SUCCESS on success
 * @retval NAVY_ERR on failure
 * @todo criterion
 */
int user_input(int argc, char const *const *argv, instance_t *instance)
{
    char const *path;
    if (argc != 2 && argc != 3) {
        write(2, "Invalid input ./navy -h for further usage information.\
\n", 55);
        return NAVY_ERR;
    }
    if (!my_strncmp(argv[1], "-h", 2)) {
        print_help();
        return NAVY_SUCCESS;
    }
    if (argc == 2)
        path = argv[1];
    else {
        instance->player = 1;
        globale.opponent = my_getnbr(argv[1]);
        path = argv[2];
    }
    if (!verify_file_validity(path))
        return NAVY_SUCCESS;
    return NAVY_ERR;
}
