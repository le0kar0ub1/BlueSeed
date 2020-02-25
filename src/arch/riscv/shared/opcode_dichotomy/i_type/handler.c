#include "builtin.h"
#include "shared/opcode_dichotomy/handler.h"
#include "shared/opcode_dichotomy/itype.h"
#include "instructionBase.h"
#include "opcode.h"

static struct opcodeIhandler opcodeI =
{
    .funct3 = {
        {0b000,    0b001,    0b010,    0b100,     0b101, -1},

        {0b000,      0b010,      0b011,       0b100,      0b110,     0b111, -1},

        {0b001,      0b101,      0b101, -1},

        {0b000,       0b001, -1},

        {0b000, -1},

        {0b001,      0b010,        0b011,       0b101,        0b110,        0b111, -1},

        {0b0, -1},

        {-1}
    },
    .handler = {
        {rv32i_lb, rv32i_lh, rv32i_lw, rv32i_lbu, rv32i_lhu}, /* IDX 0 in opcodeHandler (I) */

        {rv32i_addi, rv32i_slti, rv32i_sltiu, rv32i_xori, rv32i_ori, rv32i_andi}, /* IDX 1 in opcodeHandler (I) */

        {rv32i_slli, rv32i_srli, rv32i_srai}, /* IDX 2 in opcodeHandler (I) */

        {rv32i_fence, rv32i_fencei}, /* IDX 3 in opcodeHandler (I) */

        {rv32i_callNbreak}, /* IDX 4 in opcodeHandler (I) */

        {rv32i_csrrw, rv32i_csrrs, rv32i_csrrc, rv32i_csrrwi, rv32i_csrrsi, rv32i_csrrci}, /* IDX 5 in opcodeHandler (I) */

        {rv32i_jalr}, /* IDX 6 in opcodehandler (I) */

        {NULL}
    } 
};

bool checkItypeConstraints(int i, int j __unused, struct opcode_Itype *parser)
{
    if (i == 1 && parser->rd == 0)
        return (false);
    return (true);
}

void *opcode_handler_Itype(extractor32_t *extracted)
{ 
    struct opcode_Itype *parser = (struct opcode_Itype *)extracted;
    for (int i = 0; opcodeI.funct3[i][0] != -1; i++) {
        for (int j = 0; opcodeI.funct3[i][j] != -1; j++) {
            if (isOpcodeInIndex(ITYPE_OPCODE_IDX, i, parser->opcode) &&
            opcodeI.funct3[i][j] == (int)parser->funct3) {
                if (!checkItypeConstraints(i, j, parser))
                    return (NULL);
                return (opcodeI.handler[i][j]);
            }
        }
    }
    return (NULL);
}