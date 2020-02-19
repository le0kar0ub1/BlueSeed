#include "builtin.h"
#include "riscv64/processor/processor.h"
#include "riscv64/processor/get_register.h"

extern struct abiprocessor *processor;

uintptr processor_get_zero(void)
{
    return (processor->zero);
}

uintptr processor_get_ra(void)
{
    return (processor->ra);
}

uintptr processor_get_sp(void)
{
    return (processor->sp);
}

uintptr processor_get_gp(void)
{
    return (processor->gp);
}

uintptr processor_get_tp(void)
{
    return (processor->tp);
}

uintptr processor_get_t0(void)
{
    return (processor->t0);
}

uintptr processor_get_t1(void)
{
    return (processor->t1);
}

uintptr processor_get_t2(void)
{
    return (processor->t2);
}

uintptr processor_get_fp(void)
{
    return (processor->fp);
}

uintptr processor_get_s1(void)
{
    return (processor->s1);
}

uintptr processor_get_a0(void)
{
    return (processor->a0);
}

uintptr processor_get_a1(void)
{
    return (processor->a1);
}

uintptr processor_get_a2(void)
{
    return (processor->a2);
}

uintptr processor_get_a3(void)
{
    return (processor->a3);
}

uintptr processor_get_a4(void)
{
    return (processor->a4);
}

uintptr processor_get_a5(void)
{
    return (processor->a5);
}

uintptr processor_get_a6(void)
{
    return (processor->a6);
}

uintptr processor_get_a7(void)
{
    return (processor->a7);
}

uintptr processor_get_s2(void)
{
    return (processor->s2);
}

uintptr processor_get_s3(void)
{
    return (processor->s3);
}

uintptr processor_get_s4(void)
{
    return (processor->s4);
}

uintptr processor_get_s5(void)
{
    return (processor->s5);
}

uintptr processor_get_s6(void)
{
    return (processor->s6);
}

uintptr processor_get_s7(void)
{
    return (processor->s7);
}

uintptr processor_get_s8(void)
{
    return (processor->s8);
}

uintptr processor_get_s9(void)
{
    return (processor->s9);
}

uintptr processor_get_s10(void)
{
    return (processor->s10);
}

uintptr processor_get_s11(void)
{
    return (processor->s11);
}

uintptr processor_get_t3(void)
{
    return (processor->t3);
}

uintptr processor_get_t4(void)
{
    return (processor->t4);
}

uintptr processor_get_t5(void)
{
    return (processor->t5);
}

uintptr processor_get_t6(void)
{
    return (processor->t6);
}

uintptr processor_get_ft0(void)
{
    return (processor->ft0);
}

uintptr processor_get_ft1(void)
{
    return (processor->ft1);
}

uintptr processor_get_ft2(void)
{
    return (processor->ft2);
}

uintptr processor_get_ft3(void)
{
    return (processor->ft3);
}

uintptr processor_get_ft4(void)
{
    return (processor->ft4);
}

uintptr processor_get_ft5(void)
{
    return (processor->ft5);
}

uintptr processor_get_ft6(void)
{
    return (processor->ft6);
}

uintptr processor_get_ft7(void)
{
    return (processor->ft7);
}

uintptr processor_get_fs0(void)
{
    return (processor->fs0);
}

uintptr processor_get_fs1(void)
{
    return (processor->fs1);
}

uintptr processor_get_fa0(void)
{
    return (processor->fa0);
}

uintptr processor_get_fa1(void)
{
    return (processor->fa1);
}

uintptr processor_get_fa2(void)
{
    return (processor->fa2);
}

uintptr processor_get_fa3(void)
{
    return (processor->fa3);
}

uintptr processor_get_fa4(void)
{
    return (processor->fa4);
}

uintptr processor_get_fa5(void)
{
    return (processor->fa5);
}

uintptr processor_get_fa6(void)
{
    return (processor->fa6);
}

uintptr processor_get_fa7(void)
{
    return (processor->fa7);
}

uintptr processor_get_fs2(void)
{
    return (processor->fs2);
}

uintptr processor_get_fs3(void)
{
    return (processor->fs3);
}

uintptr processor_get_fs4(void)
{
    return (processor->fs4);
}

uintptr processor_get_fs5(void)
{
    return (processor->fs5);
}

uintptr processor_get_fs6(void)
{
    return (processor->fs6);
}

uintptr processor_get_fs7(void)
{
    return (processor->fs7);
}

uintptr processor_get_fs8(void)
{
    return (processor->fs8);
}

uintptr processor_get_fs9(void)
{
    return (processor->fs9);
}

uintptr processor_get_fs10(void)
{
    return (processor->fs10);
}

uintptr processor_get_fs11(void)
{
    return (processor->fs11);
}

uintptr processor_get_ft8(void)
{
    return (processor->ft8);
}

uintptr processor_get_ft9(void)
{
    return (processor->ft9);
}

uintptr processor_get_ft10(void)
{
    return (processor->ft10);
}

uintptr processor_get_ft11(void)
{
    return (processor->ft11);
}

uintptr processor_get_pc(void)
{
    return (processor->pc);
}