#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "shared/memory/stack.h"
#include "shared/processor/processor.h"
#include "shared/runtime/elftool.h"

void init_environnement(void)
{
    verbose_log("Initializing stack...\n");
    stack_init();
    verbose_log("Initializing processor...\n");
    processor_init();
    verbose_log("Initializing elf tool...\n");
    elftool_init();
}

void exit_environnement(void)
{
    verbose_log("Destroying processor...\n");
    processor_destroy();
    verbose_log("Destroying stack...\n");
    stack_destroy();
}