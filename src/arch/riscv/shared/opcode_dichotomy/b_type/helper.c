#include "shared/opcode_dichotomy/btype.h"
#include "processor/processor.h"

int64 instrBranch_getOffset(struct opcode_Btype *op)
{
    int64 off = 0;

    off += (op->imm1 & 0b00001) << 11;
    off += (op->imm1 & 0b11110) >> 1;

    off += (op->imm2 & 0b0111111) << 5;
    off += (op->imm2 & 0b1000000) << 6;
    return (off);
}

void instrBranch_takeBranch(int64 off)
{
    processor_set_pc(processor_get_pc() + off);
}
