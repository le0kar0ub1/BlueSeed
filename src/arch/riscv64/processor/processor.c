#include "builtin.h"
#include "processor/processor.h"
#include "shared/memory/stack.h"

extern struct env *environnement;

struct abiprocessor *processor;


void processor_init(void)
{
    processor = (struct abiprocessor *)vmalloc(sizeof(struct abiprocessor));
    memset(processor, 0x0, sizeof(struct abiprocessor));
    /* INIT stack pointer */
    processor_set_sp((reg_t)stack_get_stackptr());
    /* INIT program counter */
    processor_set_pc((reg_t)environnement->virtual.link);
}

void processor_destroy(void)
{
    free(processor);
}