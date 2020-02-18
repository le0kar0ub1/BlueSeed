#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "shared/memory/stack.h"
#include "processor/processor.h"
#include "shared/runtime/extractor.h"
#include "opcode.h"
#include "shared/runtime/dump.h"
#include "instructionBase.h"
#include "shared/opcode_dichotomy/handler.h"

void arch_exec(void)
{
    extractor32_t *instr = malloc(sizeof(extractor32_t));
    void (*handler)(extractor32_t *);
    /* Program main loop */
    while(1) {
        *instr = extractCodeD();
        handler = getHandlerFromOpcode(RISCV_OPCODE_MASK(*instr));
        handler(instr);
    }
    free(instr);
}

void opcode_handler_Stype(extractor32_t *extracted) { printf("opcode_handler_Stype\n");}
void opcode_handler_Rtype(extractor32_t *extracted) { printf("opcode_handler_Rtype\n");}
void opcode_handler_Utype(extractor32_t *extracted) { printf("opcode_handler_Utype\n");}
void opcode_handler_Jtype(extractor32_t *extracted) { printf("opcode_handler_Jtype\n");}
void opcode_handler_R4type(extractor32_t *extracted) { printf("opcode_handler_Jtype\n");}
