#include "shared/opcode_dichotomy/compressed.h"

uint rvcRegisterToNorm(uint rvc)
{
    return (rvc + 8);
}

uint normToRvcRegister(uint norm)
{
    return (norm - 8);
}