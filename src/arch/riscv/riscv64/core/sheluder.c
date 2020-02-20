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
#include "shared/debugger/debugger.h"

extern bool IS_RUN_DEBUG;

void arch_exec(void)
{
    extractor32_t *instr = malloc(sizeof(extractor32_t));
    void (*handler)(extractor32_t *);
    verbose_log("Starting execution...\n");
    /* Program main loop */
    while (1) {
        *instr = extractCodeD();
        handler = getHandlerFromOpcode(RISCV_OPCODE_MASK(*instr));
        handler(instr);
        if (IS_RUN_DEBUG)
            debugger();
    }
    free(instr);
}