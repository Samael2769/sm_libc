/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my
*/

#ifndef SM_LIBC_H_
#define SM_LIBC_H_
#include <stddef.h>

void *sm_realloc(void *ptr, size_t size, size_t ptr_size);
int sm_find_char(char const *str, char c);
size_t sm_strlen(char const *str);
char *sm_strcat(char *dest, char const *src);
char *sm_strconcat(char *dest, char const *src);
char *sm_itoa(int nb);
int sm_nbrlen(int nb);
void *sm_calloc(size_t nmemb, size_t size);
void *sm_memset(void * ptr, int c, size_t size);
void sm_revstr(char *str);
char *sm_convert_base(int base, int nbr, int type);

#endif /* !SM_LIBC_H_ */
