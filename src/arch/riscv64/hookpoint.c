#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "shared/memory/stack.h"
#include "processor/processor.h"
#include "shared/runtime/extractor.h"

extern struct env *environnement;

void arch_init(void)
{
}

void arch_exit(void)
{
}

void arch_hookpoint(void)
{
    arch_init();
    arch_exit();
}