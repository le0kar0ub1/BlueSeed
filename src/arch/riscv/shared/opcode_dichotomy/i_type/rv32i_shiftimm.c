#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"

#define SHIFT_IMM_MASK(x) (x & ((1 << 5) - 1))

void rv32i_slli(struct opcode_Itype *extracted)
{
    registerSet(extracted->rd, ((int)registerGet(extracted->rs1)) << SHIFT_IMM_MASK(extracted->imm));
}

void rv32i_srli(struct opcode_Itype *extracted)
{
    registerSet(extracted->rd, ((int)registerGet(extracted->rs1)) >> SHIFT_IMM_MASK(extracted->imm));
}

void rv32i_srai(struct opcode_Itype *extracted)
{
    if ((int)registerGet(extracted->rs1) < 0)
        registerSet(extracted->rd, (((int)registerGet(extracted->rs1)) >> extracted->imm) * -1);
    else
        registerSet(extracted->rd, ((int)registerGet(extracted->rs1)) >> extracted->imm);
}
