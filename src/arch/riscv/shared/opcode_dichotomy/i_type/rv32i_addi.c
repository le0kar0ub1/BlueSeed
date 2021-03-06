#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"

void rv32i_addi(struct opcode_Itype *extracted)
{
    debug_log_instr("addi %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    registerSet(extracted->rd, registerGet(extracted->rs1) + extracted->imm);
}