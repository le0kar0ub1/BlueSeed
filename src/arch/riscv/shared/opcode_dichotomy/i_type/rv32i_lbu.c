#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"
#include "env/env.h"

void rv32i_lbu(struct opcode_Itype *extracted )
{
    uint8 *get = (uint8 *)virtToHost((void *)((uint64)((int)extracted->imm + registerGet(extracted->rs1))));
    registerSetB(extracted->rd, *get);
}