#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "shared/memory/stack.h"
#include "shared/processor/processor.h"
#include "shared/runtime/extractor.h"

extern struct env *environnement;

void arch_init(void) {}

void arch_hookpoint(void)
{
    arch_init();
    verbose_log("Entering in program scheluder...\n");
    arch_exec();
}