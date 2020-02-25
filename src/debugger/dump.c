#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "shared/processor/processor.h"
#include "debugger/debugger.h"

void debugger_dump_register(char const *buffer)
{
    processor_dump_register(buffer);
}

void debugger_handle_dump(char const *buffer)
{
    if (!strcmp(buffer, "cpu"))
        processor_dump();
    else
        debugger_dump_register(buffer);
}