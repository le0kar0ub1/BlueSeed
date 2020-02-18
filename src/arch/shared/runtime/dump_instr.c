#include "shared/runtime/dump.h"
#include <stdio.h>

void dumpInstrB(uint8 op)
{
    printf("%01x\n", op);
}

void dumpInstrW(uint16 op)
{
    printf("%02x\n", op);
}

void dumpInstrD(uint32 op)
{
    printf("%04x\n", op);
}

void dumpInstrQ(uint64 op)
{
    printf("%08lx\n", op);
}
