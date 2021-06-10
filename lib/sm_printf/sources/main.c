/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/
#include "sm_printf.h"
#include "sm_libc.h"
#include <stdlib.h>

//0 + # -
//digits
//flag

int main(int ac, char const * const av[])
{
    printf("test %p %X%o %c %%test2\n", "alpha", 10, 9, 'c');
    printf("=======================\n");
    sm_printf("test %p %X%o %c %%test2\n", "alpha", 10, 9, 'c');
    return 0;
}