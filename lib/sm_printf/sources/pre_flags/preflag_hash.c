/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** preflag_hash
*/

#include <stdarg.h>
#include "sm_libc.h"

char *preflag_hash(char *to_print, char *flags)
{
    char c = flags[sm_strlen(flags) - 1];

    if (c == 'x')
        return (sm_strconcat("0x", to_print));
    if (c == 'X')
        return (sm_strconcat("0X", to_print));
    if (c == 'o')
        return (sm_strconcat("0", to_print));
    return to_print;
}