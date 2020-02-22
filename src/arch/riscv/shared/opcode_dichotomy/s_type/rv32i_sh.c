#include "shared/opcode_dichotomy/stype.h"
#include "processor/processor.h"
#include "env/env.h"

void rv32i_sh(struct opcode_Stype *extracted)
{
    int16 *store = (int16 *)(void *)(registerGet(extracted->rs1) + ((extracted->imm2 << 5) + extracted->imm1));
    *store = registerGetB(extracted->rs2);
}