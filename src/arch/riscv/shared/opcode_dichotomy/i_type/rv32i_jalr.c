#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"

void rv32i_jalr(struct opcode_Itype *extracted)
{
    debug_log_instr("jalr %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    uint jmp = extracted->imm + registerGet(extracted->rs1);
    jmp &= ~1;
    registerSet(extracted->rd, jmp);
    processor_set_pc(jmp);
}