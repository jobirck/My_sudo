/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** copier une string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest = '\0';
    return dest;
}
