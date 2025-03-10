/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** print une string
*/
#include "include/lib.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return 0;
}
