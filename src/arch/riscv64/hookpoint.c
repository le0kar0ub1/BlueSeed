#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "shared/memory/stack.h"
#include "riscv64/processor/processor.h"

extern struct env *environnement;

void arch_init(void)
{
    verbose_log("Initializing processor...\n");
    processor_init();

    verbose_log("Initializing stack...\n");
    stack_init();
}

void arch_exit(void)
{
    verbose_log("Destroying stack...\n");
    stack_destroy();

    verbose_log("Destroying processor...\n");
    processor_destroy();
}

void arch_hookpoint(void)
{
    arch_init();
    arch_exit();
}