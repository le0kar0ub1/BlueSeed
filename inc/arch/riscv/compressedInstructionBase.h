#ifndef _COMPRESSED_INSTRUCTION_H_
#define _COMPRESSED_INSTRUCTION_H_

#include "def/typedef.h"
#include "def/keyword.h"

struct opcode_CRtype
{
    uint opcode : 2;
    uint rs2    : 5;
    uint rx     : 5;
    uint funct4 : 4;
} __packed;

static inline int getFuncFromCompressedCR(int *opcode)
{
    return (((struct opcode_CRtype *)opcode)->funct4);
}

static inline int getRS2FromCompressedCR(int *opcode)
{
    return (((struct opcode_CRtype *)opcode)->rs2);
}

static inline int getRxFromCompressedCR(int *opcode)
{
    return (((struct opcode_CRtype *)opcode)->rx);
}


struct opcode_CItype
{
    uint opcode : 2;
    uint imm1   : 5;
    uint rx     : 5;
    uint imm2   : 1;
    uint funct3 : 3;
} __packed;

static inline int getFuncFromCompressedCI(int *opcode)
{
    return (((struct opcode_CItype *)opcode)->funct3);
}

static inline int getRxFromCompressedCI(int *opcode)
{
    return (((struct opcode_CItype *)opcode)->rx);
}

static inline int getImm1FromCompressedCI(int *opcode)
{
    return (((struct opcode_CItype *)opcode)->imm1);
}

static inline int getImm2FromCompressedCI(int *opcode)
{
    return (((struct opcode_CItype *)opcode)->imm2);
}

struct opcode_CSStype
{
    uint opcode : 2;
    uint rs2    : 5;
    uint imm    : 6;
    uint funct3 : 3;
} __packed;

static inline int getFuncFromCompressedCSS(int *opcode)
{
    return (((struct opcode_CSStype *)opcode)->funct3);
}


struct opcode_CIWtype
{
    uint opcode : 2;
    uint rd     : 3;
    uint imm    : 10;
    uint funct3 : 3;
} __packed;

static inline int getFuncFromCompressedCIW(int *opcode)
{
    return (((struct opcode_CIWtype *)opcode)->funct3);
}

struct opcode_CLtype
{
    uint opcode : 2;
    uint rd     : 3;
    uint imm1   : 2;
    uint rs1    : 3;
    uint imm2   : 3;
    uint funct3 : 3;
} __packed;

static inline int getFuncFromCompressedCL(int *opcode)
{
    return (((struct opcode_CLtype *)opcode)->funct3);
}

struct opcode_CStype
{
    uint opcode : 2;
    uint rs2    : 3;
    uint imm1   : 2;
    uint rs1    : 3;
    uint imm2   : 3;
    uint funct3 : 3;
} __packed;

static inline int getFuncFromCompressedCS(int *opcode)
{
    return (((struct opcode_CStype *)opcode)->funct3);
}

struct opcode_CAtype
{
    uint opcode : 2;
    uint rs2    : 3;
    uint imm1   : 2;
    uint rs1    : 3;
    uint funct6 : 6;
} __packed;

static inline int getFuncFromCompressedCA(int *opcode)
{
    return (((struct opcode_CAtype *)opcode)->funct6);
}

static inline int getImmFromCompressedCA(int *opcode)
{
    return (((struct opcode_CAtype *)opcode)->imm1);
}

struct opcode_CBtype
{
    uint opcode : 2;
    uint offset : 5;
    uint rs1    : 3;
    uint imm2   : 3;
    uint funct3 : 3;
} __packed;

static inline int getFuncFromCompressedCB(int *opcode)
{
    return (((struct opcode_CBtype *)opcode)->funct3);
}

struct opcode_CJtype
{
    uint opcode : 2;
    uint target : 11;
    uint funct3 : 3;
} __packed;

static inline int getFuncFromCompressedCJ(int *opcode)
{
    return (((struct opcode_CJtype *)opcode)->funct3);
}

#endif