#include "riscv64/memory/stack.h"
#include "env/env.h"

hostaddr_t stackbase;
hostaddr_t stackptr;

void stack_init(void)
{
    stackbase = vmalloc(STACK_BASE_SIZE);
    stackptr = stackbase;
}

void stack_destroy(void)
{
    free(stackbase);
}