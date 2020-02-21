#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"
#include "env/env.h"

void rv32i_lw(struct opcode_Itype *extracted)
{
    int32 *get = (int32 *)virtToHost((void *)(int64)extracted->imm);
    registerSetD(extracted->rd, get[0]);
}