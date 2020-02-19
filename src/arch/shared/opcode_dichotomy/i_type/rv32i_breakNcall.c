#include "shared/opcode_dichotomy/itype.h"
#include "syscall/syscall.h"

#include "processor/processor.h"

void rv32i_ecall(void)
{
    exec_syscall();
}

void rv32i_break(void) {}

void rv32i_callNbreak(struct opcode_Itype *extracted)
{
    if (extracted->imm == 0)
        rv32i_ecall();
    else if (extracted->imm == 1)
        rv32i_break();
    else
        RAISE(ERR_OPCODE_NUM);
}