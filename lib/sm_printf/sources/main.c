/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/
#include "sm_printf.h"
#include "sm_libc.h"

//0 + # -
//digits
//flag

int main(int ac, char const * const av[])
{
    printf("test %s %c %c test2\n", "alpha", 'b', 'c');
    printf("=======================\n");
    sm_printf("test %s %c %c test2\n", "alpha", 'b', 'c');
    return 0;
}