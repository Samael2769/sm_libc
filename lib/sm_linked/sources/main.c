/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "sm_list.h"

int main(int ac, char **av)
{
    sm_list_t *list = create_first_node(av[0], CHAR);
    for (int i = 1; i < ac; i++)
        push_at_end(list, av[i], CHAR);
    
    //display_list(list);
    pop_head(&list);
    display_mem(list);
    return 0;
}