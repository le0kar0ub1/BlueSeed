#include "builtin.h"
#include "shared/opcode_dichotomy/handler.h"
#include "shared/opcode_dichotomy/stype.h"
#include "instructionBase.h"
#include "opcode.h"

static struct opcodeShandler opcodeS =
{
    .funct3 = {
        {0b000,    0b001,    0b010,   -1},

        {-1}
    },
    .handler = {
        {rv32i_sb, rv32i_sh, rv32i_sw}, /* IDX 0 in opcodeHandler (S) */
    
        {NULL}
    } 
};

void opcode_handler_Stype(extractor32_t *extracted)
{ 
    struct opcode_Stype *parser = (struct opcode_Stype *)extracted;
    for (int i = 0; opcodeS.funct3[i][0] != -1; i++) {
        for (int j = 0; opcodeS.funct3[i][j] != -1; j++) {
            if (isOpcodeInIndex(STYPE_OPCODE_IDX, i, parser->opcode)) {
                opcodeS.handler[i][j](parser);
                return;
            }
        }
    }
    RAISE(ERR_OPCODE_NUM);
}