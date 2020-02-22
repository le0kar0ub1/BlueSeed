#include "shared/opcode_dichotomy/jtype.h"
#include "shared/processor/processor.h"

void rv32i_jal(struct opcode_Jtype *extracted)
{
    int jmp = extracted->imm;
    debug_log_instr("jal %s, %d", getRegisterName(extracted->rd), jmp);
    if (jmp == 0)
        return;
    jmp =  (extracted->imm & 0b00000000000011111111) << 11;
    jmp += (extracted->imm & 0b00000000000100000000) << 2;
    jmp += (extracted->imm & 0b01111111111000000000) >> 9;
    jmp += (extracted->imm & 0b10000000000000000000) << 0;
    jmp = ((1 << 20) - jmp) * 2;
    jmp = processor_get_pc() - jmp;
    registerSet(extracted->rd, jmp);
    processor_set_pc(jmp);
}