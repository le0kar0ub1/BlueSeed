#include "shared/opcode_dichotomy/compressed.h"
#include "shared/processor/processor.h"
#include "shared/opcode_dichotomy/itype.h"

void compressed_mv(struct opcode_CRtype *op)
{
    debug_log_instr("mv %s, %s", getRegisterName(op->rx), getRegisterName(op->rs2));
    registerSet(op->rx, registerGet(op->rs2));
}