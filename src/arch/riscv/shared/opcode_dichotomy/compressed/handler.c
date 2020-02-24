#include "builtin.h"
#include "shared/opcode_dichotomy/handler.h"
#include "shared/opcode_dichotomy/compressed.h"
#include "instructionBase.h"
#include "opcode.h"

static struct opcodeCompressedHandler opcodeCompressed =
{
    .opcode = {
        -1
    },
    .handler = {
        NULL
    } 
};

bool opcode_handler_compressed(extractor32_t *extracted)
{ 
    int parser = (int)*extracted;
    for (int i = 0; opcodeCompressed.opcode[i] != -1; i++) {
        if (opcodeCompressed.opcode[i] == parser) {
            opcodeCompressed.handler[i](parser);
            return (true);
        }
    }
    return (false);
}