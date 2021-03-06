#ifndef _PSEUDO_PSUDOTYPE_H_
#define _PSEUDO_PSUDOTYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

#include "isa/rv32i/opcode.h"
#include "isa/rv64i/opcode.h"

#include "instructionBase.h"
#include "shared/processor/processor.h"

struct opcodePseudohandler
{
    int opcode[10];
    void (*handler[10])(int);
};

#define PSEUDO_INSTR_RET 0x8082
#define PSEUDO_OPCODE_RET 0b0000010

void pseudo_ret(int);

#endif