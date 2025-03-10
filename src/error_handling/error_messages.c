/*
** EPITECH PROJECT, 2025
** error messages
** File description:
** sudo's messages when there is an error
*/
#include "../include/printf.h"

void one_argument(void)
{
    my_printf("usage: sudo -h | -K | -k | -V\n");
    my_printf("usage: sudo -v [-ABkNnS] [-g group] ");
    my_printf("[-h host] [-p prompt] [-u user]\n");
    my_printf("usage: sudo -l [-ABkNnS] [-g group] ");
    my_printf("[-h host] [-p prompt] [-U user]\n");
    my_printf("            [-u user] [command [arg ...]]\n");
    my_printf("usage: sudo [-ABbEHkNnPS] [-r role] ");
    my_printf("[-t type] [-C num] [-D directory]\n");
    my_printf("            [-g group] [-h host] [-");
    my_printf("p prompt] [-R directory] [-T timeout]\n");
    my_printf("            [-u user] [VAR=value] [");
    my_printf("-i | -s] [command [arg ...]]\n");
    my_printf("usage: sudo -e [-ABkNnS] [-r role] ");
    my_printf("[-t type] [-C num] [-D directory]\n");
    my_printf("            [-g group] [-h host] [");
    my_printf("-p prompt] [-R directory] [-T timeout]\n");
    my_printf("            [-u user] file ...\n");
}

void bad_password(void)
{
    my_printf("Sorry, try again.\n");
}

void three_bad_password(void)
{
    my_printf("sudo: 3 incorrect password attempts\n");
}
