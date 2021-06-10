/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sm_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "sm_libc.h"
#include "struct.h"

static void check_flag(char *flag, va_list list)
{
    char *to_print = malloc(sizeof(char) * 1);
    to_print[0] = '\0';

    for (int i = 0; flag[i]; ++i) {
        for (int j = 0; j < flag_size; ++j) {
            if (flag[i] == flag_fct_tab[j].flag) {
                to_print = flag_fct_tab[j].flag_ptr(list, to_print);
            }
        }
    }
    write(1, to_print, sm_strlen(to_print));
}

static char *get_flag(char *str, int *index)
{
    char *flags = "csSdioxXufeEgGpn%";
    char *str_flag = malloc(sizeof(char) * 2);
    int i = *index;
    int o;

    for (o = 0; str[i] != '\0' && sm_find_char(flags, str[i]) == (-1);
    ++i, ++o) {
        str_flag[o] = str[i];
        str_flag[o + 1] = '\0';
        str_flag = sm_realloc(str_flag, sizeof(char) *
        (sm_strlen(str_flag) + 2), sizeof(char) * (sm_strlen(str_flag) + 1));
    }
    str_flag[o] = str[i];
    str_flag[o + 1]= '\0';
    str_flag = sm_realloc(str_flag, sizeof(char) *
    (sm_strlen(str_flag) + 2), sizeof(char) * (sm_strlen(str_flag) + 1));
    i++;
    *index = i;
    return str_flag;
}

void sm_printf(char *str, ...)
{
    va_list list;
    char *flag = NULL;

    if (str == NULL)
        return;
    va_start(list, str);
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '%') {
            i++;
            flag = get_flag(str, &i);
            check_flag(flag, list);
        }
        write(1, &str[i], 1);
    }
    va_end(list);
}