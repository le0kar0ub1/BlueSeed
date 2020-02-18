#include "builtin.h"
#include "riscv64/processor/processor.h"
#include "riscv64/processor/set_register.h"

extern struct abiprocessor *processor;

void processor_set_zero(uintptr val)
{
    processor->zero = val;
}

void processor_set_ra(uintptr val)
{
    processor->ra = val;
}

void processor_set_sp(uintptr val)
{
    processor->sp = val;
}

void processor_set_gp(uintptr val)
{
    processor->gp = val;
}

void processor_set_tp(uintptr val)
{
    processor->tp = val;
}

void processor_set_t0(uintptr val)
{
    processor->t0 = val;
}

void processor_set_t1(uintptr val)
{
    processor->t1 = val;
}

void processor_set_t2(uintptr val)
{
    processor->t2 = val;
}

void processor_set_fp(uintptr val)
{
    processor->fp = val;
}

void processor_set_s1(uintptr val)
{
    processor->s1 = val;
}

void processor_set_a0(uintptr val)
{
    processor->a0 = val;
}

void processor_set_a1(uintptr val)
{
    processor->a1 = val;
}

void processor_set_a2(uintptr val)
{
    processor->a2 = val;
}

void processor_set_a3(uintptr val)
{
    processor->a3 = val;
}

void processor_set_a4(uintptr val)
{
    processor->a4 = val;
}

void processor_set_a5(uintptr val)
{
    processor->a5 = val;
}

void processor_set_a6(uintptr val)
{
    processor->a6 = val;
}

void processor_set_a7(uintptr val)
{
    processor->a7 = val;
}

void processor_set_s2(uintptr val)
{
    processor->s2 = val;
}

void processor_set_s3(uintptr val)
{
    processor->s3 = val;
}

void processor_set_s4(uintptr val)
{
    processor->s4 = val;
}

void processor_set_s5(uintptr val)
{
    processor->s5 = val;
}

void processor_set_s6(uintptr val)
{
    processor->s6 = val;
}

void processor_set_s7(uintptr val)
{
    processor->s7 = val;
}

void processor_set_s8(uintptr val)
{
    processor->s8 = val;
}

void processor_set_s9(uintptr val)
{
    processor->s9 = val;
}

void processor_set_s10(uintptr val)
{
    processor->s10 = val;
}

void processor_set_s11(uintptr val)
{
    processor->s11 = val;
}

void processor_set_t3(uintptr val)
{
    processor->t3 = val;
}

void processor_set_t4(uintptr val)
{
    processor->t4 = val;
}

void processor_set_t5(uintptr val)
{
    processor->t5 = val;
}

void processor_set_t6(uintptr val)
{
    processor->t6 = val;
}

void processor_set_ft0(uintptr val)
{
    processor->ft0 = val;
}

void processor_set_ft1(uintptr val)
{
    processor->ft1 = val;
}

void processor_set_ft2(uintptr val)
{
    processor->ft2 = val;
}

void processor_set_ft3(uintptr val)
{
    processor->ft3 = val;
}

void processor_set_ft4(uintptr val)
{
    processor->ft4 = val;
}

void processor_set_ft5(uintptr val)
{
    processor->ft5 = val;
}

void processor_set_ft6(uintptr val)
{
    processor->ft6 = val;
}

void processor_set_ft7(uintptr val)
{
    processor->ft7 = val;
}

void processor_set_fs0(uintptr val)
{
    processor->fs0 = val;
}

void processor_set_fs1(uintptr val)
{
    processor->fs1 = val;
}

void processor_set_fa0(uintptr val)
{
    processor->fa0 = val;
}

void processor_set_fa1(uintptr val)
{
    processor->fa1 = val;
}

void processor_set_fa2(uintptr val)
{
    processor->fa2 = val;
}

void processor_set_fa3(uintptr val)
{
    processor->fa3 = val;
}

void processor_set_fa4(uintptr val)
{
    processor->fa4 = val;
}

void processor_set_fa5(uintptr val)
{
    processor->fa5 = val;
}

void processor_set_fa6(uintptr val)
{
    processor->fa6 = val;
}

void processor_set_fa7(uintptr val)
{
    processor->fa7 = val;
}

void processor_set_fs2(uintptr val)
{
    processor->fs2 = val;
}

void processor_set_fs3(uintptr val)
{
    processor->fs3 = val;
}

void processor_set_fs4(uintptr val)
{
    processor->fs4 = val;
}

void processor_set_fs5(uintptr val)
{
    processor->fs5 = val;
}

void processor_set_fs6(uintptr val)
{
    processor->fs6 = val;
}

void processor_set_fs7(uintptr val)
{
    processor->fs7 = val;
}

void processor_set_fs8(uintptr val)
{
    processor->fs8 = val;
}

void processor_set_fs9(uintptr val)
{
    processor->fs9 = val;
}

void processor_set_fs10(uintptr val)
{
    processor->fs10 = val;
}

void processor_set_fs11(uintptr val)
{
    processor->fs11 = val;
}

void processor_set_ft8(uintptr val)
{
    processor->ft8 = val;
}

void processor_set_ft9(uintptr val)
{
    processor->ft9 = val;
}

void processor_set_ft10(uintptr val)
{
    processor->ft10 = val;
}

void processor_set_ft11(uintptr val)
{
    processor->ft11 = val;
}

void processor_set_pc(uintptr val)
{
    processor->pc = val;
}