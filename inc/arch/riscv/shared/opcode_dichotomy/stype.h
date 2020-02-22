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

void rv32i_sb(struct opcode_Stype *);
void rv32i_sh(struct opcode_Stype *);
void rv32i_sw(struct opcode_Stype *);

#endif