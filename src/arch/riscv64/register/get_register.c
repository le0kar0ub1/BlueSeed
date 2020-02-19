#include "processor/processor.h"
#include "control/error.h"

static uint64 (*getreg[32])(void) =
{
        processor_get_zero,
        processor_get_ra,
        processor_get_sp,
        processor_get_gp,
        processor_get_tp,
        processor_get_t0,
        processor_get_t1,
        processor_get_t2,
        processor_get_fp,
        processor_get_s1,
        processor_get_a0,
        processor_get_a1,
        processor_get_a2,
        processor_get_a3,
        processor_get_a4,
        processor_get_a5,
        processor_get_a6,
        processor_get_a7,
        processor_get_s2,
        processor_get_s3,
        processor_get_s4,
        processor_get_s5,
        processor_get_s6,
        processor_get_s7,
        processor_get_s8,
        processor_get_s9,
        processor_get_s10,
        processor_get_s11,
        processor_get_t3,
        processor_get_t4,
        processor_get_t5,
        processor_get_t6
};

uint64 registerGet(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return (getreg[reg]());
}