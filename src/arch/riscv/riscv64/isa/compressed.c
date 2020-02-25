#include "opcode.h"
#include "shared/opcode_dichotomy/handler.h"
#include "isa/compressed/opcode.h"
#include "shared/opcode_dichotomy/compressed.h"

void *compressedHandlerGetZero(int opcode)
{
    return (NULL);
}

void *compressedHandlerGetOne(int opcode __unused)
{
    return (NULL);
}

void *compressedHandlerGetTwo(int opcode __unused)
{
    return (NULL);
}


void *getCompressedHandlerFromOpcode(int opcode)
{
    switch (COMPRESSED_OPMASK(opcode)) {
        case COMPRESSED_OP0:
            return (compressedHandlerGetZero(opcode));
            break;
        case COMPRESSED_OP1:
            return (compressedHandlerGetOne(opcode));
            break;
        case COMPRESSED_OP2:
            return (compressedHandlerGetTwo(opcode));
            break;
        case COMPRESSED_OP3:
            return (NULL);
            break;
        default:
            return (NULL);
    }
}