#include "builtin.h"
#include "shared/opcode_dichotomy/handler.h"
#include "shared/opcode_dichotomy/itype.h"

// static struct opcodeIhandler opcodeI =
// {
//     .funct3 = {
//         {0b000,    0b001,    0b010,    0b100,     0b101},

//         {0b000,      0b010,      0b011,       0b100,      0b110,     0b111},

//         {}
//     },
//     .handler = {
//         {rv32i_lb, rv32i_lh, rv32i_lw, rv32i_lbu, rv32i_lhu},

//         {rv32i_addi, rv32i_slti, rv32i_sltiu, rv32i_xori, rv32i_ori, rv32i_andi},

//         {}
//     } 
// };

void opcode_handler_Itype(extractor32_t *extracted)
{ 
    printf("I-type handling\n");
    struct opcode_Itype *parser = (struct opcode_Itype *)extracted;
}