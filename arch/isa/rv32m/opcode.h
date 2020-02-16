#ifndef _RV32M_INSTRUCTION_H_
#define _RV32M_INSTRUCTION_H_

/* R-type */
#define RV32M_OPCODE  0b0110011

#define MUL_MASK      "0000001??????????000?????0110011"
#define MUL_OPCODE    0b0110011

#define MULH_MASK     "0000001??????????001?????0110011"
#define MULH_OPCODE   0b0110011

#define MULHSU_MASK   "0000001??????????010?????0110011"
#define MULHSU_OPCODE 0b0110011

#define MULHU_MASK    "0000001??????????011?????0110011"
#define MULHU_OPCODE  0b0110011

#define DIV_MASK      "0000001??????????100?????0110011"
#define DIV_OPCODE    0b0110011

#define DIVU_MASK     "0000001??????????101?????0110011"
#define DIVU_OPCODE   0b0110011

#define REM_MASK      "0000001??????????110?????0110011"
#define REM_OPCODE    0b0110011

#define REMU_MASK     "0000001??????????111?????0110011"
#define REMU_OPCODE   0b0110011

#endif