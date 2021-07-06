/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flag
*/

#pragma once

#include <stdarg.h>

char *flag_char(va_list list, char *to_print, char * flags);
char *flag_string(va_list list, char *to_print, char * flags);
char *flag_int(va_list list, char *to_print, char * flags);
char *flag_unint(va_list list, char *to_print, char * flags);
char *flag_percent(va_list list, char *to_print, char * flags);
char *flag_octal(va_list list, char *to_print, char * flags);
char *flag_hexa_maj(va_list list, char *to_print, char * flags);
char *flag_hexa(va_list list, char *to_print, char * flags);
char *flag_specialstr(va_list list, char *to_print, char * flags);
char *flag_pointer(va_list list, char *to_print, char * flags);
char *flag_float(va_list list, char *to_print, char * flags);

char *preflag_hash(char *to_print, char *flags);
char *preflag_plus(char *to_print, char *flags);

void numbers(char **flag, char **to_print);
int check_zero(char *flag);
int check_minus(char *flag);
int check_first_zero(char *flag, int i);
char *make_print(int times, char *flag, char *to_print);