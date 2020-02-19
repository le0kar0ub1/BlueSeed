#ifndef _INSTR_ITYPE_H_
#define _INSTR_ITYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

#include "isa/rv32i/opcode.h"
#include "isa/rv64i/opcode.h"

#include "instructionBase.h"

struct opcodeUhandler
{
    int opcode[7][10];
    void (*handler[7][10])(struct opcode_Utype *);
};

void rv32i_lui(struct opcode_Utype *);
void rv32i_auipc(struct opcode_Utype *);

#endif