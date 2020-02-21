#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "processor/processor.h"
#include "shared/debugger/debugger.h"

static char const *debugCommand[10] =
{
    "dump cpu",
    NULL
};

char debugBuffer[100];

static void (*debugHandler[10])(void) =
{
    debugger_handle_dumpReg,
    NULL
};

void debugger_handle_dumpReg(void)
{
    processor_dump();
}

void debugger_handle_next(void) {}

void debugger(void)
{
    int i = 0;
    char buf = 0;

    renewCommand:
    i = 0;
    for (; read(STDIN_FILENO, &buf, 1) && buf != 0xA; i++)
        debugBuffer[i] = buf;
    debugBuffer[i] = 0;
    if (!strcmp(CMD_NEXT_LONG, debugBuffer) || !strcmp(CMD_NEXT_SHORT, debugBuffer))
        return;
    for (i = 0; debugCommand[i]; i++)
        if (!strcmp(debugCommand[i], debugBuffer)) {
            debugHandler[i]();
            goto renewCommand;
        }
    printf("Unhandled command...\n");
    goto renewCommand;
}