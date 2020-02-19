#include "shared/opcode_dichotomy/utype.h"
#include "def/macro.h"
#include "processor/processor.h"

void rv32i_lui(struct opcode_Utype *extracted)
{
    /* set absolute address */
    registerSet(extracted->rd , APPLY_AND_MASK(extracted->imm << 12, 12));
}