#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"
#include "env/env.h"

void rv32i_lw(struct opcode_Itype *extracted )
{
    debug_log_instr("lw %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    int32 *get = (int32 *)virtToHost((void *)((uint64)((int)extracted->imm + registerGet(extracted->rs1))));
    registerSetB(extracted->rd, *get);
}