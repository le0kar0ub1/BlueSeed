#include "builtin.h"
#include "processor/processor.h"
#include "shared/memory/stack.h"

extern struct abiprocessor *processor;

void processor_udump(void)
{
    printf("\e[0;31mx0    \e[0m: \e[0;34m%020lu \e[0m (zero-hardwired)\n", (uint64)processor->zero);
    printf("\e[0;31mra    \e[0m: \e[0;34m%020lu \e[0m (Adress return)\n", (uint64)processor->ra);
    printf("\e[0;31msp    \e[0m: \e[0;34m%020lu \e[0m (Stack pointer)\n", (uint64)processor->sp);
    printf("\e[0;31mgp    \e[0m: \e[0;34m%020lu \e[0m (Global pointer)\n", (uint64)processor->gp);
    printf("\e[0;31mtp    \e[0m: \e[0;34m%020lu \e[0m (thread pointer)\n", (uint64)processor->tp);
    printf("\e[0;31mt0    \e[0m: \e[0;34m%020lu \e[0m (temporary register - Alternate link register)\n", (uint64)processor->t0);
    printf("\e[0;31mt1    \e[0m: \e[0;34m%020lu \e[0m (temporary register)\n", (uint64)processor->t1);
    printf("\e[0;31mt2    \e[0m: \e[0;34m%020lu \e[0m (temporary register)\n", (uint64)processor->t2);
    printf("\e[0;31mfp    \e[0m: \e[0;34m%020lu \e[0m (frame pointer)\n", (uint64)processor->fp);
    printf("\e[0;31ms1    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s1);
    printf("\e[0;31ma0    \e[0m: \e[0;34m%020lu \e[0m (function arguments)\n", (uint64)processor->a0);
    printf("\e[0;31ma1    \e[0m: \e[0;34m%020lu \e[0m (function arguments)\n", (uint64)processor->a1);
    printf("\e[0;31ma2    \e[0m: \e[0;34m%020lu \e[0m (function arguments)\n", (uint64)processor->a2);
    printf("\e[0;31ma3    \e[0m: \e[0;34m%020lu \e[0m (function arguments)\n", (uint64)processor->a3);
    printf("\e[0;31ma4    \e[0m: \e[0;34m%020lu \e[0m (function arguments)\n", (uint64)processor->a4);
    printf("\e[0;31ma5    \e[0m: \e[0;34m%020lu \e[0m (function arguments)\n", (uint64)processor->a5);
    printf("\e[0;31ma6    \e[0m: \e[0;34m%020lu \e[0m (function arguments)\n", (uint64)processor->a6);
    printf("\e[0;31ma7    \e[0m: \e[0;34m%020lu \e[0m (function arguments)\n", (uint64)processor->a7);
    printf("\e[0;31ms2    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s2);
    printf("\e[0;31ms3    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s3);
    printf("\e[0;31ms4    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s4);
    printf("\e[0;31ms5    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s5);
    printf("\e[0;31ms6    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s6);
    printf("\e[0;31ms7    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s7);
    printf("\e[0;31ms8    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s8);
    printf("\e[0;31ms9    \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s9);
    printf("\e[0;31ms10   \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s10);
    printf("\e[0;31ms11   \e[0m: \e[0;34m%020lu \e[0m (saved register)\n", (uint64)processor->s11);
    printf("\e[0;31mt3    \e[0m: \e[0;34m%020lu \e[0m (temporary register)\n", (uint64)processor->t3);
    printf("\e[0;31mt4    \e[0m: \e[0;34m%020lu \e[0m (temporary register)\n", (uint64)processor->t4);
    printf("\e[0;31mt5    \e[0m: \e[0;34m%020lu \e[0m (temporary register)\n", (uint64)processor->t5);
    printf("\e[0;31mt6    \e[0m: \e[0;34m%020lu \e[0m (temporary register)\n", (uint64)processor->t6); 

    printf("\e[0;31mft0   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft0);
    printf("\e[0;31mft1   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft1);
    printf("\e[0;31mft2   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft2);
    printf("\e[0;31mft3   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft3);
    printf("\e[0;31mft4   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft4);
    printf("\e[0;31mft5   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft5);
    printf("\e[0;31mft6   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft6);
    printf("\e[0;31mft7   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft7);
    printf("\e[0;31mfs0   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs0);
    printf("\e[0;31mfs1   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs1);
    printf("\e[0;31mfa0   \e[0m: \e[0;34m%020lu \e[0m (FP argument/ret value)\n", (uint64)processor->fa0);
    printf("\e[0;31mfa1   \e[0m: \e[0;34m%020lu \e[0m (FP argument/ret value)\n", (uint64)processor->fa1);
    printf("\e[0;31mfa2   \e[0m: \e[0;34m%020lu \e[0m (FP argument)\n", (uint64)processor->fa2);
    printf("\e[0;31mfa3   \e[0m: \e[0;34m%020lu \e[0m (FP argument)\n", (uint64)processor->fa3);
    printf("\e[0;31mfa4   \e[0m: \e[0;34m%020lu \e[0m (FP argument)\n", (uint64)processor->fa4);
    printf("\e[0;31mfa5   \e[0m: \e[0;34m%020lu \e[0m (FP argument)\n", (uint64)processor->fa5);
    printf("\e[0;31mfa6   \e[0m: \e[0;34m%020lu \e[0m (FP argument)\n", (uint64)processor->fa6);
    printf("\e[0;31mfa7   \e[0m: \e[0;34m%020lu \e[0m (FP argument)\n", (uint64)processor->fa7);
    printf("\e[0;31mfs2   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs2);
    printf("\e[0;31mfs3   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs3);
    printf("\e[0;31mfs4   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs4);
    printf("\e[0;31mfs5   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs5);
    printf("\e[0;31mfs6   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs6);
    printf("\e[0;31mfs7   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs7);
    printf("\e[0;31mfs8   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs8);
    printf("\e[0;31mfs9   \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs9);
    printf("\e[0;31mfs10  \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs10);
    printf("\e[0;31mfs11  \e[0m: \e[0;34m%020lu \e[0m (FP saved register)\n", (uint64)processor->fs11);
    printf("\e[0;31mft8   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft8);
    printf("\e[0;31mft9   \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft9);
    printf("\e[0;31mft10  \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft10);
    printf("\e[0;31mft11  \e[0m: \e[0;34m%020lu \e[0m (FP temporary)\n", (uint64)processor->ft11);

    printf("\e[0;31mpc    \e[0m: \e[0;34m%020lu \e[0m (PROGRAM COUNTER)\n", (uint64)processor->pc);
}

void processor_dump(void)
{
    printf("\e[0;31mxo    \e[0m: \e[0;34m%020ld \e[0m (zero-hardwired)\n", (int64)processor->zero);
    printf("\e[0;31mra    \e[0m: \e[0;34m%020ld \e[0m (Adress return)\n", (int64)processor->ra);
    printf("\e[0;31msp    \e[0m: \e[0;34m%020ld \e[0m (Stack pointer)\n", (int64)processor->sp);
    printf("\e[0;31mgp    \e[0m: \e[0;34m%020ld \e[0m (Global pointer)\n", (int64)processor->gp);
    printf("\e[0;31mtp    \e[0m: \e[0;34m%020ld \e[0m (thread pointer)\n", (int64)processor->tp);
    printf("\e[0;31mt0    \e[0m: \e[0;34m%020ld \e[0m (temporary register - Alternate link register)\n", (int64)processor->t0);
    printf("\e[0;31mt1    \e[0m: \e[0;34m%020ld \e[0m (temporary register)\n", (int64)processor->t1);
    printf("\e[0;31mt2    \e[0m: \e[0;34m%020ld \e[0m (temporary register)\n", (int64)processor->t2);
    printf("\e[0;31mfp    \e[0m: \e[0;34m%020ld \e[0m (frame pointer)\n", (int64)processor->fp);
    printf("\e[0;31ms1    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s1);
    printf("\e[0;31ma0    \e[0m: \e[0;34m%020ld \e[0m (function arguments)\n", (int64)processor->a0);
    printf("\e[0;31ma1    \e[0m: \e[0;34m%020ld \e[0m (function arguments)\n", (int64)processor->a1);
    printf("\e[0;31ma2    \e[0m: \e[0;34m%020ld \e[0m (function arguments)\n", (int64)processor->a2);
    printf("\e[0;31ma3    \e[0m: \e[0;34m%020ld \e[0m (function arguments)\n", (int64)processor->a3);
    printf("\e[0;31ma4    \e[0m: \e[0;34m%020ld \e[0m (function arguments)\n", (int64)processor->a4);
    printf("\e[0;31ma5    \e[0m: \e[0;34m%020ld \e[0m (function arguments)\n", (int64)processor->a5);
    printf("\e[0;31ma6    \e[0m: \e[0;34m%020ld \e[0m (function arguments)\n", (int64)processor->a6);
    printf("\e[0;31ma7    \e[0m: \e[0;34m%020ld \e[0m (function arguments)\n", (int64)processor->a7);
    printf("\e[0;31ms2    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s2);
    printf("\e[0;31ms3    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s3);
    printf("\e[0;31ms4    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s4);
    printf("\e[0;31ms5    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s5);
    printf("\e[0;31ms6    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s6);
    printf("\e[0;31ms7    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s7);
    printf("\e[0;31ms8    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s8);
    printf("\e[0;31ms9    \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s9);
    printf("\e[0;31ms10   \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s10);
    printf("\e[0;31ms11   \e[0m: \e[0;34m%020ld \e[0m (saved register)\n", (int64)processor->s11);
    printf("\e[0;31mt3    \e[0m: \e[0;34m%020ld \e[0m (temporary register)\n", (int64)processor->t3);
    printf("\e[0;31mt4    \e[0m: \e[0;34m%020ld \e[0m (temporary register)\n", (int64)processor->t4);
    printf("\e[0;31mt5    \e[0m: \e[0;34m%020ld \e[0m (temporary register)\n", (int64)processor->t5);
    printf("\e[0;31mt6    \e[0m: \e[0;34m%020ld \e[0m (temporary register)\n", (int64)processor->t6); 

    printf("\e[0;31mft0   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft0);
    printf("\e[0;31mft1   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft1);
    printf("\e[0;31mft2   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft2);
    printf("\e[0;31mft3   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft3);
    printf("\e[0;31mft4   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft4);
    printf("\e[0;31mft5   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft5);
    printf("\e[0;31mft6   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft6);
    printf("\e[0;31mft7   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft7);
    printf("\e[0;31mfs0   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs0);
    printf("\e[0;31mfs1   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs1);
    printf("\e[0;31mfa0   \e[0m: \e[0;34m%020ld \e[0m (FP argument/ret value)\n", (int64)processor->fa0);
    printf("\e[0;31mfa1   \e[0m: \e[0;34m%020ld \e[0m (FP argument/ret value)\n", (int64)processor->fa1);
    printf("\e[0;31mfa2   \e[0m: \e[0;34m%020ld \e[0m (FP argument)\n", (int64)processor->fa2);
    printf("\e[0;31mfa3   \e[0m: \e[0;34m%020ld \e[0m (FP argument)\n", (int64)processor->fa3);
    printf("\e[0;31mfa4   \e[0m: \e[0;34m%020ld \e[0m (FP argument)\n", (int64)processor->fa4);
    printf("\e[0;31mfa5   \e[0m: \e[0;34m%020ld \e[0m (FP argument)\n", (int64)processor->fa5);
    printf("\e[0;31mfa6   \e[0m: \e[0;34m%020ld \e[0m (FP argument)\n", (int64)processor->fa6);
    printf("\e[0;31mfa7   \e[0m: \e[0;34m%020ld \e[0m (FP argument)\n", (int64)processor->fa7);
    printf("\e[0;31mfs2   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs2);
    printf("\e[0;31mfs3   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs3);
    printf("\e[0;31mfs4   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs4);
    printf("\e[0;31mfs5   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs5);
    printf("\e[0;31mfs6   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs6);
    printf("\e[0;31mfs7   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs7);
    printf("\e[0;31mfs8   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs8);
    printf("\e[0;31mfs9   \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs9);
    printf("\e[0;31mfs10  \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs10);
    printf("\e[0;31mfs11  \e[0m: \e[0;34m%020ld \e[0m (FP saved register)\n", (int64)processor->fs11);
    printf("\e[0;31mft8   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft8);
    printf("\e[0;31mft9   \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft9);
    printf("\e[0;31mft10  \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft10);
    printf("\e[0;31mft11  \e[0m: \e[0;34m%020ld \e[0m (FP temporary)\n", (int64)processor->ft11);

    printf("\e[0;31mpc    \e[0m: \e[0;34m%020ld \e[0m (PROGRAM COUNTER)\n", (int64)processor->pc);
}