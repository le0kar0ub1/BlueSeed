#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"
#include "env/env.h"

void rv32i_lh(struct opcode_Itype *extracted)
{
    int16 *get = (int16 *)virtToHost((void *)(int64)extracted->imm);
    registerSetW(extracted->rd, get[0]);
}