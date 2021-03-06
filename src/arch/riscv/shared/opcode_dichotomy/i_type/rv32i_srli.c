#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"

#define SHIFT_IMM_MASK(x) (x & ((1 << 5) - 1))

void rv32i_srli(struct opcode_Itype *extracted)
{
    debug_log_instr("srli %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    registerSet(extracted->rd, ((int)registerGet(extracted->rs1)) >> SHIFT_IMM_MASK(extracted->imm));
}