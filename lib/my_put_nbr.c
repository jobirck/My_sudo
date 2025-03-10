/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** print nbr
*/
#include "include/lib.h"

int my_put_nbr(int nb)
{
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}
