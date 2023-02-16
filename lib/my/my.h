/*
** EPITECH PROJECT, 2022
** my_lib header
** File description:
** all prototypes
*/

#ifndef MY_LIB_
    #define MY_LIB_

    int find_min(int a, int b);
    int find_max(int a, int b);
    int fill_with_zeros(int **map);
    int char_tab_len(char **tab);
    char **my_str_to_word_array_free_delimiter(char *str);
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_getnbr(char const *str);
    int free_str_tab(char **str_tab);
    void free_int_tab(int **sea_map);
    char *my_itoa(unsigned int nbr);
    char *my_strncpy(char *dest, char const *src, int n);
    int my_strlen(char const *str);
    int my_printf(char *str, ...);

#endif /* MY_LIB_ */
