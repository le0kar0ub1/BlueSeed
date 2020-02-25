#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"
#include "env/env.h"

void rv32i_lh(struct opcode_Itype *extracted )
{
    debug_log_instr("lh %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    int16 *get = (int16 *)virtToHost((void *)((int64)((int)extracted->imm + registerGet(extracted->rs1))));
    registerSetB(extracted->rd, get[0]);
}