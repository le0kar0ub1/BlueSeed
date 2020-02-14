#ifndef _OPCODE_H_
#define _OPCODE_H_

#include "builtin.h"
#include "math.h"

#define END_SCD_OPCODE -1

struct opcodeHandler 
{
    int opscd[50];
    void (*handler[50])(uint);
};

struct opcodePrefix
{
    uint8 const prefix[50];
    struct opcodeHandler op[50];
};

/* SB type */
#define BEQ_MASK                    "0b?????????????????000?????1100011"
#define BNE_MASK                    "0b?????????????????001?????1100011"
#define BLT_MASK                    "0b?????????????????100?????1100011"
#define BGE_MASK                    "0b?????????????????101?????1100011"
#define BLTU_MASK                   "0b?????????????????110?????1100011"
#define BGEU_MASK                   "0b?????????????????111?????1100011"

/* I type */
#define JALR_MASK                   "0b?????????????????000?????1100111"

/* UJ type */
#define JAL_MASK                    "0b?????????????????????????1101111"

/* U type */
#define LUI_MASK                    "0b?????????????????????????0110111"

/* U type */
#define AUIPC_MASK                  "0b?????????????????????????0010111"

/* S type */
#define ADDI_MASK                   "0b?????????????????000?????0010011"
#define SLTI_MASK                   "0b?????????????????010?????0010011"
#define SLTIU_MASK                  "0b?????????????????011?????0010011"
#define XORI_MASK                   "0b?????????????????100?????0010011"
#define ORI_MASK                    "0b?????????????????110?????0010011"
#define ANDI_MASK                   "0b?????????????????111?????0010011"

/* R type */
#define SLLI_MASK                   "0b000000???????????001?????0010011"
#define SRLI_MASK                   "0b000000???????????101?????0010011"
#define SRAI_MASK                   "0b010000???????????101?????0010011"

/* R type */
#define ADD_MASK                    "0b0000000??????????000?????0110011"
#define SUB_MASK                    "0b0100000??????????000?????0110011"
#define SLL_MASK                    "0b0000000??????????001?????0110011"
#define SLT_MASK                    "0b0000000??????????010?????0110011"
#define SLTU_MASK                   "0b0000000??????????011?????0110011"
#define XOR_MASK                    "0b0000000??????????100?????0110011"
#define SRL_MASK                    "0b0000000??????????101?????0110011"
#define SRA_MASK                    "0b0100000??????????101?????0110011"
#define OR_MASK                     "0b000000000????????110?????0110011"
#define AND_MASK                    "0b0000000??????????111?????0110011"

/* I type */
#define ADDIW_MASK                  "0b?????????????????000?????0011011"

/* R type */
#define SLLIW_MASK                  "0b0000000??????????001?????0011011"
#define SRLIW_MASK                  "0b0000000??????????101?????0011011"
#define SRAIW_MASK                  "0b0100000??????????101?????0011011"

/* R type */
#define ADDW_MASK                   "0b0000000??????????000?????0111011"
#define SUBW_MASK                   "0b0100000??????????000?????0111011"
#define SLLW_MASK                   "0b0000000??????????001?????0111011"
#define SRLW_MASK                   "0b0000000??????????101?????0111011"
#define SRAW_MASK                   "0b0100000??????????101?????0111011"

/* I type */
#define LB_MASK                     "0b?????????????????000?????0000011"
#define LH_MASK                     "0b?????????????????001?????0000011"
#define LW_MASK                     "0b?????????????????010?????0000011"
#define LD_MASK                     "0b?????????????????011?????0000011"
#define LBU_MASK                    "0b?????????????????100?????0000011"
#define LHU_MASK                    "0b?????????????????101?????0000011"
#define LWU_MASK                    "0b?????????????????110?????0000011"

/* I type */
#define SB_MASK                     "0b?????????????????000?????0100011"
#define SH_MASK                     "0b?????????????????001?????0100011"
#define SW_MASK                     "0b?????????????????010?????0100011"
#define SD_MASK                     "0b?????????????????011?????0100011"

/* I type */
#define FENCE_MASK                  "0b?????????????????000?????0001111"
#define FENCE_I_MASK                "0b?????????????????001?????0001111"

/* R type */
#define MUL_MASK                    "0b0000001??????????000?????0110011"
#define MULH_MASK                   "0b0000001??????????001?????0110011"
#define MULHSU_MASK                 "0b0000001??????????010?????0110011"
#define MULHU_MASK                  "0b0000001??????????011?????0110011"
#define DIV_MASK                    "0b0000001??????????100?????0110011"
#define DIVU_MASK                   "0b0000001??????????101?????0110011"
#define REM_MASK                    "0b0000001??????????110?????0110011"
#define REMU_MASK                   "0b0000001??????????111?????0110011"

/* R type */
#define MULW_MASK                   "0b0000001??????????000?????0111011"
#define DIVW_MASK                   "0b0000001??????????100?????0111011"
#define DIVUW_MASK                  "0b0000001??????????101?????0111011"
#define REMW_MASK                   "0b0000001??????????110?????0111011"
#define REMUW_MASK                  "0b0000001??????????111?????0111011"


#define LR_W_MASK                   "0b00010??00000?????010?????0101111"
#define LR_D_MASK                   "0b00010??00000?????011?????0101111"

