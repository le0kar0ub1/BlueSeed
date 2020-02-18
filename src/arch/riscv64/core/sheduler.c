#include "builtin.h"
#include "hookpoint.h"
#include "env/env.h"
#include "shared/memory/stack.h"
#include "processor/processor.h"
#include "shared/runtime/extractor.h"
#include "opcode.h"
#include "shared/runtime/dump.h"

void arch_exec(void)
{
    // while(1);
    dumpInstrD(extractCodeD());
}