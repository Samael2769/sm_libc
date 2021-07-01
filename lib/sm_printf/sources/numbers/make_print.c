/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** make_print
*/

#include "flag.h"
#include "sm_libc.h"
#include <stdlib.h>

char *make_print(int times, char *flag, char *to_print)
{
    char *to_add = malloc(sizeof(char) * times + 1);

    if (check_zero(flag) == 0 && check_minus(flag) != 0)
        to_add = sm_memset(to_add, '0', times);
    else
        to_add = sm_memset(to_add, ' ', times);
    to_add[times] = '\0';
    if (check_minus(flag) == 0)
        to_print = sm_strconcat(to_print, to_add);
    else
        to_print = sm_strconcat(to_add, to_print);
    return to_print;
}