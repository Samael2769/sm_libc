/*
** SAMAEL PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_list
*/

#include "sm_list.h"
#include <stdlib.h>
#include <stdio.h>

sm_list_t *create_first_node(void *data, type_t type)
{
    sm_list_t *node = malloc(sizeof(sm_list_t));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    node->head = node;
    node->type = type;
    return node;
}

void push_at_end(sm_list_t *sm_list, void *data, type_t type)
{
    sm_list_t *tmp = sm_list->head;
    sm_list_t *new = malloc(sizeof(sm_list_t));
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

void push_at_top(sm_list_t *sm_list, void *data, type_t type)
{
    sm_list_t *new = malloc(sizeof(sm_list_t));
    if (new == NULL)
        return;
    new->type = type;
    new->data = data;
    new->next = sm_list->head;
    sm_list->head->prev = new;
    new->prev = NULL;
    sm_list->head = new;
}

void push_at_place(sm_list_t *sm_list, void *data, type_t type, size_t place)
{
    if (place == 0) {
        push_at_top(sm_list, data, type);
        return;
    }
    sm_list_t *new = malloc(sizeof(type_t));
    sm_list_t *tmp = sm_list->head;
    for (size_t i = 0; i < place && tmp->next; ++i, tmp = tmp->next);
    if (!tmp->next)
        push_at_end(sm_list, data, type);
    else {
        new->data = data;
        new->type = type;
        tmp->prev->next = new;
        new->next = tmp;
        new->prev = tmp->prev;
        tmp->prev = new;
    }
}

void free_sm_list(sm_list_t *sm_list)
{
    for (sm_list_t *tmp = sm_list->head; tmp;) {
        free(sm_list->head);
        tmp = tmp->next;
        sm_list->head = tmp;
    }
}

void display_sm_liste(sm_list_t *sm_list)
{
    if (sm_list == NULL)
        return;
    for (sm_list_t *tmp = sm_list->head; tmp; tmp = tmp->next) {
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

void display_mem(sm_list_t *sm_list)
{
    if (sm_list == NULL)
        return;
    for (sm_list_t *tmp = sm_list->head; tmp; tmp = tmp->next) {
        printf("ptr = %p\nnext = %p\nprev = %p\n-------\n", tmp, tmp->next, tmp->prev);
    }
    printf("+++++++++++\n");
}

void pop_list(sm_list_t *sm_list)
{
    sm_list_t *tmp;
    if (sm_list == NULL)
        return;
    if (sm_list->next == NULL)
        return;
    for (tmp = sm_list; tmp->next->next != NULL; tmp = tmp->next);
    tmp->next = NULL;
}

void pop_head(sm_list_t **sm_list)
{
    sm_list_t* temp;

    temp = *sm_list;
    *sm_list = (*sm_list)->next;
    if ((*sm_list) == NULL)
        return;
    (*sm_list)->head = *sm_list;
    free(temp);
}

void pop_place(sm_list_t **sm_list, size_t size)
{
    if (size == 0) {
        pop_head(sm_list);
        return;
    }
    sm_list_t *tmp = *sm_list;
    for (int i = 0; i < size; i++)
        tmp = tmp->next;
    tmp->prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    free(tmp);
}

sm_list_t *get_node(sm_list_t *sm_list, size_t place)
{
    sm_list_t *tmp = sm_list;
    for (int i = 0; i < place; i++)
        tmp = tmp->next;
    return tmp;
}