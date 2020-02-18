#ifndef _MEMORYCONTROL_H
#define _MEMORYCONTROL_H

#include "error.h"
#include "stdlib.h"

static inline void *vmalloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
        RAISE(ERR_OUTOFMEM_NUM);
    return (ptr);
}

#endif