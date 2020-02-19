#include "builtin.h"
#include "processor/processor.h"
#include "shared/memory/stack.h"

extern struct abiprocessor *processor;

void processor_udump(void)
{
    printf("%lu /* zero-hardwired */", (uint64)processor->zero);
    printf("%lu /* Adress return */", (uint64)processor->ra);
    printf("%lu /* Stack pointer */", (uint64)processor->sp);
    printf("%lu /* Global pointer */", (uint64)processor->gp);
    printf("%lu /* thread pointer */", (uint64)processor->tp);
    printf("%lu /* temporary register - Alternate link register */", (uint64)processor->t0);
    printf("%lu /* temporary register */", (uint64)processor->t1);
    printf("%lu /* temporary register */", (uint64)processor->t2);
    printf("%lu /* frame pointer */", (uint64)processor->fp);
    printf("%lu /* saved register */", (uint64)processor->s1);
    printf("%lu /* function arguments */", (uint64)processor->a0);
    printf("%lu /* function arguments */", (uint64)processor->a1);
    printf("%lu /* function arguments */", (uint64)processor->a2);
    printf("%lu /* function arguments */", (uint64)processor->a3);
    printf("%lu /* function arguments */", (uint64)processor->a4);
    printf("%lu /* function arguments */", (uint64)processor->a5);
    printf("%lu /* function arguments */", (uint64)processor->a6);
    printf("%lu /* function arguments */", (uint64)processor->a7);
    printf("%lu /* saved register */", (uint64)processor->s2);
    printf("%lu /* saved register */", (uint64)processor->s3);
    printf("%lu /* saved register */", (uint64)processor->s4);
    printf("%lu /* saved register */", (uint64)processor->s5);
    printf("%lu /* saved register */", (uint64)processor->s6);
    printf("%lu /* saved register */", (uint64)processor->s7);
    printf("%lu /* saved register */", (uint64)processor->s8);
    printf("%lu /* saved register */", (uint64)processor->s9);
    printf("%lu /* saved register */", (uint64)processor->s10);
    printf("%lu /* saved register */", (uint64)processor->s11);
    printf("%lu /* temporary register */", (uint64)processor->t3);
    printf("%lu /* temporary register */", (uint64)processor->t4);
    printf("%lu /* temporary register */", (uint64)processor->t5);
    printf("%lu /* temporary register */", (uint64)processor->t6);

    printf("%lu /* FP temporary */", (uint64)processor->ft0);
    printf("%lu /* FP temporary */", (uint64)processor->ft1);
    printf("%lu /* FP temporary */", (uint64)processor->ft2);
    printf("%lu /* FP temporary */", (uint64)processor->ft3);
    printf("%lu /* FP temporary */", (uint64)processor->ft4);
    printf("%lu /* FP temporary */", (uint64)processor->ft5);
    printf("%lu /* FP temporary */", (uint64)processor->ft6);
    printf("%lu /* FP temporary */", (uint64)processor->ft7);
    printf("%lu /* FP saved register */", (uint64)processor->fs0);
    printf("%lu /* FP saved register */", (uint64)processor->fs1);
    printf("%lu /* FP argument/ret value */", (uint64)processor->fa0);
    printf("%lu /* FP argument/ret value */", (uint64)processor->fa1);
    printf("%lu /* FP argument */", (uint64)processor->fa2);
    printf("%lu /* FP argument */", (uint64)processor->fa3);
    printf("%lu /* FP argument */", (uint64)processor->fa4);
    printf("%lu /* FP argument */", (uint64)processor->fa5);
    printf("%lu /* FP argument */", (uint64)processor->fa6);
    printf("%lu /* FP argument */", (uint64)processor->fa7);
    printf("%lu /* FP saved register */", (uint64)processor->fs2);
    printf("%lu /* FP saved register */", (uint64)processor->fs3);
    printf("%lu /* FP saved register */", (uint64)processor->fs4);
    printf("%lu /* FP saved register */", (uint64)processor->fs5);
    printf("%lu /* FP saved register */", (uint64)processor->fs6);
    printf("%lu /* FP saved register */", (uint64)processor->fs7);
    printf("%lu /* FP saved register */", (uint64)processor->fs8);
    printf("%lu /* FP saved register */", (uint64)processor->fs9);
    printf("%lu /* FP saved register */", (uint64)processor->fs10);
    printf("%lu /* FP saved register */", (uint64)processor->fs11);
    printf("%lu /* FP temporary */", (uint64)processor->ft8);
    printf("%lu /* FP temporary */", (uint64)processor->ft9);
    printf("%lu /* FP temporary */", (uint64)processor->ft10);
    printf("%lu /* FP temporary */", (uint64)processor->ft11);

    printf("%lu /* PROGRAM COUNTER */", (uint64)processor->pc);
}

