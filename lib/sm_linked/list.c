/*
** SAMAEL PROJECT, 2022
** Untitled (Workspace)
** File description:
** list
*/

#include "list.h"
#include <stdlib.h>

list_t *create_first_node(void *data, type_t type)
{
    list_t *node = malloc(sizeof(list_t));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    node->head = node;
    node->type = type;
    return node;
}

void push_at_end(list_t *list, void *data, type_t type)
{
    list_t *tmp = list->head;
    list_t *new = malloc(sizeof(list_t));
    if (!new)
        return;
    for (; tmp->next; tmp = tmp->next);
    if (tmp) {
        tmp->next = new;
        new->data = data;
        new->next = NULL;
        new->prev = tmp;
        new->type = type;
    }
}

void push_at_top(list_t *list, void *data, type_t type)
{
    list_t *new = malloc(sizeof(list_t));
    if (new == NULL)
        return;
    new->type = type;
    new->data = data;
    new->next = list->head;
    list->head->prev = new;
    new->prev = NULL;
    list->head = new;
}

void push_at_place(list_t *list, void *data, type_t type, size_t place)
{
    if (place == 0) {
        push_at_top(list, data, type);
        return;
    }
    list_t *new = malloc(sizeof(type_t));
    list_t *tmp = list->head;
    for (size_t i = 0; i < place && tmp->next; ++i, tmp = tmp->next);
    if (!tmp->next)
        push_at_end(list, data, type);
    else {
        new->data = data;
        new->type = type;
        tmp->prev->next = new;
        new->next = tmp;
        new->prev = tmp->prev;
        tmp->prev = new;
    }
}

void free_list(list_t *list)
{
    for (list_t *tmp = list->head; tmp;) {
        free(list->head);
        tmp = tmp->next;
        list->head = tmp;
    }
}

void display_liste(list_t *list)
{
    for (list_t *tmp = list->head; tmp; tmp = tmp->next) {
        switch (tmp->type) {
            case INT:
                printf("%d\n", *(int *)tmp->data);
                break;
            case CHAR:
                printf("%s\n", (char *)tmp->data);
                break;
            case FLOAT:
                printf("%f\n", *(float *)tmp->data);
                break;
            default:
                printf("%p\n", tmp->data);
                break;
        }
    }
}

void display_mem(list_t *list)
{
    for (list_t *tmp = list->head; tmp; tmp = tmp->next) {
        printf("ptr = %p\nnext = %p\nprev = %p\n-------\n", tmp, tmp->next, tmp->prev);
    }
    printf("+++++++++++\n");
}