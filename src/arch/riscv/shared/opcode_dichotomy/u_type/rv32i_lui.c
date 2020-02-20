#include "shared/opcode_dichotomy/utype.h"
#include "def/macro.h"
#include "processor/processor.h"
#include "shared/runtime/elftool.h"

void rv32i_lui(struct opcode_Utype *extracted)
{
    /* set absolute address */
    printf("lui\n");
    // getRegisterName(extracted->rd);
    // debug_log_instr("lui %s, %ld", getRegisterName(extracted->rd), (uint64)extracted->imm);
    // registerSet(extracted->rd , APPLY_AND_MASK(extracted->imm << 12, 12));
}