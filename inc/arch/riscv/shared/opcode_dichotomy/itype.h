#ifndef _ITYPE_H_
#define _ITYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

#include "isa/rv32i/opcode.h"
#include "isa/rv64i/opcode.h"

#include "instructionBase.h"

struct opcodeIhandler
{
    int funct3[7][10];
    void (*handler[7][10])(struct opcode_Itype *);
};

void rv32i_lb(struct opcode_Itype *);
void rv32i_lh(struct opcode_Itype *);
void rv32i_lw(struct opcode_Itype *);
void rv32i_lbu(struct opcode_Itype *);
void rv32i_lhu(struct opcode_Itype *);
void rv32i_addi(struct opcode_Itype *);
void rv32i_slti(struct opcode_Itype *);
void rv32i_sltiu(struct opcode_Itype *);
void rv32i_xori(struct opcode_Itype *);
void rv32i_ori(struct opcode_Itype *);
void rv32i_andi(struct opcode_Itype *);
void rv32i_slli(struct opcode_Itype *);
void rv32i_srli(struct opcode_Itype *);
void rv32i_srai(struct opcode_Itype *);
void rv32i_fence(struct opcode_Itype *);
void rv32i_fenci(struct opcode_Itype *);
void rv32i_callNbreak(struct opcode_Itype *);
void rv32i_csrrw(struct opcode_Itype *);
void rv32i_csrrs(struct opcode_Itype *);
void rv32i_csrrc(struct opcode_Itype *);
void rv32i_csrrwi(struct opcode_Itype *);
void rv32i_csrrsi(struct opcode_Itype *);
void rv32i_csrrci(struct opcode_Itype *);

#endif