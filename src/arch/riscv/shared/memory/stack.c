#include "shared/memory/stack.h"
#include "env/env.h"

extern struct stack *stack;

hostaddr_t stack_get_stackptr(void)
{
    return (stack->stackptr);
}

void stack_increase(uint inc)
{
    stack->stackptr = (hostaddr_t)ADD_TO_PTR(stack->stackptr, inc);
}

void stack_decrease(uint dec)
{
    stack->stackptr = (hostaddr_t)SUB_TO_PTR(stack->stackptr, dec);
}