/*
** EPITECH PROJECT, 2022
** task03
** File description:
** len(str)
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}
