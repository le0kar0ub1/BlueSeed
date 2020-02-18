#include "shared/memory/stack.h"
#include "env/env.h"

extern struct stack *stack;

hostaddr_t stack_get_stackptr(void)
{
    return (stack->stackptr);
}