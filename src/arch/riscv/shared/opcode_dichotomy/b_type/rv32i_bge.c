#include "shared/opcode_dichotomy/btype.h"
#include "processor/processor.h"

void rv32i_bge(struct opcode_Btype *extracted)
{
    int off = instrBranch_getOffset(extracted);
    debug_log_instr("bge %s, %s, 0x%x", getRegisterName(extracted->rs1), getRegisterName(extracted->rs2), instrBranch_getOffBranch(off));
    if (registerGet(extracted->rs1) >= registerGet(extracted->rs2))
        instrBranch_takeBranch(off);
}