#define SC_W_MASK                   "0b00011????????????010?????0101111"
#define SC_D_MASK                   "0b00011????????????011?????0101111"

#define ECALL_MASK                  "0b00000000000000000000000001110011"
#define EBREAK_MASK                 "0b00000000000100000000000001110011"
#define URET_MASK                   "0b00000000001000000000000001110011"
#define MRET_MASK                   "0b00110000001000000000000001110011"
#define DRET_MASK                   "0b01111011001000000000000001110011"
#define SFENCE_VMA_MASK             "0b0001001??????????000000001110011"
#define WFI_MASK                    "0b00010000010100000000000001110011"
#define CSRRW_MASK                  "0b?????????????????001?????1110011"
#define CSRRS_MASK                  "0b?????????????????010?????1110011"
#define CSRRC_MASK                  "0b?????????????????011?????1110011"
#define CSRRWI_MASK                 "0b?????????????????101?????1110011"
#define CSRRSI_MASK                 "0b?????????????????110?????1110011"
#define CSRRCI_MASK                 "0b?????????????????111?????1110011"

#define CUSTOM0_MASK                "0b?????????????????000?????0001011"
#define CUSTOM0_RS1                 "0b_MASK?????????????????010?????0001011"
#define CUSTOM0_RS1_RS2             "0b?????????????????_MASK011?????0001011"
#define CUSTOM0_RS1_RS2_INV_MASK    "0b??????????????011?????0001011"
#define CUSTOM0_RD_MASK             "0b?????????????????100?????0001011"
#define CUSTOM0_RD_RS1              "0b?????????????????_MASK110?????0001011"
#define CUSTOM0_RD_RS1_INV_MASK     "0b??????????????110?????0001011"
#define CUSTOM0_RD_RS1_RS2          "0b?????????????????_MASK111?????0001011"
#define CUSTOM0_RD_RS1_RS2_INV_MASK "0b??????????????111?????0001011"

#define CUSTOM1_MASK                "0b?????????????????000?????0101011"
#define CUSTOM1_RS1                 "0b_MASK?????????????????010?????0101011"
#define CUSTOM1_RS1_RS2             "0b?????????????????_MASK011?????0101011"
#define CUSTOM1_RS1_RS2_INV_MASK    "0b??????????????011?????0101011"
#define CUSTOM1_RD_MASK             "0b?????????????????100?????0101011"
#define CUSTOM1_RD_RS1              "0b?????????????????_MASK110?????0101011"
#define CUSTOM1_RD_RS1_INV_MASK     "0b??????????????110?????0101011"
#define CUSTOM1_RD_RS1_RS2          "0b?????????????????_MASK111?????0101011"
#define CUSTOM1_RD_RS1_RS2_INV_MASK "0b??????????????111?????0101011"

#define CUSTOM2_MASK                "0b?????????????????000?????1011011"
#define CUSTOM2_RS1                 "0b_MASK?????????????????010?????1011011"
#define CUSTOM2_RS1_RS2             "0b?????????????????_MASK011?????1011011"
#define CUSTOM2_RS1_RS2_INV_MASK    "0b??????????????011?????1011011"
#define CUSTOM2_RD_MASK             "0b?????????????????100?????1011011"
#define CUSTOM2_RD_RS1              "0b?????????????????_MASK110?????1011011"
#define CUSTOM2_RD_RS1_INV_MASK     "0b??????????????110?????1011011"
#define CUSTOM2_RD_RS1_RS2          "0b?????????????????_MASK111?????1011011"
#define CUSTOM2_RD_RS1_RS2_INV_MASK "0b??????????????111?????1011011"

#define CUSTOM3_MASK                "0b?????????????????000?????1111011"
#define CUSTOM3_RS1                 "0b_MASK?????????????????010?????1111011"
#define CUSTOM3_RS1_RS2             "0b?????????????????_MASK011?????1111011"
#define CUSTOM3_RS1_RS2_INV_MASK    "0b??????????????011?????1111011"
#define CUSTOM3_RD_MASK             "0b?????????????????100?????1111011"
#define CUSTOM3_RD_RS1              "0b?????????????????_MASK110?????1111011"
#define CUSTOM3_RD_RS1_INV_MASK     "0b??????????????110?????1111011"
#define CUSTOM3_RD_RS1_RS2          "0b?????????????????_MASK111?????1111011"
#define CUSTOM3_RD_RS1_RS2_INV_MASK "0b??????????????111?????1111011"

#define SLLI_RV32_MASK              "0b0000000??????????001?????0010011"
#define SRLI_RV32_MASK              "0b0000000??????????101?????0010011"
#define SRAI_RV32_MASK              "0b0100000??????????101?????0010011"

#define RDCYCLE_MASK                "0b11000000000000000010?????1110011"
#define RDTIME_MASK                 "0b11000000000100000010?????1110011"
#define RDINSTRET_MASK              "0b11000000001000000010?????1110011"
#define RDCYCLEH_MASK               "0b11001000000000000010?????1110011"
#define RDTIMEH_MASK                "0b11001000000100000010?????1110011"
#define RDINSTRETH_MASK             "0b11001000001000000010?????1110011"

#endif