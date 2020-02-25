#ifndef _COMPRESSED_OPCODE_H_
#define _COMPRESSED_OPCODE_H_

#if SYSTEMSZ == 64
/*
** RISCV-V 64
** COMPRESSED OPCODE
*/

    enum COP0
    {
        CADDISPN_FUNC = 0b000,
        CFLD_FUNC     = 0b001,
        CLW_FUNC      = 0b010,
        CLD_FUNC      = 0b011,
        /* RESERVED */
        CFSD_FUNC     = 0b101,
        CSW_FUNC      = 0b110,
        CSD_FUNC      = 0b111,
    };

    enum COP1
    {
        CNOP_FUNC      = 0b000,
        CADDI_FUNC     = 0b000,
        CJAL_FUNC      = 0b001,
        CADDIW_FUNC    = 0b001,
        CLI_FUNC       = 0b010,
        CLUI_FUNC      = 0b011,
        CAND_FUNC      = 0b100,
        COR_FUNC       = 0b100,
        CXOR_FUNC      = 0b100,
        CSUB_FUNC      = 0b100,
        CADDW_FUNC     = 0b100,
        CSUBW_FUNC     = 0b100,
        CJ_FUNC        = 0b101,
        CBEQZ_FUNC     = 0b110,
        CBNEZ_FUNC     = 0b111,
    };

    enum COP2
    {
        CSLLI_FUNC  = 0b000,
        CFLDSP_FUNC = 0b001,
        CLWSP_FUNC  = 0b010,
        CLSDP_FUNC  = 0b011,
        CMV_FUNC    = 0b100,
        CJR_FUNC    = 0b100,
        CADD_FUNC   = 0b100,
        CFSDP_FUNC  = 0b101,
        CSWSP_FUNC  = 0b110,
        CSDSP_FUNC  = 0b111,
    };

#else

/*
** RISC-V 32
** COMPRESSED OPCODE
*/

    enum COP0
    {
        CADDISPN_FUNC = 0b000,
        CFLD_FUNC     = 0b001,
        CLW_FUNC      = 0b010,
        CFLW_FUNC     = 0b011,
        /* RESERVED */
        CFSD_FUNC     = 0b101,
        CSW_FUNC      = 0b110,
        CFSW_FUNC     = 0b111,
    };

    enum COP1
    {
        CNOP_FUNC    = 0b000,
        CADDI_FUNC   = 0b000,
        CJAL_FUNC    = 0b001,
        CADDIW_FUNC  = 0b001,
        CLI_FUNC     = 0b010,
        CLUI_FUNC    = 0b011,
        CAND_FUNC    = 0b100,
        COR_FUNC     = 0b100,
        CXOR_FUNC    = 0b100,
        CSUB_FUNC    = 0b100,
        CADDW_FUNC   = 0b100,
        CSUBW_FUNC   = 0b100,
        CJ_FUNC      = 0b101,
        CBEQZ_FUNC   = 0b110,
        CBNEZ_FUNC   = 0b111,
    };

    enum COP2
    {
        CSLLI_FUNC  = 0b000,
        CFLDSP_FUNC = 0b001,
        CLWSP_FUNC  = 0b010,
        CFLWSP_FUNC = 0b011,
        CMV_FUNC    = 0b100,
        CJALR_FUNC  = 0b100,
        CADD_FUNC   = 0b100,
        CFSDP_FUNC  = 0b101,
        CWSP_FUNC   = 0b110,
        CSWSP_FUNC  = 0b111,
    };
#endif

#endif