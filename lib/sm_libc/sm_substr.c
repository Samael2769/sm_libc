/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_substr
*/

#include <stdlib.h>
#include "sm_libc.h"

char *sm_substr(char *str, int start, int end)
{
    if (str == NULL)
        return NULL;
    char *new = malloc(sizeof(char) * (end - start + 1));
    int i = 0;

    for (i = 0; start < end; start++, i++)
        new[i] = str[start];
    new[i] = '\0';
    return new;
}