/*
** EPITECH PROJECT, 2022
** task05
** File description:
** return a number out of a str
*/
#include "my.h"

static int is_number(char c)
{
    if (c > 47 && c < 58)
        return 1;
    return 0;
}

static int overflow(long int nbr, int neg)
{
    if (nbr > 2147483647 && neg == 0)
        return 1;
    if (-nbr < -2147483648 && neg == 1)
        return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long int nbr = 0;
    int neg = 1;
    while (str[i] != '\0') {
        if (is_number(str[i]) == 1 || str[i] == '-')
            break;
        i++;
    }
    while (str[i] == '-') {
        neg *= -1;
        i++;
    }
    while (is_number(str[i]) == 1) {
        nbr *= 10;
        nbr = nbr + str[i] - 48;
        i++;
    }
    if (overflow(nbr, (neg == -1))) return 0;
    return nbr * neg;
}
