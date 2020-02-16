#ifndef _RV64A_INSTRUCTION_H_
#define _RV64A_INSTRUCTION_H_

#include "isa/rv32a/opcode.h"

#define RV64A_OPCODE 0b0101111

#define LR_D_MASK   "00010??00000?????011?????0101111"
#define LR_D_OPCODE 0b0101111
#define SC_D_MASK   "00011????????????011?????0101111"
#define SC_D_OPCODE 0b0101111

#endif