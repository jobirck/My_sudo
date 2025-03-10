/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** copier un nombre de cara d'une string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && dest[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
    }
    return dest;
}
