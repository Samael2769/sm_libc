/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "sm_libc.h"

#define BLOCK 64

int sm_get_next_line(int fd, char **str)
{
    char buf[BLOCK + 1];
    buf[0] = '\0';
    int size = 0;
    char *dup = NULL;
    char *tmp = NULL;
    while (sm_find_char(buf, '\n') == -1 && (size = read(fd, buf, BLOCK)) > 0) {
        buf[size] = '\0';
        tmp = dup;
        dup = sm_strconcat(tmp, buf);
        free(tmp);
    }
    *str = sm_substr(dup, 0, sm_find_char(dup, '\n') + 1);
    free(dup);
    free(tmp);
    return 0;
}