#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"
#include "env/env.h"

void rv64i_ld(struct opcode_Itype *extracted)
{
    debug_log_instr("ld %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    int64 *get = (int64 *)virtToHost((void *)((int64)((int)extracted->imm + registerGet(extracted->rs1))));
    registerSet(extracted->rd, *get);
}