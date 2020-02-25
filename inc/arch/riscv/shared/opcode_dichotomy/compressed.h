#ifndef _INSTR_PSUDOTYPE_H_
#define _INSTR_PSUDOTYPE_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "shared/runtime/extractor.h"

#include "compressedInstructionBase.h"
#include "shared/processor/processor.h"

/* compressed opcodes are defined on 2 bits */
#define COMPRESSED_OPMASK(x) (x & 0b11)

#define COMPRESSED_OP0 0
#define COMPRESSED_OP1 1
#define COMPRESSED_OP2 2
#define COMPRESSED_OP3 3

void *compressedHandlerGetZero(int);
void *compressedHandlerGetOne(int);
void *compressedHandlerGetTwo(int);

static inline void compressed_fld(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_fld\n");
}
static inline void compressed_lw(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_lw\n");
}
void compressed_ld(struct opcode_CLtype *);

static inline void compressed_fsd(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_fsd\n");
}
static inline void compressed_csw(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_csw\n");
}
static inline void compressed_sd(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_sd\n");
}
static inline void compressed_nop(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_nop\n");
}
static inline void compressed_addi(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_addi\n");
}
static inline void compressed_addiw(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_addiw\n");
}
static inline void compressed_jal(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_jal\n");
}
static inline void compressed_cli(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_cli\n");
}
static inline void compressed_lui(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_lui\n");
}
static inline void compressed_sub(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_sub\n");
}
static inline void compressed_xor(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_xor\n");
}
static inline void compressed_or(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_or\n");
}
static inline void compressed_and(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_and\n");
}
static inline void compressed_subw(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_subw\n");
}
static inline void compressed_addw(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_addw\n");
}
static inline void compressed_j(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_j\n");
}
static inline void compressed_beqz(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_beqz\n");
}
static inline void compressed_bnez(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_bnez\n");
}
static inline void compressed_slli(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_slli\n");
}
static inline void compressed_slli64(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_slli64\n");
}
static inline void compressed_fldsp(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_fldsp\n");
}
static inline void compressed_lwsp(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_lwsp\n");
}
static inline void compressed_ldsp(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_ldsp\n");
}
static inline void compressed_jr(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_jr\n");
}

void compressed_mv(struct opcode_CRtype *);

static inline void compressed_ebreak(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_ebreak\n");
}
static inline void compressed_jalr(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_jalr\n");
}
static inline void compressed_add(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_add\n");
}
static inline void compressed_fsdsp(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_fsdsp\n");
}
static inline void compressed_swsp(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_swsp\n");
}
static inline void compressed_fswsp(int *opcode __unused)
{
    printf("INSTR UNHANDLED: compressed_fswsp\n");
}

#endif