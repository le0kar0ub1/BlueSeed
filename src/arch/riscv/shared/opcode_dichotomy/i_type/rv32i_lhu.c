#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"
#include "env/env.h"

void rv32i_lhu(struct opcode_Itype *extracted )
{
    uint16 *get = (uint16 *)virtToHost((void *)((uint64)((int)extracted->imm + registerGet(extracted->rs1))));
    registerSetB(extracted->rd, *get);
}