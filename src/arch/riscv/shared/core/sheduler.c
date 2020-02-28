#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "shared/memory/stack.h"
#include "shared/processor/processor.h"
#include "shared/runtime/extractor.h"
#include "shared/runtime/elftool.h"
#include "opcode.h"
#include "shared/runtime/dump.h"
#include "instructionBase.h"
#include "shared/opcode_dichotomy/handler.h"
#include "debugger/debugger.h"

extern bool IS_RUN_DEBUG;
extern bool IS_RUN_EXPLICIT;

void displayRunningSymbol(void);
void displayRunningSymbol(void)
{
    static char *symrun = NULL, *newsym = NULL;
    if (IS_RUN_EXPLICIT || IS_RUN_DEBUG)
    if ((newsym = elf_getRunningSymbol((virtaddr_t)processor_get_pc())) != symrun && newsym) {
        symrun = newsym;
        printf("\n[\e[0;34m%s\e[0m:%lx]\n", symrun, (archuval_t)processor_get_pc());
    }
}

void arch_exec(void)
{
    extractor32_t *instr = malloc(sizeof(extractor32_t));
    void (*handler)(extractor32_t *);
    verbose_log("Starting execution...\n");
    /* Program main loop */
    while (1) {
        /* Current symbol */
        displayRunningSymbol();
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