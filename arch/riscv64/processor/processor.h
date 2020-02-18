#ifndef _PROCESSOR_CONTEXT_H_
#define _PROCESSOR_CONTEXT_H_

#include "typedef.h"
#include "keyword.h"

struct abiprocessor {
    uintptr zero; /* zero-hardwired */
    uintptr ra;   /* Adress return */
    uintptr sp;   /* Stack pointer */
    uintptr gp;   /* Global pointer */
    uintptr tp;   /* thread pointer */

    uintptr t0;   /* temporary register - Alternate link register */
    uintptr t1;   /* temporary register */
    uintptr t2;   /* temporary register */

    uintptr fp;   /* frame pointer */

    uintptr s1;   /* saved register */

    uintptr a0;   /* function arguments */
    uintptr a1;   /* function arguments */
    uintptr a2;   /* function arguments */
    uintptr a3;   /* function arguments */
    uintptr a4;   /* function arguments */
    uintptr a5;   /* function arguments */
    uintptr a6;   /* function arguments */
    uintptr a7;   /* function arguments */

    uintptr s2;   /* saved register */
    uintptr s3;   /* saved register */
    uintptr s4;   /* saved register */
    uintptr s5;   /* saved register */
    uintptr s6;   /* saved register */
    uintptr s7;   /* saved register */
    uintptr s8;   /* saved register */
    uintptr s9;   /* saved register */
    uintptr s10;  /* saved register */
    uintptr s11;  /* saved register */

    uintptr t3;   /* temporary register */
    uintptr t4;   /* temporary register */
    uintptr t5;   /* temporary register */
    uintptr t6;   /* temporary register */



    uintptr ft0;   /* FP temporary */
    uintptr ft1;   /* FP temporary */
    uintptr ft2;   /* FP temporary */
    uintptr ft3;   /* FP temporary */
    uintptr ft4;   /* FP temporary */
    uintptr ft5;   /* FP temporary */
    uintptr ft6;   /* FP temporary */
    uintptr ft7;   /* FP temporary */

    uintptr fs0;   /* FP saved register */
    uintptr fs1;   /* FP saved register */
    uintptr fa0;   /* FP argument/ret value */
    uintptr fa1;   /* FP argument/ret value */
    uintptr fa2;   /* FP argument */
    uintptr fa3;   /* FP argument */
    uintptr fa4;   /* FP argument */
    uintptr fa5;   /* FP argument */
    uintptr fa6;   /* FP argument */
    uintptr fa7;   /* FP argument */

    uintptr fs2;   /* FP saved register */
    uintptr fs3;   /* FP saved register */
    uintptr fs4;   /* FP saved register */
    uintptr fs5;   /* FP saved register */
    uintptr fs6;   /* FP saved register */
    uintptr fs7;   /* FP saved register */
    uintptr fs8;   /* FP saved register */
    uintptr fs9;   /* FP saved register */
    uintptr fs10;  /* FP saved register */
    uintptr fs11;  /* FP saved register */

    uintptr ft8;   /* FP temporary */
    uintptr ft9;   /* FP temporary */
    uintptr ft10;  /* FP temporary */
    uintptr ft11;  /* FP temporary */


    uintptr pc;   /* PROGRAM COUNTER */
} __packed;

void processor_init(void);
void processor_destroy(void);
void processor_set_stackptr(uintptr ptr);

struct riscv64_processor {
    uintptr x0;  /* UN-USABLE REGISTER (raise exception else) */
    uintptr x1;  /* Adress return */
    uintptr x2;  /* Stack pointer */
    uintptr x3;  /* Global pointer */
    uintptr x4;  /* thread pointer */
    uintptr x5;  /* temporary register - Alternate link register */
    uintptr x6;  /* temporary register */
    uintptr x7;  /* temporary register */
    uintptr x8;  /* frame pointer */
    uintptr x9;  /* saved register */
    uintptr x10; /* function arguments */
    uintptr x11; /* function arguments */
    uintptr x12; /* function arguments */
    uintptr x13; /* function arguments */
    uintptr x14; /* function arguments */
    uintptr x15; /* function arguments */
    uintptr x16; /* function arguments */
    uintptr x17; /* function arguments */
    uintptr x18; /* saved register */
    uintptr x19; /* saved register */
    uintptr x20; /* saved register */
    uintptr x21; /* saved register */
    uintptr x22; /* saved register */
    uintptr x23; /* saved register */
    uintptr x24; /* saved register */
    uintptr x25; /* saved register */
    uintptr x26; /* saved register */
    uintptr x27; /* saved register */
    uintptr x28; /* temporary register */
    uintptr x29; /* temporary register */
    uintptr x30; /* temporary register */
    uintptr x31; /* temporary register */
    uintptr pc;  /* PROGRAM COUNTER */
} __packed;

#endif