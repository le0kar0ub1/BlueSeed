#ifndef _OPCODE_H_
#define _OPCODE_H_

#include "builtin.h"
#include "instructionBase.h"
#include "shared/runtime/extractor.h"

#define RISCV_INSTRUCTION_SIZE 0x4

#define RISCV_OPCODE_MASK(x) (x & ((1 << 7) - 1))

#define RISCV_OPCODE_TYPE_MAX 0x8

struct opcodeHandler
{
    int opcode[RISCV_OPCODE_TYPE_MAX][50];
    void (*handler[RISCV_OPCODE_TYPE_MAX])(extractor32_t *);
};

void *getHandlerFromOpcode(int);

#endif