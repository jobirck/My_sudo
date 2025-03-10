/*
** EPITECH PROJECT, 2024
** include
** File description:
** include
*/
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#ifndef PROJECT_H
    #define PROJECT_H
    #define MAX_USERS 50
    #define MAX_LINE 512
    #define MAX_USER 256


typedef struct linked_list {
    char *user;
    char *id;
    char *salt;
    char *hash;
    struct linked_list *next;
} linked_list_t;

linked_list_t *load_shadow(void);

int is_user_sudo(char *user, char **user_tab);

void elevate_privileges(char **command);

int check_password_attempts(char *full_salt, char *correct_hash);

void debug_linked(linked_list_t *head);

void dash_h(int ac, char **av);

char *who_use_it(char **env);

void dash_g(char **env);

int verify_password(char const *user, linked_list_t *list);

void dash_u(char const *path);

void one_argument(void);

#endif
