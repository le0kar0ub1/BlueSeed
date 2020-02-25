#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"
#include "env/env.h"

void rv32i_lb(struct opcode_Itype *extracted)
{
    debug_log_instr("lb %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    int8 *get = (int8 *)virtToHost((void *)((int64)((int)extracted->imm + registerGet(extracted->rs1))));
    registerSetB(extracted->rd, *get);
}