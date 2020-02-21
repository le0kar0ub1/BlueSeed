#ifndef _INSTR_STYPE_H_
#define _INSTR_STYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

#include "isa/rv32i/opcode.h"
#include "isa/rv64i/opcode.h"

#include "instructionBase.h"

struct opcodeShandler
{
    int funct3[8][10];
    void (*handler[8][10])(struct opcode_Stype *);
};

void rv32i_lb(struct opcode_Stype *);
void rv32i_lh(struct opcode_Stype *);
void rv32i_lw(struct opcode_Stype *);
void rv32i_lbu(struct opcode_Stype *);
void rv32i_lhu(struct opcode_Stype *);
void rv32i_addi(struct opcode_Stype *);

#endif