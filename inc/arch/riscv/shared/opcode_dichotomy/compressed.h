#ifndef _INSTR_PSUDOTYPE_H_
#define _INSTR_PSUDOTYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

#include "compressedInstructionBase.h"
#include "shared/processor/processor.h"

struct opcodeCompressedHandler
{
    int opcode[10];
    void (*handler[10])(int);
};

#endif