#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"
#include "env/env.h"

void rv32i_lbu(struct opcode_Itype *extracted )
{
    debug_log_instr("lbu %s, %s, %u", getRegisterName(extracted->rd), getRegisterName(extracted->rs1), extracted->imm);
    uint8 *get = (uint8 *)virtToHost((void *)((uint64)((int)extracted->imm + registerGet(extracted->rs1))));
    registerSetB(extracted->rd, *get);
}