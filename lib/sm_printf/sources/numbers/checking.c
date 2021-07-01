/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** checking
*/

#include "sm_libc.h"

int check_first_zero(char *flag, int i)
{
    if (flag[i] == '0') {
        if (i - 1 <= 0)
            return 0;
        if (flag[i - 1] >= '0' && flag[i - 1] <= '9')
            return 1;
        else
            return 0;
    }
    return -1;
}

int check_minus(char *flag)
{
    if (sm_find_char(flag, '-') >= 0)
        return 0;
    return -1;
}

int check_zero(char *flag)
{
    for (int i = 0; flag[i]; ++i) {
        if (flag[i] == '0' && check_first_zero(flag, i) == 0) {
            return 0;
        }
    }
    return -1;
}