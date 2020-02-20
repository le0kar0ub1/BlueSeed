#include "shared/opcode_dichotomy/utype.h"
#include "def/macro.h"
#include "processor/processor.h"
#include "env/env.h"

#include "runtime/elftool.h"

extern struct env *environnement;

void rv32i_auipc(struct opcode_Utype *extracted)
{
    /* set adress PC relative */
    debug_log_instr("auipc %s, %d", getRegisterName(extracted->rd), (uint64)extracted->imm);
    uint set = (uint64)processor_get_pc();
    // set = set + APPLY_AND_MASK(extracted->imm << 12, 12);
    set += extracted->imm << 12;
    set -= 4; /* we are already at next instruction */
    registerSet(extracted->rd , set);
}