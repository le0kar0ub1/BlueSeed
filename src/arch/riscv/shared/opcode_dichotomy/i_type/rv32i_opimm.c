#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"

void rv32i_addi(struct opcode_Itype *extracted __unused)
{
    registerSet(extracted->rd, extracted->rs1 + extracted->imm);
}

void rv32i_slti(struct opcode_Itype *extracted __unused)
{

}

void rv32i_sltiu(struct opcode_Itype *extracted __unused)
{

}

void rv32i_xori(struct opcode_Itype *extracted __unused)
{

}

void rv32i_ori(struct opcode_Itype *extracted __unused)
{

}

void rv32i_andi(struct opcode_Itype *extracted __unused)
{


}