#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"

void rv32i_slti(struct opcode_Itype *extracted)
{
    debug_log_instr("slti %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    if ((int)registerGet(extracted->rs1) < (int)extracted->imm)
        registerSet(extracted->rd, 1);
    else
        registerSet(extracted->rd, 0);
}
