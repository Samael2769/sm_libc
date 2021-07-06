/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flag_char
*/

#include <stdarg.h>
#include "sm_libc.h"

char *flag_char(va_list list, char *to_print, char * flags)
{
    char c = va_arg(list, int);

    to_print = sm_realloc(to_print, sizeof(char) * sm_strlen(to_print) + 2,
    sizeof(char) * sm_strlen(to_print) + 1);
    to_print[sm_strlen(to_print)] = c;
    return to_print;
}

char *flag_string(va_list list, char *to_print, char *flags)
{
    char *str = va_arg(list, char *);
    int size = get_len(flags, sm_strlen(str));
    int len = 0;

    for (int i = 0; str[i] != '\0' && i != size; ++i) {
        len = sm_strlen(to_print);
        to_print = sm_realloc(to_print, (sm_strlen(to_print) + 2), (sm_strlen(to_print) + 1));
        to_print[len] = str[i];
        to_print[len + 1] = '\0';
    }
    return to_print;
}

static char *put_zeros(char *str)
{
    size_t len = sm_strlen(str);

    if (len > 2)
        return (sm_strconcat("\\", str));
    if (len > 1)
        return (sm_strconcat("\\0", str));
    return (sm_strconcat("\\00", str));
}

char *flag_specialstr(va_list list, char *to_print, char * flags)
{
    char *src = va_arg(list, char *);
    int size = get_len(flags, sm_strlen(src));
    int len = 0;

    for (int i = 0; src[i] != '\0' && i != size; ++i) {
        if (src[i] >= 33 && src[i] <= 126) {
            len = sm_strlen(to_print);
            to_print = sm_realloc(to_print, (sm_strlen(to_print) + 2), (sm_strlen(to_print) + 1));
            to_print[len] = src[i];
            to_print[len + 1] = '\0';
        } else {
            to_print = sm_strconcat(to_print, put_zeros(sm_convert_base(8, src[i], 1)));
        }
    }
    return (to_print);
}

char *flag_percent(va_list list, char *to_print, char * flags)
{
    char c = '%';
    
    list = list;
    to_print = sm_realloc(to_print, sizeof(char) * sm_strlen(to_print) + 2,
    sizeof(char) * sm_strlen(to_print) + 1);
    to_print[sm_strlen(to_print)] = c;
    return to_print;
}