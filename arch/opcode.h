#ifndef _OPCODE_H_
#define _OPCODE_H_

#include "builtin.h"

struct opcodeHandler 
{
    int prefix[OPCODE_TYPE_MAX][50];
    void (*handler[OPCODE_TYPE_MAX])(uint);
};

#endif