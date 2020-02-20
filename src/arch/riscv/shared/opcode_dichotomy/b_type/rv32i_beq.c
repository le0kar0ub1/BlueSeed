#include "shared/opcode_dichotomy/btype.h"
#include "processor/processor.h"

void rv32i_beq(struct opcode_Btype *extracted)
{
    printf("VALUES: %d %d\n", extracted->imm2, extracted->imm1);
    int64 off = instrBranch_getOffset(extracted);
    printf("OFF: %lx \n", off);
    printf("FINAL: %lxd\n", off + (processor_get_pc()));
    exit(0);
    debug_log_instr("beq %s, %s, %d\n", getRegisterName(extracted->rs1), getRegisterName(extracted->rs2), off);
    if (registerGet(extracted->rs1) == registerGet(extracted->rs2))
        instrBranch_takeBranch(off);
}