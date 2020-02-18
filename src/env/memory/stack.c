#include "shared/memory/stack.h"
#include "env/env.h"

struct stack *stack;

void stack_init(void)
{
    stack = vmalloc(sizeof(struct stack));
    stack->stackbase = vmalloc(STACK_BASE_SIZE);
    stack->stackptr  = stack->stackbase;
}

void stack_destroy(void)
{
    free(stack->stackbase);
}