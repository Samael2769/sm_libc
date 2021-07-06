/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** numbers
*/

#include "sm_libc.h"
#include "flag.h"
#include <stdlib.h>

int get_number(char *flag)
{
    char *number = malloc(sizeof(char));
    int i = 0;

    number[0] = '\0';
    for (int j = 0; flag[j] != '\0'; ++j) {
        if (flag[j] >= '0' && flag[j] <= '9' && flag[j - 1] != '.') {
            number = sm_realloc(number, sm_strlen(number) + 2, sm_strlen(number) + 1);
            number[i] = flag[j];
            ++i;
            number[i] = '\0';
        }
    }
    return (sm_atoi(number));
}

char *erase_number(char *flag)
{
    char *dup = malloc(sizeof(char) * sm_strlen(flag) + 1);
    int j = 0;

    for (int i = 0; flag[i] != '\0'; ++i) {
        if (flag[i] >= '0' && flag[i] <= '9' && check_first_zero(flag, i) != 0)
            continue;
        dup[j] = flag[i];
        ++j;
    }
    dup[j] = '\0';
    return dup;
}

void numbers(char **flag, char **to_print)
{
    int nb = get_number(*flag) - sm_strlen(*to_print);

    if (nb < 0)
        nb = 0;
    flag[0] = erase_number(*flag);
    to_print[0] = make_print(nb, *flag, *to_print);
}