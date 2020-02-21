#ifndef _INSTR_JTYPE_H_
#define _INSTR_JTYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

#include "isa/rv32i/opcode.h"
#include "isa/rv64i/opcode.h"

#include "instructionBase.h"
#include "processor/processor.h"

struct opcodeJhandler
{
    int funct3[7][10];
    void (*handler[7][10])(struct opcode_Jtype *);
};

void rv32i_jal(struct opcode_Jtype *);

#endif