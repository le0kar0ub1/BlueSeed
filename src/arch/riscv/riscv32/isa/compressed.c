#include "opcode.h"
#include "shared/opcode_dichotomy/handler.h"
#include "isa/compressed/opcode.h"
#include "shared/opcode_dichotomy/compressed.h"

void *compressedHandlerGetZero(int opcode)
{
    uint8 func  = getFuncFromCompressedCL(&opcode);
    uint8 ciw   = getFuncFromCompressedCIW(&opcode);
    switch (ciw) {
        case CADDISPN_FUNC:
            return (compressed_addi4sp);
        default:
            break;
    }
    switch (func) {
        case CFLD_FUNC:
             return (compressed_fld);
        case CLW_FUNC:
            return (compressed_lw);
        default:
            break;
    }
    func = getFuncFromCompressedCS(&opcode);
    switch (func)  {
        case CFSD_FUNC:
            return (compressed_fsd);
        case CSW_FUNC:
            return (compressed_csw);
        default:
            break;
    }
    return (NULL);
}

void *compressedHandlerGetOne(int opcode __unused)
{
    uint8 ci = getFuncFromCompressedCI(&opcode);
    switch (ci) {
        case CNOP_FUNC || CADDI_FUNC:
            if (getRxFromCompressedCI(&opcode) == 0)
                return (compressed_nop);
            return (compressed_addi);
        case CJAL_FUNC || CADDIW_FUNC:
            if (getRxFromCompressedCI(&opcode) == 0)
                return (compressed_addiw);
            return (compressed_jal);
        default:
            break;
    }
    uint8 ca  = getFuncFromCompressedCA(&opcode) & 0b111000;
    uint8 ca2 = getFuncFromCompressedCA(&opcode) & 0b000111;
    uint8 imm = getImmFromCompressedCA(&opcode);
    switch (ca) {
        case CLI_FUNC:
            return (compressed_cli);
        case CLUI_FUNC:
            return (compressed_lui);
        case CAND_FUNC || COR_FUNC || CXOR_FUNC || CSUB_FUNC || CADDW_FUNC || CSUBW_FUNC:
            switch (ca2) {
                case 0b011:
                    if (imm == 0b00)
                        return (compressed_sub);
                    else if (imm == 0b01)
                        return (compressed_xor);
                    else if (imm == 0b10)
                        return (compressed_or);
                    else /* 0b11 */
                        return (compressed_and);
                case 0b111:
                    if (imm == 0b00)
                        return (compressed_subw);
                    if (imm == 0b01)
                        return (compressed_addw);
                default:
                    break;
            }
    }
    uint8 cj = getFuncFromCompressedCJ(&opcode);
    switch (cj) {
        case CJ_FUNC:
            return (compressed_j);
        default:
            break;
    }
    uint8 cb = getFuncFromCompressedCB(&opcode);
    switch (cb) {
        case CBEQZ_FUNC:
            return (compressed_beqz);
        case CBNEZ_FUNC:
            return (compressed_bnez);
        default:
            break;
    }
    return (NULL);
}

void *compressedHandlerGetTwo(int opcode __unused)
{
    uint8 ci = getFuncFromCompressedCI(&opcode);
    switch (ci) {
        case 0b000:
            if (getImm1FromCompressedCI(&opcode) == 0 && getImm2FromCompressedCI(&opcode) == 0)
                return (compressed_slli);
            return (compressed_slli64);
        case 0b001:
            return (compressed_fldsp);
        case 0b010:
            return (compressed_lwsp);
        default:
            break;
    }
    uint8 cr = getFuncFromCompressedCR(&opcode);
    uint8 rs2 = getRS2FromCompressedCR(&opcode);
    uint8 rx = getRxFromCompressedCR(&opcode);
    switch (cr) {
        case 0b1000:
            if (rs2 == 0)
                return (compressed_jr);
            return (compressed_mv);
        case 0b1001:
            if (rs2 == 0 && rx == 0)
                return (compressed_ebreak);
            if (rs2 == 0)
                return (compressed_jalr);
            return (compressed_add);
        default:
            break;
    }
    uint8 css = getFuncFromCompressedCSS(&opcode);
    switch (css) {
        case 0b110:
            return (compressed_swsp);
        case 0b111:
            return (compressed_fswsp);
        default:
            break;
    }
    return (NULL);
}


void *getCompressedHandlerFromOpcode(int opcode)
{
    switch (COMPRESSED_OPMASK(opcode)) {
        case COMPRESSED_OP0:
            return (compressedHandlerGetZero(opcode));
            break;
        case COMPRESSED_OP1:
            return (compressedHandlerGetOne(opcode));
            break;
        case COMPRESSED_OP2:
            return (compressedHandlerGetTwo(opcode));
            break;
        case COMPRESSED_OP3:
            return (NULL);
            break;
        default:
            return (NULL);
    }
}