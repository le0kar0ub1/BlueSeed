#include "linked.h"
#include "string.h"
#include "stdint.h"
#include "macro.h"
#include "stdlib.h"

listnode_t *list_insert_back(list_t *list, void *item)
{
    listnode_t *new = vmalloc(sizeof(listnode_t));

    if (!list->head && !list->tail)
        return (list_init(list, new, item));
    new->prev = list->tail;
    new->item = item;
    new->next = NULL;
    list->tail = new;
    list->size++;
    return (new);
}

void list_remove_front(list_t *list)
{
    listnode_t *ls = list->head;

    if (!list->head)
        return;
    list->head = ls->next;
    if (list->head)
        list->head->prev = NULL;
    free(ls);
    list->size--;
}

void list_remove_back(list_t *list)
{
    listnode_t *ls = list->tail;

    if (!list->head)
        return;
    list->tail = ls->prev;
    if (list->tail)
        list->tail->next = NULL;
    free(ls);
    list->size--;
}

void list_remove_by_item(list_t *list, listnode_t *node)
{
    if (list->head == node)
        return (list_remove_front(list));
    else if (list->tail == node)
        return (list_remove_back(list));
    else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        list->size--;
        free(node);
    }
}

bool list_is_contain(list_t *list, void *item)
{
    for(listnode_t *node = list->head; node != NULL; node = node->next)
        if (node->item == item)
            return (true);
    return (false);
}