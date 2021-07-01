/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flag_float
*/

#include <stdarg.h>
#include "sm_libc.h"

char *flag_float(va_list list, char *to_print)
{
    float nb = va_arg(list, double);
    char *str = sm_ftoa(nb, 6);
    to_print = sm_strconcat(to_print, str);
    return to_print;
}