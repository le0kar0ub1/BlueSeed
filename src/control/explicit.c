#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "opt/opt.h"
#include "prototypes.h"

extern bool IS_RUN_EXPLICIT;
extern bool IS_RUN_DEBUG;

void debug_log_instr(char const *fmt, ...)
{
    if (!IS_RUN_EXPLICIT && !IS_RUN_DEBUG)
        return;
    printf("[\e[0;32mINSTR EXEC\e[0m] \e[0;31m");
    va_list ap;

    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
    printf("\e[0m\n");
}