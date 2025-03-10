/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mysudo-joseph.birck
** File description:
** sudoers.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "include/project.h"

void elevate_privileges(char **command)
{
    if (setuid(0) != 0) {
        perror("Erreur : impossible d'obtenir les privilèges root");
        exit(84);
    }
    if (setgid(0) != 0) {
        perror("Erreur : impossible de changer de groupe");
        exit(84);
    }
    execvp(command[0], command);
    perror("Erreur lors de l'exécution de la commande");
    exit(84);
}
