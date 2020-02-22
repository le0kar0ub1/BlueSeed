#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"
#include "env/env.h"

void rv32i_lb(struct opcode_Itype *extracted)
{
    int8 *get = (int8 *)virtToHost((void *)((int64)((int)extracted->imm + registerGet(extracted->rs1))));
    registerSetB(extracted->rd, *get);
}