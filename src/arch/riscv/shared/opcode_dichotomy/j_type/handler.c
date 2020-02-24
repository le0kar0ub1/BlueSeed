#include "builtin.h"
#include "shared/opcode_dichotomy/handler.h"
#include "shared/opcode_dichotomy/jtype.h"
#include "instructionBase.h"
#include "opcode.h"

static struct opcodeJhandler opcodeJ =
{
    .funct3 = {
        {0b000},

        {-1}
    },
    .handler = {
        {rv32i_jal}, /* IDX 0 in opcodeHandler (B) */
    
        {NULL}
    } 
};

bool opcode_handler_Jtype(extractor32_t *extracted)
{ 
    struct opcode_Jtype *parser = (struct opcode_Jtype *)extracted;
    for (int i = 0; opcodeJ.funct3[i][0] != -1; i++) {
        for (int j = 0; opcodeJ.funct3[i][j] != -1; j++) {
            if (isOpcodeInIndex(JTYPE_OPCODE_IDX, i, parser->opcode)) {
                opcodeJ.handler[i][j](parser);
                return (true);
            }
        }
    }
    return (false);
}