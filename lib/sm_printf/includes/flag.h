/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flag
*/

#pragma once

#include <stdarg.h>

char *flag_char(va_list list, char *to_print);
char *flag_string(va_list list, char *to_print);
char *flag_int(va_list list, char *to_print);
char *flag_unint(va_list list, char *to_print);
char *flag_percent(va_list list, char *to_print);
char *flag_octal(va_list list, char *to_print);
char *flag_hexa_maj(va_list list, char *to_print);
char *flag_hexa(va_list list, char *to_print);
char *flag_specialstr(va_list list, char *to_print);
char *flag_pointer(va_list list, char *to_print);

char *preflag_hash(char *to_print, char *flags);