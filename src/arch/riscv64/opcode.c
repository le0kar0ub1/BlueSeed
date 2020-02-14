// #include "opcode.h"

// static struct opcodePrefix prefix =
// {
//     .prefix  = {
//                 0b1100011, /* branch */

//                 0b1100111, /* JALR */

//                 0b1101111, /* JAL */

//                 0b0110111, /* LUI */

//                 0b0010111, /* AUIPC */

//                 0b0010011, /* OP IMM */

//                 0b0110011, /* OP */

//                 0b0011011, /* OPW IMM */

//                 0b0111011, /* OPW */

//                 0b0000011, /* LOAD */

//                 0b0100011, /* STORE */

//                 0b0001111, /* FENCE */

//                 0b0110011, /* MUL/DIV H */

//                 0b0111011, /* MUL/DIV W */

//                 0b0101111, /* LOAD/STORE W/D */

//                 0b1110011, /* JMP & like */
//                },
//     .op     = {
//             {
//                 .opscd   = {0b000,     0b001,     0b100,     0b101,     0b110,      0b111,      END_SCD_OPCODE}, 
//                 .handler = {instr_beq, instr_bne, instr_blt, instr_bge, instr_bltu, instr_bgeu, NULL}
//             },
//             {
//                 .opscd   = {0b000,      END_SCD_OPCODE},
//                 .handler = {instr_jalr, NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE},
//                 .handler = {instr_jal,      NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE},
//                 .handler = {instr_lui,      NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE},
//                 .handler = {instr_auipc,    NULL},
//             },
//             {
//                 .opscd   = {0b000,      0b001,      0b010,      0b011,       0b100,      0b101,        0b101,        0b110,     0b111,      END_SCD_OPCODE},
//                 .handler = {instr_addi, instr_slli, instr_slti, instr_sltiu, instr_xori, instr_shifti, instr_shifti, instr_ori, instr_andi, NULL}
//             },
//             {
//                 .opscd   = {0b000,     0b001,     0b010,     0b011,      0b100,     0b101,       0b101,       0b110,    0b111,     END_SCD_OPCODE},
//                 .handler = {instr_add, instr_sll, instr_slt, instr_sltu, instr_xor, instr_shift, instr_shift, instr_or, instr_and, NULL}
//             },
//             {
//                 .opscd   = {0b000,       0b001,       0b101,         0b101,         END_SCD_OPCODE},
//                 .handler = {instr_addiw, instr_slliw, instr_shiftiw, instr_shiftiw, NULL}
//             },
//             {
//                 .opscd   = {0b000,         0b000,         0b001,      0b101,        0b101,       END_SCD_OPCODE},
//                 .handler = {instr_addsubw, instr_addsubw, instr_sllw, instr_shiftw, instr_shiftw, NULL}
//             },
//             {
//                 .opscd   = {0b000,    0b001,    0b010,    0b011,    0b100,     0b101,     0b110,     END_SCD_OPCODE},
//                 .handler = {instr_lb, instr_lh, instr_lw, instr_ld, instr_lbu, instr_lhu, instr_lwu, NULL}
//             },
//             {
//                 .opscd   = {0b000,    0b001,    0b010,    0b011,    END_SCD_OPCODE},
//                 .handler = {instr_sb, instr_sh, instr_sw, instr_sd, NULL}
//             },
//             {
//                 .opscd   = {0b000,       0b001,       END_SCD_OPCODE},
//                 .handler = {instr_fence, instr_fenci, NULL}
//             },
//             {
//                 .opscd   = {0b000,     0b001,      0b010,        0b011,       0b100,     0b101,      0b110,     0b111,      END_SCD_OPCODE},
//                 .handler = {instr_mul, instr_mulh, instr_mulhsu, instr_mulhu, instr_div, instr_divu, instr_rem, instr_remu, NULL}
//             },
//             {
//                 .opscd   = {0b010,     0b010,     0b011,     0b011,     END_SCD_OPCODE},
//                 .handler = {instr_lrw, instr_scw, instr_lrd, instr_scd, NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE},
//                 .handler = {instr_ecall,    NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE}, 
//                 .handler = {instr_ebreak,   END_SCD_OPCODE}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE},
//                 .handler = {instr_uret,     NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE},
//                 .handler = {instr_mret,     NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE},
//                 .handler = {instr_dret,     NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE,   END_SCD_OPCODE},
//                 .handler = {instr_sfence_vma, NULL}
//             },
//             {
//                 .opscd   = {END_SCD_OPCODE, END_SCD_OPCODE},
//                 .handler = {instr_wfi,     NULL}
//             },
//     }
// };