void processor_dump(void)
{
    printf("%ld /* zero-hardwired */", (int64)processor->zero);
    printf("%ld /* Adress return */", (int64)processor->ra);
    printf("%ld /* Stack pointer */", (int64)processor->sp);
    printf("%ld /* Global pointer */", (int64)processor->gp);
    printf("%ld /* thread pointer */", (int64)processor->tp);
    printf("%ld /* temporary register - Alternate link register */", (int64)processor->t0);
    printf("%ld /* temporary register */", (int64)processor->t1);
    printf("%ld /* temporary register */", (int64)processor->t2);
    printf("%ld /* frame pointer */", (int64)processor->fp);
    printf("%ld /* saved register */", (int64)processor->s1);
    printf("%ld /* function arguments */", (int64)processor->a0);
    printf("%ld /* function arguments */", (int64)processor->a1);
    printf("%ld /* function arguments */", (int64)processor->a2);
    printf("%ld /* function arguments */", (int64)processor->a3);
    printf("%ld /* function arguments */", (int64)processor->a4);
    printf("%ld /* function arguments */", (int64)processor->a5);
    printf("%ld /* function arguments */", (int64)processor->a6);
    printf("%ld /* function arguments */", (int64)processor->a7);
    printf("%ld /* saved register */", (int64)processor->s2);
    printf("%ld /* saved register */", (int64)processor->s3);
    printf("%ld /* saved register */", (int64)processor->s4);
    printf("%ld /* saved register */", (int64)processor->s5);
    printf("%ld /* saved register */", (int64)processor->s6);
    printf("%ld /* saved register */", (int64)processor->s7);
    printf("%ld /* saved register */", (int64)processor->s8);
    printf("%ld /* saved register */", (int64)processor->s9);
    printf("%ld /* saved register */", (int64)processor->s10);
    printf("%ld /* saved register */", (int64)processor->s11);
    printf("%ld /* temporary register */", (int64)processor->t3);
    printf("%ld /* temporary register */", (int64)processor->t4);
    printf("%ld /* temporary register */", (int64)processor->t5);
    printf("%ld /* temporary register */", (int64)processor->t6);

    printf("%ld /* FP temporary */", (int64)processor->ft0);
    printf("%ld /* FP temporary */", (int64)processor->ft1);
    printf("%ld /* FP temporary */", (int64)processor->ft2);
    printf("%ld /* FP temporary */", (int64)processor->ft3);
    printf("%ld /* FP temporary */", (int64)processor->ft4);
    printf("%ld /* FP temporary */", (int64)processor->ft5);
    printf("%ld /* FP temporary */", (int64)processor->ft6);
    printf("%ld /* FP temporary */", (int64)processor->ft7);
    printf("%ld /* FP saved register */", (int64)processor->fs0);
    printf("%ld /* FP saved register */", (int64)processor->fs1);
    printf("%ld /* FP argument/ret value */", (int64)processor->fa0);
    printf("%ld /* FP argument/ret value */", (int64)processor->fa1);
    printf("%ld /* FP argument */", (int64)processor->fa2);
    printf("%ld /* FP argument */", (int64)processor->fa3);
    printf("%ld /* FP argument */", (int64)processor->fa4);
    printf("%ld /* FP argument */", (int64)processor->fa5);
    printf("%ld /* FP argument */", (int64)processor->fa6);
    printf("%ld /* FP argument */", (int64)processor->fa7);
    printf("%ld /* FP saved register */", (int64)processor->fs2);
    printf("%ld /* FP saved register */", (int64)processor->fs3);
    printf("%ld /* FP saved register */", (int64)processor->fs4);
    printf("%ld /* FP saved register */", (int64)processor->fs5);
    printf("%ld /* FP saved register */", (int64)processor->fs6);
    printf("%ld /* FP saved register */", (int64)processor->fs7);
    printf("%ld /* FP saved register */", (int64)processor->fs8);
    printf("%ld /* FP saved register */", (int64)processor->fs9);
    printf("%ld /* FP saved register */", (int64)processor->fs10);
    printf("%ld /* FP saved register */", (int64)processor->fs11);
    printf("%ld /* FP temporary */", (int64)processor->ft8);
    printf("%ld /* FP temporary */", (int64)processor->ft9);
    printf("%ld /* FP temporary */", (int64)processor->ft10);
    printf("%ld /* FP temporary */", (int64)processor->ft11);

    printf("%ld /* PROGRAM COUNTER */", (int64)processor->pc);
}