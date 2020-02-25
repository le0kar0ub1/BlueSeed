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

#endif