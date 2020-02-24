#include "opcode.h"
#include "shared/opcode_dichotomy/handler.h"
#include "isa/compressed/opcode.h"

// static struct opcodeHandler compressedOpcode =
// {
//     .opcode  = {
//                 {},
//                },
//     .handler = {
//             NULL
//     }
// };

// bool isOpcodeInIndex(uint typeidx, uint subidx, uint val)
// {
//     if ((uint)riscvopcode.opcode[typeidx][subidx] == val)
//         return (true);
//     return (false);
// }

void *getCompressedHandlerFromOpcode(int opcode)
{
    printf("COMPRESSED\n");
    // for (uint i = 0; i < RISCV_OPCODE_TYPE_MAX - 1; i++) {
    //     for (uint j = 0; riscvopcode.opcode[i][j]; j++) {
    //         if (opcode == riscvopcode.opcode[i][j])
    //             return (riscvopcode.handler[i]);
    //     }
    // }
    // RAISE(ERR_OPCODE_NUM);
    return (NULL);
}