#include "shared/opcode_dichotomy/compressed.h"
#include "shared/processor/processor.h"
#include "shared/opcode_dichotomy/itype.h"

void compressed_ld(struct opcode_CLtype *op __unused)
{
    // debug_log_instr("ld %s, %s", getRegisterName(op->rx), getRegisterName(op->rs2));
    // registerSet(op->rx, registerGet(op->rs2));
    printf("LDDDDDDDDDDd\n");
}