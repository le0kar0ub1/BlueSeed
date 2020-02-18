#ifndef _STACK_H_
#define _STACK_H_

#include "builtin.h"

#define STACK_BASE_SIZE 0x1000000

void stack_init(void);
void stack_destroy(void);

#endif