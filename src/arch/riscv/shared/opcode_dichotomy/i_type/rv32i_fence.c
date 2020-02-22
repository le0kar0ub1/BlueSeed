#include "shared/opcode_dichotomy/itype.h"
#include "shared/processor/processor.h"

void rv32i_fence(struct opcode_Itype *extracted __unused)
{
    debug_log_instr("fence");
}

void rv32i_fencei(struct opcode_Itype *extracted __unused)
{
    debug_log_instr("fence.i");
}
