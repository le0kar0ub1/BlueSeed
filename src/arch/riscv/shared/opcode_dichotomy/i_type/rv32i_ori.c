#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"

void rv32i_ori(struct opcode_Itype *extracted)
{
    debug_log_instr("xori %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    registerSet(extracted->rd, registerGet(extracted->rs1) | extracted->imm);
}