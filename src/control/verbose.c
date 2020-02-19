#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "opt/opt.h"
#include "prototypes.h"

extern bool IS_RUN_VERBOSE;

void verbose_log(char const *fmt, ...)
{
    if (!IS_RUN_VERBOSE)
        return;
    printf("[\e[0;34mBlueSeed\e[0m] ");
    va_list ap;

    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}
