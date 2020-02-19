#include "builtin.h"
#include "shared/opcode_dichotomy/handler.h"
#include "shared/opcode_dichotomy/utype.h"
#include "instructionBase.h"
#include "opcode.h"

static struct opcodeUhandler opcodeU =
{
    .opcode = {
        {LUI_OPCODE, -1},

        {AUIPC_OPCODE, -1},

        {-1}
    },
    .handler = {
        {rv32i_lui}, /* IDX 0 in opcodeHandler (U) */

        {rv32i_auipc}, /* IDX 1 in opcodeHandler (U) */

        {NULL}
    } 
};

void opcode_handler_Utype(extractor32_t *extracted)
{ 
    struct opcode_Utype *parser = (struct opcode_Utype *)extracted;
    for (int i = 0; opcodeU.opcode[i][0] != -1; i++) {
        for (int j = 0; opcodeU.opcode[i][j] != -1; j++) {
            if (isOpcodeInIndex(UTYPE_OPCODE_IDX, i, parser->opcode) &&
            opcodeU.opcode[i][j] == (int)parser->opcode) {
                opcodeU.handler[i][j](parser);
                return;
            }
        }
    }
    RAISE(ERR_OPCODE_NUM);
}