#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "riscv64/memory/stack.h"

extern struct env *environnement;

void arch_hookpoint(void)
{
    verbose_log("Initializing stack...\n");
    stack_init();
    stack_destroy();
}