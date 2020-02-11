#include "linked.h"
#include "string.h"
#include "stdint.h"
#include "macro.h"
#include "stdlib.h"

list_t *list_generate(void)
{
    list_t *list = vmalloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0x0;
    return (list);
}

listnode_t *list_init(list_t *list, listnode_t *new, void *item)
{
    list->head = new;
    list->tail = new;
    list->size++;
    new->prev = NULL;
    new->item = item;
    new->next = NULL;
    return (new);
}

uint64 list_size(list_t *list)
{
    if (!list)
        return (0);
    return (list->size);
}

listnode_t *list_insert_front(list_t *list, void *item)
{
    listnode_t *new = vmalloc(sizeof(listnode_t));

    if (!list->head && !list->tail)
        return (list_init(list, new, item));
    new->next = list->head;
    new->item = item;
    new->prev = NULL;
    list->head = new;
    list->size++;
    return (new);
}
