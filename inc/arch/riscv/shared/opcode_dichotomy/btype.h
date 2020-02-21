#ifndef _INSTR_BTYPE_H_
#define _INSTR_BTYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

#include "isa/rv32i/opcode.h"
#include "isa/rv64i/opcode.h"

#include "instructionBase.h"

struct opcodeBhandler
{
    int funct3[7][10];
    void (*handler[7][10])(struct opcode_Btype *);
};

void rv32i_beq(struct opcode_Btype *);
void rv32i_bne(struct opcode_Btype *);
void rv32i_blt(struct opcode_Btype *);
void rv32i_bge(struct opcode_Btype *);
void rv32i_bltu(struct opcode_Btype *);
void rv32i_bgeu(struct opcode_Btype *);

int instrBranch_getOffset(struct opcode_Btype *);
void instrBranch_takeBranch(int);

#endif