#include "shared/opcode_dichotomy/utype.h"
#include "def/macro.h"
#include "shared/processor/processor.h"
#include "shared/runtime/elftool.h"

void rv32i_lui(struct opcode_Utype *extracted)
{
    /* set absolute address */
    debug_log_instr("lui %s, %d", getRegisterName(extracted->rd), (uint64)extracted->imm);
    registerSet(extracted->rd , extracted->imm << 12);
}