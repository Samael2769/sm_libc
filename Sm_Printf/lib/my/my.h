/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <stddef.h>

void *sm_realloc(void *ptr, size_t size, size_t ptr_size);
int sm_find_char(char const *str, char c);
size_t sm_strlen(char *str);
char *sm_strcat(char *dest, char *src);

#endif /* !MY_H_ */
