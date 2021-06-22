/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** preflag_plus
*/

#include "sm_libc.h"
#include <stdarg.h>

char *preflag_plus(char *to_print, char *flags)
{
    char c = flags[sm_strlen(flags) - 1];

    if (c == 'i' || c == 'd')
        return (sm_strconcat("+", to_print));
    return to_print;
}