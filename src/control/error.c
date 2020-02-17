#include "control/error.h"

char const *errorMsg[100] = 
{
    "Invalid Input",
    "Invalid target architecture",
    "Invalid argument",
    "Invalid opcode",
    "Invalid ELF header",
    "Exec Format Error",
    "Out of memory"
};

void RAISE(int errorcode)
{
    dprintf(2, "%s\n", errorMsg[errorcode - 1]);
    exit (errorcode);
}