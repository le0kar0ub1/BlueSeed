#ifndef _STACK_H_
#define _STACK_H_

#include "builtin.h"
#include "env/env.h"

#define STACK_BASE_SIZE 0x1000000

void stack_init(void);
void stack_destroy(void);

hostaddr_t stack_get_stackptr(void);

void stack_increase(uint);
void stack_decrease(uint);

struct stack
{
    hostaddr_t stackbase;
    hostaddr_t stackptr;
};

#endif