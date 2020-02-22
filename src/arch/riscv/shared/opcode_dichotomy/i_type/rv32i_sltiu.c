#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"

void rv32i_sltiu(struct opcode_Itype *extracted)
{
    debug_log_instr("sltiu %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    if ((uint)registerGet(extracted->rs1) < (uint)extracted->imm)
        registerSet(extracted->rd, 1);
    else
        registerSet(extracted->rd, 0);
}