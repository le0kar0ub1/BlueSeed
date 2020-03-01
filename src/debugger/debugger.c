#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shared/processor/processor.h"
#include "debugger/debugger.h"
#include "def/operator.h"

static char const *debugCommandAllowed[10] =
{
    "help",
    "dump",
    "exit",
    "jump",
    "set",
    NULL
};

char debugBuffer[100];

static void (*debugHandler[10])(char const *) =
{
    debugger_handle_help,
    debugger_handle_dump,
    debugger_handle_exit,
    debugger_handle_jump,
    debugger_handle_set,
    NULL
};

void debugger_handle_set(char const *set)
{
    char *div = (char *)set;
    uint parse = 0;

    for (; div[parse] && div[parse] != 0x20; parse++);
    div[parse] = 0;
    for (; div[parse] && div[parse] == 0x20; parse++);
    parse++;
    if (!isRegisterExistant(getRegisterIdxFromName(div)))
        printf("Invalid Register...\n");
    else
        registerSetFromName(set, (archuval_t)strtol(ADD_TO_PTR(div, parse), NULL, 0));
}

void debugger_handle_jump(char const *set)
{
    archuval_t jmp = (archuval_t)(int)strtol(set, NULL, 0);
    processor_set_pc(jmp);
}

void debugger_handle_help(char const *unused __unused)
{
    printf("Allowed command:\n");
    printf("    help\n");
    printf("    dump [cpu | regX]\n");
    printf("    exit\n");
    printf("    jump [ADDR]\n");
    printf("    set  [regX]\n");
    printf("    next [SKIP]\n");
}

void debugger_handle_exit(char const *unused __unused)
{
    exit(0);
}

uint debugger_handle_next(char const *buffer)
{
    uint skip = (uint)strtol(buffer, NULL, 0) - 1;
    return (skip);
}

void debugger(void)
{
    static uint skip = 0;
    int i = 0;
    char buf = 0;

    if (skip > 0) {
        skip--;
        return;
    }
    renewCommand:
    write(1, DEBUG_PROMPT, strlen(DEBUG_PROMPT));
    i = 0;
    for (; read(STDIN_FILENO, &buf, 1) && buf != 0xA; i++)
        debugBuffer[i] = buf;
    if (i == 0)
        debugger_handle_exit(NULL);
    debugBuffer[i] = 0;
    if (!strncmp(CMD_NEXT_LONG, debugBuffer, strlen(CMD_NEXT_LONG))) {
        if (!strcmp(CMD_NEXT_LONG, debugBuffer))
            return;
        skip = debugger_handle_next(debugBuffer + strlen(CMD_NEXT_LONG) + 1);
        return;
    }
    for (i = 0; debugCommandAllowed[i]; i++)
        if (!strncmp(debugCommandAllowed[i], debugBuffer, strlen(debugCommandAllowed[i]))) {
            debugHandler[i](debugBuffer + strlen(debugCommandAllowed[i]) + 1);
            goto renewCommand;
        }
    if (debugBuffer[0] != 0x0)
        printf("Unhandled command...\n");
    goto renewCommand;
}