/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flag_float
*/

#include <stdarg.h>
#include "sm_libc.h"
#include "usefull.h"

char *flag_float(va_list list, char *to_print, char * flags)
{
    float nb = va_arg(list, double);
    int size = get_len(flags, 6);
    char *str = sm_ftoa(nb, size);

    to_print = sm_strconcat(to_print, str);
    return to_print;
}