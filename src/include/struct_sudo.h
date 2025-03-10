/*
** EPITECH PROJECT, 2025
** struct my_sudo
** File description:
** function table pointers
*/
#ifndef STRUCT_SUDO_H
    #define STRUCT_SUDO_H

typedef struct {
    char flags;
    void (*dash)(char const *path);
} dash_t;

#endif /* !STRUCT_SUDO_H */
