/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** struct
*/

#pragma once
#include <stdarg.h>
#include "flag.h"

typedef struct flag_s {
    char flag;
    char * (*ptr)(va_list list, char * to_print);
} flag_t;

typedef struct preflag_s {
    char flag;
    char * (*ptr)(char * to_print, char *flags);
} preflag_t;

static const flag_t flag_fct_tab[] = {
    {.flag = 'c', flag_char},
    {.flag = 's', flag_string},
    {.flag = 'd', flag_int},
    {.flag = 'i', flag_int},
    {.flag = 'u', flag_unint},
    {.flag = '%', flag_percent},
    {.flag = 'o', flag_octal},
    {.flag = 'x', flag_hexa},
    {.flag = 'X', flag_hexa_maj},
    {.flag = 'S', flag_specialstr},
    {.flag = 'p', flag_pointer},
    {.flag = 'f', flag_float},
    //{.flag = 'n', },
};

static const preflag_t preflag_fct_tab[] = {
    {.flag = '#', preflag_hash},
    {.flag = '+', preflag_plus},
};

static const int pre_flag_size = sizeof(preflag_fct_tab) / sizeof(preflag_fct_tab[0]);

static const int flag_size = sizeof(flag_fct_tab) / sizeof(flag_fct_tab[0]);