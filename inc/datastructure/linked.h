#ifndef _LINKED_H_
#define _LINKED_H_

#include "keyword.h"
#include "typedef.h"
#include "stdbool.h"

struct listnode {
    struct listnode *prev;
    struct listnode *next;
    void            *item;
} __packed;

typedef struct listnode listnode_t;

struct list {
    listnode_t *head;
    listnode_t *tail;
    uint64     size;
} __packed;

typedef struct list list_t;

bool list_is_contain(list_t *list, void *item);
void list_remove_by_item(list_t *list, listnode_t *node);
void list_remove_back(list_t *list);
void list_remove_front(list_t *list);
listnode_t *list_insert_back(list_t *list, void *item);
listnode_t *list_insert_front(list_t *list, void *item);
uint64 list_size(list_t *list);
listnode_t *list_init(list_t *list, listnode_t *new, void *item);
list_t *list_generate(void);

#endif