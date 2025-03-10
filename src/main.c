/*
** EPITECH PROJECT, 2025
** main
** File description:
** my_sudo's main
*/

// ne pas demander le mdp quand user == root

#include "include/lib.h"
#include "include/printf.h"
#include "include/project.h"
#include "include/struct_sudo.h"
#include "error_handling/errors.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void h_func(void)
{
    my_printf("usage: ./my_sudo -h\n");
    my_printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
}

int main(int ac, char **av, char **env)
{
    linked_list_t *shadow_data;
    char *current_user;

    if (ac == 1)
        return 84;
    if (strcmp(av[1], "-h") == 0) {
        h_func();
        return 0;
    }
    shadow_data = load_shadow();
    current_user = who_use_it(env);
    if (!shadow_data || !current_user)
        return 84;
    if (verify_password(current_user, shadow_data) == 0) {
        if (ac > 1)
            elevate_privileges(&av[1]);
    } else
        return 84;
    return 0;
}
