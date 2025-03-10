/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mysudo-joseph.birck
** File description:
** password.c
*/
#include "include/project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <crypt.h>

char *who_use_it(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], "SUDO_USER=", 10) == 0)
            return strdup(env[i] + 10);
    }
    printf("No user found\n");
    return NULL;
}

static void get_password(char *buffer, size_t size)
{
    struct termios oldt;
    struct termios newt;

    printf("[my_sudo] password: ");
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    if (!fgets(buffer, size, stdin))
        buffer[0] = '\0';
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
    if (buffer[0] && buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';
}

static linked_list_t *find_user(linked_list_t *list, char const *user)
{
    while (list) {
        if (strcmp(list->user, user) == 0)
            return list;
        list = list->next;
    }
    printf("User %s not found in the list\n", user);
    return NULL;
}

static int check_password(char *password, linked_list_t *user)
{
    char *hash = crypt(password, user->hash);

    return hash && strcmp(hash, user->hash) == 0;
}

static int attempt_password_verification(linked_list_t *user_node)
{
    char password[256];

    for (int i = 0; i < 3; i++) {
        get_password(password, sizeof(password));
        if (check_password(password, user_node))
            return 0;
        printf("Sorry, Try again.\n");
    }
    printf("sudo: 3 incorrect password attempts\n");
    return 84;
}

int verify_password(char const *user, linked_list_t *list)
{
    linked_list_t *user_node = find_user(list, user);
    int result = 0;

    if (strcmp(user, "root") == 0)
        return 0;
    if (!user_node)
        return 2;
    result = attempt_password_verification(user_node);
    return result;
}
