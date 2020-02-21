#include "shared/opcode_dichotomy/btype.h"
#include "processor/processor.h"

void rv32i_bltu(struct opcode_Btype *extracted)
{
    int off = instrBranch_getOffset(extracted);
    debug_log_instr("bltu %s, %s, %d", getRegisterName(extracted->rs1), getRegisterName(extracted->rs2), off);
    if (registerUGet(extracted->rs1) < registerUGet(extracted->rs2))
        instrBranch_takeBranch(off);
}