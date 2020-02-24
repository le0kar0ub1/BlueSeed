#include "builtin.h"
#include "shared/opcode_dichotomy/handler.h"
#include "shared/opcode_dichotomy/pseudoinstr.h"
#include "instructionBase.h"
#include "opcode.h"

static struct opcodePseudohandler opcodePseudo =
{
    .opcode = {
        PSEUDO_INSTR_RET,
        -1
    },
    .handler = {
        pseudoinstr_ret,
        NULL
    } 
};

void opcode_handler_pseudoInstr(extractor32_t *extracted)
{ 
    int parser = (int)*extracted;
    for (int i = 0; opcodePseudo.opcode[i] != -1; i++) {
        if (opcodePseudo.opcode[i] == parser) {
            opcodePseudo.handler[i](parser);
            return;
        }
    }
    RAISE(ERR_OPCODE_NUM);
}