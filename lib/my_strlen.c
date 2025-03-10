/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** compter le nombre de cara dans une string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
