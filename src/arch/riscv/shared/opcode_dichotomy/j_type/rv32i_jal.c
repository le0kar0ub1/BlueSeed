#include "shared/opcode_dichotomy/jtype.h"
#include "shared/processor/processor.h"

void rv32i_jal(struct opcode_Jtype *extracted)
{
    int jmp = 0;
    if (extracted->imm == 0)
        goto jal_nojmp;
    jmp += (extracted->imm & 0b00000000000011111111) << 11;
    jmp += (extracted->imm & 0b00000000000100000000) << 2;
    jmp += (extracted->imm & 0b01111111111000000000) >> 9;
    jmp += (extracted->imm & 0b10000000000000000000);
    jmp <<= 1;
    if (extracted->imm < 0)
        jmp -= 2 << 20;
    jal_nojmp:
    jmp = (processor_get_pc() - 4) + jmp;
    debug_log_instr("jal %s, %x", getRegisterName(extracted->rd), jmp);
    registerSet(extracted->rd, processor_get_pc());
    processor_set_pc(jmp);
}