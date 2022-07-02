/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flag_int
*/

#include <stdarg.h>
#include "sm_libc.h"

char *flag_int(va_sm_list sm_list, char *to_print, char * flags)
{
    int nb = va_arg(sm_list, int);
    to_print = sm_strconcat(to_print, sm_itoa(nb));
    return (to_print);
}

char *flag_unint(va_sm_list sm_list, char *to_print, char * flags)
{
    unsigned int nb = va_arg(sm_list, unsigned int);
    to_print = sm_strconcat(to_print, sm_itoa(nb));
    return (to_print);
}

char *flag_pointer(va_sm_list sm_list, char *to_print, char * flags)
{
    unsigned nb = va_arg(sm_list, long unsigned int);

    char *adress = sm_strconcat("0x", sm_convert_base(16, nb, 1));
    return sm_strconcat(to_print, adress);
}