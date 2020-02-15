#include "riscv_instructionBase.h"
#include "riscv64/opcode.h"
#include "rv32i_is.h"

void handle_prefix(uint op)
{
    
}

static struct opcodeHandler prefix =
{
    .prefix  = {
                /* B-TYPE */
                {RV32I_BRANCH_OPCODE},

                /* I-Type */
                {RV32I_LOAD_OPCODE, RV32I_OPIMM_OPCODE, RV32I_SHIFTIMM_OPCODE,
                RV32I_FENCE_OPCODE, RV32I_CALL_BREAK_OPCODE, RV32I_CSR_OPCODE},

                /* S-Type */
                {RV32I_STORE_OPCODE},

                /* R Type */
                {RV32I_OP_OPCODE},

                /* U-Type */
                {LUI_OPCODE, AUIPC_OPCODE},

                /* J-Type */
                {JAL_OPCODE},

                /* R4-Type */
                {JALR_OPCODE},

                NULL
               },
    .handler = {
            opcode_handler_Btype,
            opcode_handler_Itype,
            opcode_handler_Stype,
            opcode_handler_Rtype,
            opcode_handler_Utype,
            opcode_handler_Jtype,
            opcode_handler_R4type
    }
};
