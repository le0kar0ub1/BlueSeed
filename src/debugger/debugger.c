#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "shared/processor/processor.h"
#include "shared/debugger/debugger.h"

static char const *debugCommandAllowed[10] =
{
    "help",
    "dump cpu",
    NULL
};

char debugBuffer[100];

static void (*debugHandler[10])(void) =
{
    debugger_handler_help,
    debugger_handle_dumpReg,
    NULL
};

void debugger_handler_help(void)
{
    printf("Allowed command: (name are explicit)\n");
    for (uint i = 0; debugCommandAllowed[i]; i++)
        printf("    %s\n", debugCommandAllowed[i]);
}

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
    write(1, DEBUG_PROMPT, strlen(DEBUG_PROMPT));
    i = 0;
    for (; read(STDIN_FILENO, &buf, 1) && buf != 0xA; i++)
        debugBuffer[i] = buf;
    debugBuffer[i] = 0;
    if (!strcmp(CMD_NEXT_LONG, debugBuffer) || !strcmp(CMD_NEXT_SHORT, debugBuffer))
        return;
    for (i = 0; debugCommandAllowed[i]; i++)
        if (!strcmp(debugCommandAllowed[i], debugBuffer)) {
            debugHandler[i]();
            goto renewCommand;
        }
    if (debugBuffer[0] != 0x0)
        printf("Unhandled command...\n");
    goto renewCommand;
}