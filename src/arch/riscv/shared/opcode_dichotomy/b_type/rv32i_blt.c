#include "shared/opcode_dichotomy/btype.h"
#include "processor/processor.h"

void rv32i_blt(struct opcode_Btype *extracted)
{
    uint off = instrBranch_getOffset(extracted);
    debug_log_instr("blt %s, %s, %d\n", getRegisterName(extracted->rs1), getRegisterName(extracted->rs2), off);
    if (registerGet(extracted->rs1) < registerGet(extracted->rs2))
        instrBranch_takeBranch(off);
}