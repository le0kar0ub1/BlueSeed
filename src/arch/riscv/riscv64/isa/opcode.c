#include "opcode.h"
#include "shared/opcode_dichotomy/handler.h"
#include "isa/rv32i/opcode.h"
#include "isa/rv64i/opcode.h"
#include "isa/rv32m/opcode.h"
#include "isa/rv64m/opcode.h"

static struct opcodeHandler riscvopcode =
{
    .opcode  = {
                /* B-TYPE */
                {RV32I_BRANCH_OPCODE},

                /* I-Type */
                {RV32I_LOAD_OPCODE, RV32I_OPIMM_OPCODE, RV32I_SHIFTIMM_OPCODE,
                RV32I_FENCE_OPCODE, RV32I_CALL_BREAK_OPCODE, RV32I_CSR_OPCODE},

                /* S-Type */
                {RV32I_STORE_OPCODE},

                /* R Type */
                {RV32I_OP_OPCODE, RV32M_OPCODE},

                /* U-Type */
                {LUI_OPCODE, AUIPC_OPCODE},

                /* J-Type */
                {JAL_OPCODE},

                /* R4-Type */
                {JALR_OPCODE}
               },
    .handler = {
            opcode_handler_Btype,
            opcode_handler_Itype,
            opcode_handler_Stype,
            opcode_handler_Rtype,
            opcode_handler_Utype,
            opcode_handler_Jtype,
            opcode_handler_R4type,
            NULL
    }
};

bool isOpcodeInIndex(uint typeidx, uint subidx, uint val)
{
    if ((uint)riscvopcode.opcode[typeidx][subidx] == val)
        return (true);
    return (false);
}

void *getHandlerFromOpcode(int opcode)
{
    for (uint i = 0; i < RISCV_OPCODE_TYPE_MAX - 1; i++) {
        for (uint j = 0; riscvopcode.opcode[i][j]; j++) {
            if (opcode == riscvopcode.opcode[i][j])
                return (riscvopcode.handler[i]);
        }
    }
    RAISE(ERR_OPCODE_NUM);
    return (NULL);
}