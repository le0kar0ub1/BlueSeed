#include "shared/opcode_dichotomy/compressed.h"
#include "shared/processor/processor.h"
#include "shared/opcode_dichotomy/itype.h"

void compressed_ld(struct opcode_CLtype *op)
{
    int off = 0;
    off += op->imm1 << 6;
    off += op->imm2 << 3;
    debug_log_instr("ld %s, %x(%s)", getRegisterName(rvcRegisterToNorm(op->rd)), off, getRegisterName(rvcRegisterToNorm(op->rs1)));
    registerSet(rvcRegisterToNorm(op->rd), registerGet(rvcRegisterToNorm(op->rs1)));
}