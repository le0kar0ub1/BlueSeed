#include "builtin.h"
#include "shared/processor/processor.h"
#include "shared/memory/stack.h"

extern struct abiprocessor *processor;

void processor_dump_register(char const *name)
{
    if (!isRegisterExistant(getRegisterIdxFromName(name)))
        printf("Invalid Register...\n");
    else
        printf("\e[0;31m%s    \e[0m: \e[0;34m%016lx \e[0m\n", name, getRegisterFromName(name));
}

void processor_udump(void)
{
    printf("\e[0;31mx0    \e[0m: \e[0;34m%016lxu \e[0m (zero-hardwired)\n", (archuval_t)processor->zero);
    printf("\e[0;31mra    \e[0m: \e[0;34m%016lxu \e[0m (Adress return)\n", (archuval_t)processor->ra);
    printf("\e[0;31msp    \e[0m: \e[0;34m%016lxu \e[0m (Stack pointer)\n", (archuval_t)processor->sp);
    printf("\e[0;31mgp    \e[0m: \e[0;34m%016lxu \e[0m (Global pointer)\n", (archuval_t)processor->gp);
    printf("\e[0;31mtp    \e[0m: \e[0;34m%016lxu \e[0m (thread pointer)\n", (archuval_t)processor->tp);
    printf("\e[0;31mt0    \e[0m: \e[0;34m%016lxu \e[0m (temporary register - Alternate link register)\n", (archuval_t)processor->t0);
    printf("\e[0;31mt1    \e[0m: \e[0;34m%016lxu \e[0m (temporary register)\n", (archuval_t)processor->t1);
    printf("\e[0;31mt2    \e[0m: \e[0;34m%016lxu \e[0m (temporary register)\n", (archuval_t)processor->t2);
    printf("\e[0;31mfp    \e[0m: \e[0;34m%016lxu \e[0m (frame pointer)\n", (archuval_t)processor->fp);
    printf("\e[0;31ms1    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s1);
    printf("\e[0;31ma0    \e[0m: \e[0;34m%016lxu \e[0m (function arguments)\n", (archuval_t)processor->a0);
    printf("\e[0;31ma1    \e[0m: \e[0;34m%016lxu \e[0m (function arguments)\n", (archuval_t)processor->a1);
    printf("\e[0;31ma2    \e[0m: \e[0;34m%016lxu \e[0m (function arguments)\n", (archuval_t)processor->a2);
    printf("\e[0;31ma3    \e[0m: \e[0;34m%016lxu \e[0m (function arguments)\n", (archuval_t)processor->a3);
    printf("\e[0;31ma4    \e[0m: \e[0;34m%016lxu \e[0m (function arguments)\n", (archuval_t)processor->a4);
    printf("\e[0;31ma5    \e[0m: \e[0;34m%016lxu \e[0m (function arguments)\n", (archuval_t)processor->a5);
    printf("\e[0;31ma6    \e[0m: \e[0;34m%016lxu \e[0m (function arguments)\n", (archuval_t)processor->a6);
    printf("\e[0;31ma7    \e[0m: \e[0;34m%016lxu \e[0m (function arguments)\n", (archuval_t)processor->a7);
    printf("\e[0;31ms2    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s2);
    printf("\e[0;31ms3    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s3);
    printf("\e[0;31ms4    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s4);
    printf("\e[0;31ms5    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s5);
    printf("\e[0;31ms6    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s6);
    printf("\e[0;31ms7    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s7);
    printf("\e[0;31ms8    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s8);
    printf("\e[0;31ms9    \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s9);
    printf("\e[0;31ms10   \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s10);
    printf("\e[0;31ms11   \e[0m: \e[0;34m%016lxu \e[0m (saved register)\n", (archuval_t)processor->s11);
    printf("\e[0;31mt3    \e[0m: \e[0;34m%016lxu \e[0m (temporary register)\n", (archuval_t)processor->t3);
    printf("\e[0;31mt4    \e[0m: \e[0;34m%016lxu \e[0m (temporary register)\n", (archuval_t)processor->t4);
    printf("\e[0;31mt5    \e[0m: \e[0;34m%016lxu \e[0m (temporary register)\n", (archuval_t)processor->t5);
    printf("\e[0;31mt6    \e[0m: \e[0;34m%016lxu \e[0m (temporary register)\n", (archuval_t)processor->t6); 

    printf("\e[0;31mft0   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft0);
    printf("\e[0;31mft1   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft1);
    printf("\e[0;31mft2   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft2);
    printf("\e[0;31mft3   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft3);
    printf("\e[0;31mft4   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft4);
    printf("\e[0;31mft5   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft5);
    printf("\e[0;31mft6   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft6);
    printf("\e[0;31mft7   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft7);
    printf("\e[0;31mfs0   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs0);
    printf("\e[0;31mfs1   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs1);
    printf("\e[0;31mfa0   \e[0m: \e[0;34m%016lxu \e[0m (FP argument/ret value)\n", (archuval_t)processor->fa0);
    printf("\e[0;31mfa1   \e[0m: \e[0;34m%016lxu \e[0m (FP argument/ret value)\n", (archuval_t)processor->fa1);
    printf("\e[0;31mfa2   \e[0m: \e[0;34m%016lxu \e[0m (FP argument)\n", (archuval_t)processor->fa2);
    printf("\e[0;31mfa3   \e[0m: \e[0;34m%016lxu \e[0m (FP argument)\n", (archuval_t)processor->fa3);
    printf("\e[0;31mfa4   \e[0m: \e[0;34m%016lxu \e[0m (FP argument)\n", (archuval_t)processor->fa4);
    printf("\e[0;31mfa5   \e[0m: \e[0;34m%016lxu \e[0m (FP argument)\n", (archuval_t)processor->fa5);
    printf("\e[0;31mfa6   \e[0m: \e[0;34m%016lxu \e[0m (FP argument)\n", (archuval_t)processor->fa6);
    printf("\e[0;31mfa7   \e[0m: \e[0;34m%016lxu \e[0m (FP argument)\n", (archuval_t)processor->fa7);
    printf("\e[0;31mfs2   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs2);
    printf("\e[0;31mfs3   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs3);
    printf("\e[0;31mfs4   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs4);
    printf("\e[0;31mfs5   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs5);
    printf("\e[0;31mfs6   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs6);
    printf("\e[0;31mfs7   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs7);
    printf("\e[0;31mfs8   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs8);
    printf("\e[0;31mfs9   \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs9);
    printf("\e[0;31mfs10  \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs10);
    printf("\e[0;31mfs11  \e[0m: \e[0;34m%016lxu \e[0m (FP saved register)\n", (archuval_t)processor->fs11);
    printf("\e[0;31mft8   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft8);
    printf("\e[0;31mft9   \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft9);
    printf("\e[0;31mft10  \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft10);
    printf("\e[0;31mft11  \e[0m: \e[0;34m%016lxu \e[0m (FP temporary)\n", (archuval_t)processor->ft11);

    printf("\e[0;31mpc    \e[0m: \e[0;34m%016lxu \e[0m (PROGRAM COUNTER)\n", (archuval_t)processor->pc);
}

void processor_dump(void)
{
    printf("\e[0;31mx0    \e[0m: \e[0;34m%016lx \e[0m (zero-hardwired)\n", (archival_t)processor->zero);
    printf("\e[0;31mra    \e[0m: \e[0;34m%016lx \e[0m (Adress return)\n", (archival_t)processor->ra);
    printf("\e[0;31msp    \e[0m: \e[0;34m%016lx \e[0m (Stack pointer)\n", (archival_t)processor->sp);
    printf("\e[0;31mgp    \e[0m: \e[0;34m%016lx \e[0m (Global pointer)\n", (archival_t)processor->gp);
    printf("\e[0;31mtp    \e[0m: \e[0;34m%016lx \e[0m (thread pointer)\n", (archival_t)processor->tp);
    printf("\e[0;31mt0    \e[0m: \e[0;34m%016lx \e[0m (temporary register - Alternate link register)\n", (archival_t)processor->t0);
    printf("\e[0;31mt1    \e[0m: \e[0;34m%016lx \e[0m (temporary register)\n", (archival_t)processor->t1);
    printf("\e[0;31mt2    \e[0m: \e[0;34m%016lx \e[0m (temporary register)\n", (archival_t)processor->t2);
    printf("\e[0;31mfp    \e[0m: \e[0;34m%016lx \e[0m (frame pointer)\n", (archival_t)processor->fp);
    printf("\e[0;31ms1    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s1);
    printf("\e[0;31ma0    \e[0m: \e[0;34m%016lx \e[0m (function arguments)\n", (archival_t)processor->a0);
    printf("\e[0;31ma1    \e[0m: \e[0;34m%016lx \e[0m (function arguments)\n", (archival_t)processor->a1);
    printf("\e[0;31ma2    \e[0m: \e[0;34m%016lx \e[0m (function arguments)\n", (archival_t)processor->a2);
    printf("\e[0;31ma3    \e[0m: \e[0;34m%016lx \e[0m (function arguments)\n", (archival_t)processor->a3);
    printf("\e[0;31ma4    \e[0m: \e[0;34m%016lx \e[0m (function arguments)\n", (archival_t)processor->a4);
    printf("\e[0;31ma5    \e[0m: \e[0;34m%016lx \e[0m (function arguments)\n", (archival_t)processor->a5);
    printf("\e[0;31ma6    \e[0m: \e[0;34m%016lx \e[0m (function arguments)\n", (archival_t)processor->a6);
    printf("\e[0;31ma7    \e[0m: \e[0;34m%016lx \e[0m (function arguments)\n", (archival_t)processor->a7);
    printf("\e[0;31ms2    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s2);
    printf("\e[0;31ms3    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s3);
    printf("\e[0;31ms4    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s4);
    printf("\e[0;31ms5    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s5);
    printf("\e[0;31ms6    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s6);
    printf("\e[0;31ms7    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s7);
    printf("\e[0;31ms8    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s8);
    printf("\e[0;31ms9    \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s9);
    printf("\e[0;31ms10   \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s10);
    printf("\e[0;31ms11   \e[0m: \e[0;34m%016lx \e[0m (saved register)\n", (archival_t)processor->s11);
    printf("\e[0;31mt3    \e[0m: \e[0;34m%016lx \e[0m (temporary register)\n", (archival_t)processor->t3);
    printf("\e[0;31mt4    \e[0m: \e[0;34m%016lx \e[0m (temporary register)\n", (archival_t)processor->t4);
    printf("\e[0;31mt5    \e[0m: \e[0;34m%016lx \e[0m (temporary register)\n", (archival_t)processor->t5);
    printf("\e[0;31mt6    \e[0m: \e[0;34m%016lx \e[0m (temporary register)\n", (archival_t)processor->t6); 

    printf("\e[0;31mft0   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft0);
    printf("\e[0;31mft1   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft1);
    printf("\e[0;31mft2   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft2);
    printf("\e[0;31mft3   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft3);
    printf("\e[0;31mft4   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft4);
    printf("\e[0;31mft5   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft5);
    printf("\e[0;31mft6   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft6);
    printf("\e[0;31mft7   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft7);
    printf("\e[0;31mfs0   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs0);
    printf("\e[0;31mfs1   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs1);
    printf("\e[0;31mfa0   \e[0m: \e[0;34m%016lx \e[0m (FP argument/ret value)\n", (archival_t)processor->fa0);
    printf("\e[0;31mfa1   \e[0m: \e[0;34m%016lx \e[0m (FP argument/ret value)\n", (archival_t)processor->fa1);
    printf("\e[0;31mfa2   \e[0m: \e[0;34m%016lx \e[0m (FP argument)\n", (archival_t)processor->fa2);
    printf("\e[0;31mfa3   \e[0m: \e[0;34m%016lx \e[0m (FP argument)\n", (archival_t)processor->fa3);
    printf("\e[0;31mfa4   \e[0m: \e[0;34m%016lx \e[0m (FP argument)\n", (archival_t)processor->fa4);
    printf("\e[0;31mfa5   \e[0m: \e[0;34m%016lx \e[0m (FP argument)\n", (archival_t)processor->fa5);
    printf("\e[0;31mfa6   \e[0m: \e[0;34m%016lx \e[0m (FP argument)\n", (archival_t)processor->fa6);
    printf("\e[0;31mfa7   \e[0m: \e[0;34m%016lx \e[0m (FP argument)\n", (archival_t)processor->fa7);
    printf("\e[0;31mfs2   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs2);
    printf("\e[0;31mfs3   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs3);
    printf("\e[0;31mfs4   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs4);
    printf("\e[0;31mfs5   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs5);
    printf("\e[0;31mfs6   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs6);
    printf("\e[0;31mfs7   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs7);
    printf("\e[0;31mfs8   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs8);
    printf("\e[0;31mfs9   \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs9);
    printf("\e[0;31mfs10  \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs10);
    printf("\e[0;31mfs11  \e[0m: \e[0;34m%016lx \e[0m (FP saved register)\n", (archival_t)processor->fs11);
    printf("\e[0;31mft8   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft8);
    printf("\e[0;31mft9   \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft9);
    printf("\e[0;31mft10  \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft10);
    printf("\e[0;31mft11  \e[0m: \e[0;34m%016lx \e[0m (FP temporary)\n", (archival_t)processor->ft11);

    printf("\e[0;31mpc    \e[0m: \e[0;34m%016lx \e[0m (PROGRAM COUNTER)\n", (archival_t)processor->pc);
}