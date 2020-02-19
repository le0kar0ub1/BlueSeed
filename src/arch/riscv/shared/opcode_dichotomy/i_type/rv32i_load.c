#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"
#include "env/env.h"

void rv32i_lb(struct opcode_Itype *extracted)
{
    int8 *get = (int8 *)virtToHost((void *)(int64)extracted->imm);
    registerSetB(extracted->rd, get[0]);
}

void rv32i_lh(struct opcode_Itype *extracted)
{
    int16 *get = (int16 *)virtToHost((void *)(int64)extracted->imm);
    registerSetW(extracted->rd, get[0]);
}

void rv32i_lw(struct opcode_Itype *extracted)
{
    int32 *get = (int32 *)virtToHost((void *)(int64)extracted->imm);
    registerSetD(extracted->rd, get[0]);
}

void rv32i_lbu(struct opcode_Itype *extracted )
{
    uint8 *get = (uint8 *)virtToHost((void *)(uint64)extracted->imm);
    registerSetB(extracted->rd, get[0]);
}

void rv32i_lhu(struct opcode_Itype *extracted )
{
    uint16 *get = (uint16 *)virtToHost((void *)(uint64)extracted->imm);
    registerSetW(extracted->rd, get[0]);
}