#ifndef _OPCODE_H_
#define _OPCODE_H_

#include "builtin.h"
#include "instructionBase.h"
#include "shared/runtime/extractor.h"

#define RISCV_INSTRUCTION_SIZE 0x4

#define RISCV_OPCODE_MASK(x) (x & ((1 << 7) - 1))

#define RISCV_OPCODE_TYPE_MAX 0x9

#define BTYPE_OPCODE_IDX  0x0
#define ITYPE_OPCODE_IDX  0x1
#define STYPE_OPCODE_IDX  0x2
#define RTYPE_OPCODE_IDX  0x3
#define UTYPE_OPCODE_IDX  0x4
#define JTYPE_OPCODE_IDX  0x5
#define R4TYPE_OPCODE_IDX 0x6
#define PSEUDO_OPCODE_IDX 0x7

struct opcodeHandler
{
    int opcode[RISCV_OPCODE_TYPE_MAX][50];
    void *(*handler[RISCV_OPCODE_TYPE_MAX])(extractor32_t *);
};

void *getHandlerFromOpcode(int);
void *getCompressedHandlerFromOpcode(int);
bool isOpcodeInIndex(uint, uint, uint);

#endif