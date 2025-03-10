/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** mettre mots d'une string dans tableau
*/
#include <stddef.h>

int isalnum(char c)
{
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}

int words_allocate(char **board, char *words)
{
    board = malloc(sizeof(char) * 2 + 1);
    if (board == NULL) {
        return NULL;
    }
    words = malloc(sizeof(char) * 3 + 1);
    if (words == NULL) {
        return NULL;
    }
    free(board);
    free(words);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    char **word;
}
