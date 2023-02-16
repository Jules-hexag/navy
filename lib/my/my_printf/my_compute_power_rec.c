/*
** EPITECH PROJECT, 2022
** task04
** File description:
** powering numbers recursive
*/
long double my_power(long double nb, int p)
{
    if (p == 0)
        return 1l;
    if (p < 0)
        return my_power(nb, p + 1) / nb;
    return my_power(nb, p - 1) * nb;
}
