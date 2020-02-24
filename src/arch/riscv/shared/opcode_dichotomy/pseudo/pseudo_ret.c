#include "shared/opcode_dichotomy/pseudo.h"
#include "shared/processor/processor.h"
#include "shared/opcode_dichotomy/itype.h"

void pseudo_ret(int extracted __unused)
{
    struct opcode_Itype transfer;
    transfer.opcode = 0;
    transfer.rd = 0;
    transfer.funct3 = 0;
    transfer.rs1 = 1;
    transfer.imm = 0;
    rv32i_jalr(&transfer);
}