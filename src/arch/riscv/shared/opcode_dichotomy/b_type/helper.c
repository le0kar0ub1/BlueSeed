#include "shared/opcode_dichotomy/btype.h"
#include "processor/processor.h"

int instrBranch_getOffset(struct opcode_Btype *op)
{
    int off = 0x0;

    /* YES, THE DOCUMENTATION IS DIRTY */
    off += (op->imm1);
    off += (op->imm2 << 5);
    off = off - (1 << 12) - 1;
    /* off += (op->imm1 & 0b00001) << 11;  */
    /* off += (op->imm1 & 0b11110) >> 1;   */
    /* off += (op->imm2 & 0b0111111) << 5; */
    /* off += (op->imm2 & 0b1000000) << 6; */
    return (off);
}