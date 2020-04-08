#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "opt/opt.h"
#include "prototypes.h"
#include "control/config.h"
#include "processor/processor.h"

extern bool IS_RUN_EXPLICIT;
extern bool IS_RUN_DEBUG;

void debug_log_instr(char const *fmt, ...)
{
    if (!IS_RUN_EXPLICIT && !IS_RUN_DEBUG)
        return;
    archuval_t pc = processor_get_pc() - 4;
#if SYSTEMSZ == 64
    printf("    %016lx \e[0;32m", pc);
#else
    printf("    %016x \e[0;32m", pc);
#endif
    va_list ap;

    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
    printf("\e[0m\n");
}