#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"

void rv32i_addi(struct opcode_Itype *extracted)
{
    debug_log_instr("addi %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    registerSet(extracted->rd, extracted->rs1 + extracted->imm);
}