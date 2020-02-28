#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shared/processor/processor.h"
#include "debugger/debugger.h"

static char const *debugCommandAllowed[10] =
{
    "help",
    "dump",
    "exit",
    NULL
};

char debugBuffer[100];

static void (*debugHandler[10])(char const *) =
{
    debugger_handle_help,
    debugger_handle_dump,
    debugger_handle_exit,
    NULL
};

void debugger_handle_help(char const *unused __unused)
{
    printf("Allowed command:\n");
    printf("    help\n");
    printf("    dump [cpu | regX]\n");
    printf("    exit\n");
}

void debugger_handle_exit(char const *unused __unused)
{
    exit(0);
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
    if (i == 0)
        debugger_handle_exit(NULL);
    debugBuffer[i] = 0;
    if (!strcmp(CMD_NEXT_LONG, debugBuffer) || !strcmp(CMD_NEXT_SHORT, debugBuffer))
        return;
    for (i = 0; debugCommandAllowed[i]; i++)
        if (!strncmp(debugCommandAllowed[i], debugBuffer, strlen(debugCommandAllowed[i]))) {
            debugHandler[i](debugBuffer + strlen(debugCommandAllowed[i]) + 1);
            goto renewCommand;
        }
    if (debugBuffer[0] != 0x0)
        printf("Unhandled command...\n");
    goto renewCommand;
}