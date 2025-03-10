/*
** EPITECH PROJECT, 2025
** sudo basics
** File description:
** filepath etc
*/

#include "include/lib.h"
#include "include/printf.h"
#include "error_handling/errors.h"
#include "include/project.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <crypt.h>

void free_list(linked_list_t *head)
{
    linked_list_t *current = head;
    linked_list_t *next;

    while (current) {
        next = current->next;
        free(current->user);
        free(current->id);
        free(current->salt);
        free(current->hash);
        free(current);
        current = next;
    }
}

linked_list_t *add_node(const char *user, const char *id,
    const char *salt, const char *hash)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (!node)
        return NULL;
    node->user = strdup(user);
    node->id = strdup(id);
    node->salt = strdup(salt);
    node->hash = strdup(hash);
    node->next = NULL;
    return node;
}

linked_list_t *parse_shadow_line(const char *line)
{
    char user[50];
    char full_hash[300];

    if (sscanf(line, "%[^:]:%[^:]", user, full_hash) != 2)
        return NULL;
    return add_node(user, "", "", full_hash);
}

FILE *open_shadow_file(void)
{
    FILE *file = fopen("/etc/shadow", "r");

    if (!file)
        perror("Erreur : Impossible d'ouvrir /etc/shadow");
    return file;
}

linked_list_t *load_shadow(void)
{
    FILE *file = open_shadow_file();
    linked_list_t *head = NULL;
    linked_list_t *tail = NULL;
    char line[512];
    linked_list_t *node;

    if (!file)
        return NULL;
    while (fgets(line, sizeof(line), file)) {
        node = parse_shadow_line(line);
        if (!node)
            continue;
        if (!head)
            head = node;
        else
            tail->next = node;
        tail = node;
    }
    fclose(file);
    return head;
}
