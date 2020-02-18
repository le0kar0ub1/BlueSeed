#include "control/error.h"
#include <stdio.h>
#include <stdlib.h>

char const *errorMsg[100] = 
{
    "Invalid Input",
    "Invalid target architecture",
    "Invalid argument",
    "Invalid opcode",
    "Invalid ELF header",
    "Exec Format Error",
    "Out of memory",
    "Unknow symbol reference",
    "Unknow section reference",
    "Segmentation fault (core dumped)",
    "Unhandle system call"
};

void RAISE(int errorcode)
{
    dprintf(2, "%s\n", errorMsg[errorcode - 1]);
    exit (errorcode);
}