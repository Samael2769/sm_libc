/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** get_len
*/

#include "sm_libc.h"

int get_len(char *flag, int normal_size)
{
    int i = sm_find_char(flag, '.');
    int size = 0;

    if (i == -1)
        return normal_size;
    size = sm_atoi(flag + i + 1);
    return size;
}