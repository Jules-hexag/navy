/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** my_navy
*/

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_
    #define EPITECH_ERR 84

    /* SOURCE */
    int my_navy(const int argc, char *const *const argv);

    /* INPUT */
    int user_input(const int argc, char *const *const argv);
    void print_help(void);
    int verify_file_validity(char *path);

#endif /* !MY_NAVY_H_ */
