/*
** EPITECH PROJECT, 2024
** structid.h
** File description:
** struct tableur printf
*/
#include <stdarg.h>
#ifndef STRUCTID_H
    #define STRUCTID_H

typedef struct {
    char symbol;
    int (*handler)(va_list ap);
} format_t;

#endif
