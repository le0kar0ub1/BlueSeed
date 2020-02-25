#include "shared/opcode_dichotomy/compressed.h"
#include "shared/processor/processor.h"
#include "shared/opcode_dichotomy/itype.h"

void compressed_ldsp(struct opcode_CItype *op __unused)
{
    int off = 0;
    off += op->imm1 & 0b00111 << 6;
    off += op->imm1 & 0b11000 << 3;
    off += op->imm2 << 5;
    off *= 8;
    debug_log_instr("ld %s, %d(sp)", getRegisterName(op->rx), off);
    registerSet(op->rx, off + processor_get_sp());
}