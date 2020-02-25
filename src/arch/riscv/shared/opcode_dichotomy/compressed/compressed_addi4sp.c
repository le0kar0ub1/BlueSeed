#include "shared/opcode_dichotomy/compressed.h"
#include "shared/processor/processor.h"
#include "shared/opcode_dichotomy/itype.h"

void compressed_addi4sp(struct opcode_CIWtype *op)
{
    int imm = 0;
    imm += (op->imm & 0b00000001) << 3;
    imm += (op->imm & 0b00000010) << 1;
    imm += (op->imm & 0b00111100) << 4;
    imm += (op->imm & 0b11000000) >> 2;
    // imm *= 4;
    debug_log_instr("addi %s, sp, %x", getRegisterName(rvcRegisterToNorm(op->rd)), imm);
    registerSet(rvcRegisterToNorm(op->rd), processor_get_sp() + imm);
}