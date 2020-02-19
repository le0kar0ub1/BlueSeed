#include "shared/opcode_dichotomy/itype.h"
#include "processor/processor.h"

void rv32i_addi(struct opcode_Itype *extracted)
{
    registerSet(extracted->rd, extracted->rs1 + extracted->imm);
}

void rv32i_slti(struct opcode_Itype *extracted)
{
    if ((int)registerGet(extracted->rs1) < (int)extracted->imm)
        registerSet(extracted->rd, 1);
    else
        registerSet(extracted->rd, 0);
}

void rv32i_sltiu(struct opcode_Itype *extracted)
{
    if ((uint)registerGet(extracted->rs1) < (uint)extracted->imm)
        registerSet(extracted->rd, 1);
    else
        registerSet(extracted->rd, 0);
}

void rv32i_xori(struct opcode_Itype *extracted)
{
    registerSet(extracted->rd, registerGet(extracted->rs1) ^ extracted->imm);
}

void rv32i_ori(struct opcode_Itype *extracted)
{
    registerSet(extracted->rd, registerGet(extracted->rs1) | extracted->imm);
}

void rv32i_andi(struct opcode_Itype *extracted)
{
    registerSet(extracted->rd, registerGet(extracted->rs1) & extracted->imm);
}