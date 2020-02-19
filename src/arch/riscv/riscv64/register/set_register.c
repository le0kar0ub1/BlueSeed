#include "processor/processor.h"
#include "control/error.h"

static void (*setreg[32])(uint64 val) =
{
        processor_set_zero,
        processor_set_ra,
        processor_set_sp,
        processor_set_gp,
        processor_set_tp,
        processor_set_t0,
        processor_set_t1,
        processor_set_t2,
        processor_set_fp,
        processor_set_s1,
        processor_set_a0,
        processor_set_a1,
        processor_set_a2,
        processor_set_a3,
        processor_set_a4,
        processor_set_a5,
        processor_set_a6,
        processor_set_a7,
        processor_set_s2,
        processor_set_s3,
        processor_set_s4,
        processor_set_s5,
        processor_set_s6,
        processor_set_s7,
        processor_set_s8,
        processor_set_s9,
        processor_set_s10,
        processor_set_s11,
        processor_set_t3,
        processor_set_t4,
        processor_set_t5,
        processor_set_t6
};

void registerSet(uint reg, uint64 val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setreg[reg](val);
}