#include "shared/opcode_dichotomy/stype.h"
#include "shared/processor/processor.h"
#include "env/env.h"

void rv32i_sw(struct opcode_Stype *extracted)
{
    int32 *store = (int32 *)(void *)(registerGet(extracted->rs1) + ((extracted->imm2 << 5) + extracted->imm1));
    *store = registerGetB(extracted->rs2);
}