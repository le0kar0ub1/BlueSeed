#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"

#define SHIFT_IMM_MASK(x) (x & ((1 << 5) - 1))

void rv32i_srai(struct opcode_Itype *extracted)
{
    debug_log_instr("srai %s, %s, %d", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    if ((int)registerGet(extracted->rs1) < 0)
        registerSet(extracted->rd, (((int)registerGet(extracted->rs1)) >> extracted->imm) * -1);
    else
        registerSet(extracted->rd, ((int)registerGet(extracted->rs1)) >> extracted->imm);
}
