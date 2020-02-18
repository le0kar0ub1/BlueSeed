#include "builtin.h"
#include "riscv64/processor/processor.h"

struct abiprocessor *processor;

void processor_init(void)
{
    processor = (struct abiprocessor *)vmalloc(sizeof(struct abiprocessor));
    memset(processor, 0x0, sizeof(struct abiprocessor));
}

void processor_destroy(void)
{
    free(processor);
}