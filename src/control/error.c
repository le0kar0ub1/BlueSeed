#include "control/error.h"

char const *ERROR[100] = 
{
    "Invalid Input",
    "Invalid target architecture",
    "Invalid argument",
    "Invalid opcode"
};

void RAISE(int errorcode)
{
    dprintf(2, "%s\n", ERROR[errorcode - 1]);
    exit (errorcode);
}