#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shared/processor/processor.h"
#include "debugger/debugger.h"
#include "def/operator.h"

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