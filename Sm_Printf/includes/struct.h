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
    char * (*flag_ptr)(va_list ap, char * to_print);
} flag_t;

typedef struct preflag_s {
    char flag;
    char * (*pre_flag_ptr)(char * to_print);
} preflag_t;

static const flag_t flag_fct_tab[] = {
    {.flag = 'c', flag_char},
    //{.flag = 's', },
    //{.flag = 'S', },
    //{.flag = 'd' || 'i', },
    //{.flag = 'o', },
    //{.flag = 'x', },
    //{.flag = 'X', },
    //{.flag = 'u', },
    //{.flag = 'f', },
    //{.flag = 'e', },
    //{.flag = 'E', },
    //{.flag = 'g', },
    //{.flag = 'G', },
    //{.flag = 'p', },
    //{.flag = 'n', },
    //{.flag = '%', },
};

static const preflag_t preflag_fct_tab[] = {
    //{.flag = '#', },
    //{.flag = '0', },
    //{.flag = '+', },
    //{.flag = '-', },
};

static const int pre_flag_size = sizeof(preflag_fct_tab) / sizeof(preflag_fct_tab[0]);

static const int flag_size = sizeof(flag_fct_tab) / sizeof(flag_fct_tab[0]);