#include "shared/opcode_dichotomy/utype.h"
#include "def/macro.h"
#include "processor/processor.h"

void rv32i_auipc(struct opcode_Utype *extracted)
{
    /* set adress PC relative */
    uint64 set = (uint64)processor_get_pc();
    set = set + APPLY_AND_MASK(extracted->imm << 12, 12);
    registerSet(extracted->rd , set);
}