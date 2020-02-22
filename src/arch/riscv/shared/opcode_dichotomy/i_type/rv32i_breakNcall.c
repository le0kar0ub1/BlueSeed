#include "shared/opcode_dichotomy/itype.h"
#include "syscall/syscall.h"

#include "shared/processor/processor.h"

void rv32i_ecall(void)
{
    debug_log_instr("ecall");
    exec_syscall();
}

void rv32i_ebreak(void)
{
    /* Generally used for debugging */
    debug_log_instr("ebreak");
}

void rv32i_callNbreak(struct opcode_Itype *extracted)
{
    if (extracted->imm == 0)
        rv32i_ecall();
    else if (extracted->imm == 1)
        rv32i_ebreak();
    else
        RAISE(ERR_OPCODE_NUM);
}