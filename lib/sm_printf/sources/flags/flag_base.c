/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flag_base
*/

#include "sm_libc.h"
#include <stdarg.h>

char *flag_hexa(va_list list, char *to_print)
{
    int nb = va_arg(list, int);

    to_print = sm_convert_base(16, nb, 1);
    return (to_print);
}

char *flag_hexa_maj(va_list list, char *to_print)
{
    int nb = va_arg(list, int);

    to_print = sm_convert_base(16, nb, 0);
    return (to_print);
}

char *flag_octal(va_list list, char *to_print)
{
    int nb = va_arg(list, int);

    to_print = sm_convert_base(8, nb, 1);
    return (to_print);
}