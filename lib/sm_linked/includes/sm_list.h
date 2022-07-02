/*
** SAMAEL PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_list
*/

#ifndef sm_list_H_
#define sm_list_H_

#include <stddef.h>

typedef struct sm_list_s sm_list_t;

typedef enum type_e {INT, CHAR, FLOAT, STRUCT} type_t;

struct sm_list_s {
    void *data;
    type_t type;
    sm_list_t * head;
    sm_list_t * next;
    sm_list_t * prev;
};

void display_mem(sm_list_t *sm_list);
void display_list(sm_list_t *sm_list);
void free_sm_list(sm_list_t *sm_list);
sm_list_t *create_first_node(void *data, type_t type);
void push_at_end(sm_list_t *sm_list, void *data, type_t type);
void push_at_top(sm_list_t *sm_list, void *data, type_t type);
void push_at_place(sm_list_t *sm_list, void *data, type_t type, size_t place);
void pop_list(sm_list_t *sm_list);
void pop_head(sm_list_t **sm_list);
void pop_place(sm_list_t **sm_list, size_t place);
sm_list_t *get_node(sm_list_t *sm_list, size_t place);

#endif /* !sm_list_H_ */
