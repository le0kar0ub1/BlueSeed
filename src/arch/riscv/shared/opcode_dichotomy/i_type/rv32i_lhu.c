#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"
#include "env/env.h"

void rv32i_lhu(struct opcode_Itype *extracted )
{
    uint16 *get = (uint16 *)virtToHost((void *)(uint64)extracted->imm);
    registerSetW(extracted->rd, get[0]);
}