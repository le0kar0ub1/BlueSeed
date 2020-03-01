#include "shared/processor/processor.h"
#include "control/error.h"

static archival_t (*getreg[32])(void) =
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

static archuval_t (*getUreg[32])(void) =
{
        processor_getu_zero,
        processor_getu_ra,
        processor_getu_sp,
        processor_getu_gp,
        processor_getu_tp,
        processor_getu_t0,
        processor_getu_t1,
        processor_getu_t2,
        processor_getu_fp,
        processor_getu_s1,
        processor_getu_a0,
        processor_getu_a1,
        processor_getu_a2,
        processor_getu_a3,
        processor_getu_a4,
        processor_getu_a5,
        processor_getu_a6,
        processor_getu_a7,
        processor_getu_s2,
        processor_getu_s3,
        processor_getu_s4,
        processor_getu_s5,
        processor_getu_s6,
        processor_getu_s7,
        processor_getu_s8,
        processor_getu_s9,
        processor_getu_s10,
        processor_getu_s11,
        processor_getu_t3,
        processor_getu_t4,
        processor_getu_t5,
        processor_getu_t6
};

archival_t registerGet(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return (getreg[reg]());
}

int8 registerGetB(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return ((int8)getreg[reg]());
}

int16 registerGetW(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return ((int16)getreg[reg]());
}

int32 registerGetD(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return ((int32)getreg[reg]());
}

int64 registerGetQ(uint reg)
{
    return (registerGet(reg));
}

archuval_t registerUGet(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return (getUreg[reg]());
}

uint8 registerUGetB(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return ((uint8)getUreg[reg]());
}

uint16 registerUGetW(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return ((uint16)getUreg[reg]());
}

uint32 registerUGetD(uint reg)
{
    if (reg == 0)
        return (0);
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    return ((uint32)getUreg[reg]());
}

uint64 registerUGetQ(uint reg)
{
    return (registerUGet(reg));
}