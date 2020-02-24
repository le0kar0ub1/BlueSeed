#include "builtin.h"
#include "shared/opcode_dichotomy/handler.h"
#include "shared/opcode_dichotomy/btype.h"
#include "instructionBase.h"
#include "opcode.h"

static struct opcodeBhandler opcodeB =
{
    .funct3 = {
        {0b000,     0b001,     0b100,     0b101,     0b110,      0b111,   -1},

        {-1}
    },
    .handler = {
        {rv32i_beq, rv32i_bne, rv32i_blt, rv32i_bge, rv32i_bltu, rv32i_bgeu}, /* IDX 0 in opcodeHandler (B) */
    
        {NULL}
    } 
};

bool opcode_handler_Btype(extractor32_t *extracted)
{ 
    struct opcode_Btype *parser = (struct opcode_Btype *)extracted;
    for (int i = 0; opcodeB.funct3[i][0] != -1; i++) {
        for (int j = 0; opcodeB.funct3[i][j] != -1; j++) {
            if (isOpcodeInIndex(BTYPE_OPCODE_IDX, i, parser->opcode) &&
            opcodeB.funct3[i][j] == (int)parser->funct3) {
                opcodeB.handler[i][j](parser);
                return (true);
            }
        }
    }
    return (false);
}