/*
** EPITECH PROJECT, 2022
** my_lib header
** File description:
** all prototypes
*/

#ifndef MY_LIB_
    #define MY_LIB_

    void my_putchar(char c);
    int my_put_nbr(int nb);
    char **my_str_to_word_array(char *str);
    char *my_strstr(char *str, char const *to_find);
    int my_putstr(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    void my_swap(int *a, int *b);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    int my_strlen(char const *str);
    char *my_strcapitalize(char *str);
    int my_getnbr(char const *str);
    int free_str_tab(char **str_tab);
    int my_str_isalpha(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_str_isnum(char const *str);
    int my_compute_power_rec(int nb, int power);
    int my_str_islower(char const *str);
    int my_compute_square_root(int nb);
    int my_str_isupper(char const *str);
    int my_is_prime(int nb);
    int my_str_isprintable(char const *str);
    int my_find_prime_sup(int nb);
    int my_showstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    int my_showmem(char const *str, int size);              //Todo
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcat(char *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    char *my_itoa(unsigned int nbr);
    int my_printf(char *str, ...);

#endif /* MY_LIB_ */
