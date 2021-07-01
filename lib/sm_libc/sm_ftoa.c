/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sm_ftoa
*/

#include "sm_libc.h"
#include <stdlib.h>

char *sm_ftoa(float nb, int point)
{
    int len = sm_nbrlen((int)nb);
    char *number = malloc(sizeof(char));
    char *inb = sm_itoa((int)nb);
    float fpart = nb - (int)nb;

    number[0] = '\0';
    if (point != 0) {
        number = sm_strconcat(inb, ".");
        fpart = fpart * sm_pow(10, point);
        inb = sm_itoa((int)fpart);
    }
    number = sm_strconcat(number, inb);
    return number;
}