/*
** SAMAEL PROJECT, 2022
** Untitled (Workspace)
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct list_s list_t;

typedef enum type_e {INT, CHAR, FLOAT, STRUCT} type_t;

struct list_s {
    void *data;
    type_t type;
    list_t * head;
    list_t * next;
    list_t * prev;
};

void display_mem(list_t *list);
void display_liste(list_t *list);
void free_list(list_t *list);
list_t *create_first_node(void *data, type_t type);
void push_at_end(list_t *list, void *data, type_t type);
void push_at_top(list_t *list, void *data, type_t type);
void push_at_place(list_t *list, void *data, type_t type, size_t place);

#endif /* !LIST_H_ */
