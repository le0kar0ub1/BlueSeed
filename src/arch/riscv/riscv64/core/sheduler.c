#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "shared/memory/stack.h"
#include "shared/processor/processor.h"
#include "shared/runtime/extractor.h"
#include "opcode.h"
#include "shared/runtime/dump.h"
#include "instructionBase.h"
#include "shared/opcode_dichotomy/handler.h"
#include "debugger/debugger.h"

extern bool IS_RUN_DEBUG;

void arch_exec(void)
{
    extractor32_t *instr = malloc(sizeof(extractor32_t));
    void (*handler)(extractor32_t *);
    verbose_log("Starting execution...\n");
    /* Program main loop */
    while (1) {
        /* If running in debug mode */
        if (IS_RUN_DEBUG)
            debugger();
        /* Extract 4 byte from the current PC */
        *instr = extractCodeD();
        /* Get the instruction handler */
        handler = getHandlerFromOpcode(*instr);
        if (!handler)
            RAISE(ERR_OPCODE_NUM);
        /* Then Exec this instruction */
        handler(instr);
    }
    free(instr);
}