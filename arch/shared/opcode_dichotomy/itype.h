#ifndef _ITYPE_H_
#define _ITYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

struct opcodeIhandler
{
    int funct3[50];
    void (*handler)(extractor32_t *);
};

#endif