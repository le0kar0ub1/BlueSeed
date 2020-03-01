#include "shared/processor/processor.h"
#include "control/error.h"

static void (*setreg[32])(archival_t val) =
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

static void (*setUreg[32])(archuval_t val) =
{
        processor_setu_zero,
        processor_setu_ra,
        processor_setu_sp,
        processor_setu_gp,
        processor_setu_tp,
        processor_setu_t0,
        processor_setu_t1,
        processor_setu_t2,
        processor_setu_fp,
        processor_setu_s1,
        processor_setu_a0,
        processor_setu_a1,
        processor_setu_a2,
        processor_setu_a3,
        processor_setu_a4,
        processor_setu_a5,
        processor_setu_a6,
        processor_setu_a7,
        processor_setu_s2,
        processor_setu_s3,
        processor_setu_s4,
        processor_setu_s5,
        processor_setu_s6,
        processor_setu_s7,
        processor_setu_s8,
        processor_setu_s9,
        processor_setu_s10,
        processor_setu_s11,
        processor_setu_t3,
        processor_setu_t4,
        processor_setu_t5,
        processor_setu_t6
};

void registerSet(uint reg, archival_t val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setUreg[reg](val);
}

void registerSetB(uint reg, int8 val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setreg[reg](REGISTER_CLEAR_BYTE(registerGet(reg)) + val);
}

void registerSetW(uint reg, int16 val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setreg[reg](REGISTER_CLEAR_WORD(registerGet(reg)) + val);
}

void registerSetD(uint reg, int32 val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setreg[reg](REGISTER_CLEAR_DWORD(registerGet(reg)) + val);
}

void registerSetQ(uint reg, archival_t val)
{
    registerSet(reg, val);
}



void registerUSet(uint reg, archuval_t val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setUreg[reg](val);
}

void registerUSetB(uint reg, uint8 val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setUreg[reg](REGISTER_CLEAR_BYTE(registerGet(reg)) + val);
}

void registerUSetW(uint reg, uint16 val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setUreg[reg](REGISTER_CLEAR_WORD(registerGet(reg)) + val);
}

void registerUSetD(uint reg, uint32 val)
{
    if (reg == 0)
        return;
    if (reg > 31)
        RAISE(ERR_OPCODE_NUM);
    setUreg[reg](REGISTER_CLEAR_DWORD(registerGet(reg)) + val);
}

void registerUSetQ(uint reg, archuval_t val)
{
    registerUSet(reg, val);
}

void registerSetFromName(char const *name, archuval_t val)
{
    registerSet(getRegisterIdxFromName(name), val);
}