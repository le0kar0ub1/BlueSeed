#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "shared/processor/processor.h"
#include "control/error.h"

static char const *abiRegName[33] =
{
        "x0",
        "ra",
        "sp",
        "gp",
        "tp",
        "t0",
        "t1",
        "t2",
        "fp",
        "s1",
        "a0",
        "a1",
        "a2",
        "a3",
        "a4",
        "a5",
        "a6",
        "a7",
        "s2",
        "s3",
        "s4",
        "s5",
        "s6",
        "s7",
        "s8",
        "s9",
        "s10",
        "s11",
        "t3",
        "t4",
        "t5",
        "t6",
        NULL
};

char const *getRegisterName(uint reg)
{
    return (abiRegName[reg]);
}

bool isRegisterExistant(uint reg)
{
    if (reg > 32 || (int)reg < -1)
        return (false);
    return (true);
}

archival_t getRegisterFromName(char const *name)
{
    for (uint i = 0; abiRegName[i]; i++)
        if (!strcmp(name, abiRegName[i]))
            return (registerGet(i));
    return (0);
}

uint getRegisterIdxFromName(char const *name)
{
    for (uint i = 0; abiRegName[i]; i++)
        if (!strcmp(name, abiRegName[i]))
            return (i);
    return ((uint)-1);
}