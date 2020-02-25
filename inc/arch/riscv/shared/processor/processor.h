#ifndef _PROCESSOR_CONTEXT_H_
#define _PROCESSOR_CONTEXT_H_

#include <stdbool.h>

#include "def/typedef.h"
#include "def/keyword.h"
#include "control/config.h"

typedef archuval_t reg_t;

#include "get_register.h"
#include "set_register.h"

void processor_dump_register(char const *);
void processor_dump(void);
void processor_udump(void);

char const *getRegisterName(uint);
archival_t getRegisterFromName(char const *);
uint getRegisterIdxFromName(char const *);
bool isRegisterExistant(uint);

#define REGISTER_CLEAR_BYTE(x)  (x & ((1 << 8) - 1))
#define REGISTER_CLEAR_WORD(x)  (x & ((1 << 16) - 1))
#define REGISTER_CLEAR_DWORD(x) ((uint32)(x & ((((uint64)1 << 32)) - 1)))
#define REGISTER_CLEAR_QWORD(x) ((uint64)(x & ((((uint64)1 << 64)) - 1)))

int64  registerGet(uint);
int8   registerGetB(uint);
int16  registerGetW(uint);
int32  registerGetD(uint);
int64  registerGetQ(uint);
uint64 registerUGet(uint);
uint8  registerUGetB(uint);
uint16 registerUGetW(uint);
uint32 registerUGetD(uint);
uint64 registerUGetQ(uint);

void registerSet(uint,   int64);
void registerSetB(uint,  int8);
void registerSetW(uint,  int16);
void registerSetD(uint,  int32);
void registerSetQ(uint,  int64);
void registerUSet(uint,  uint64);
void registerUSetB(uint, uint8);
void registerUSetW(uint, uint16);
void registerUSetD(uint, uint32);
void registerUSetQ(uint, uint64);


struct abiprocessor {
    reg_t zero; /* zero-hardwired */
    reg_t ra;   /* Adress return */
    reg_t sp;   /* Stack pointer */
    reg_t gp;   /* Global pointer */
    reg_t tp;   /* thread pointer */

    reg_t t0;   /* temporary register - Alternate link register */
    reg_t t1;   /* temporary register */
    reg_t t2;   /* temporary register */

    reg_t fp;   /* frame pointer | s0 */

    reg_t s1;   /* saved register */

    reg_t a0;   /* function arguments */
    reg_t a1;   /* function arguments */
    reg_t a2;   /* function arguments */
    reg_t a3;   /* function arguments */
    reg_t a4;   /* function arguments */
    reg_t a5;   /* function arguments */
    reg_t a6;   /* function arguments */
    reg_t a7;   /* function arguments */

    reg_t s2;   /* saved register */
    reg_t s3;   /* saved register */
    reg_t s4;   /* saved register */
    reg_t s5;   /* saved register */
    reg_t s6;   /* saved register */
    reg_t s7;   /* saved register */
    reg_t s8;   /* saved register */
    reg_t s9;   /* saved register */
    reg_t s10;  /* saved register */
    reg_t s11;  /* saved register */

    reg_t t3;   /* temporary register */
    reg_t t4;   /* temporary register */
    reg_t t5;   /* temporary register */
    reg_t t6;   /* temporary register */



    reg_t ft0;   /* FP temporary */
    reg_t ft1;   /* FP temporary */
    reg_t ft2;   /* FP temporary */
    reg_t ft3;   /* FP temporary */
    reg_t ft4;   /* FP temporary */
    reg_t ft5;   /* FP temporary */
    reg_t ft6;   /* FP temporary */
    reg_t ft7;   /* FP temporary */

    reg_t fs0;   /* FP saved register */
    reg_t fs1;   /* FP saved register */
    reg_t fa0;   /* FP argument/ret value */
    reg_t fa1;   /* FP argument/ret value */
    reg_t fa2;   /* FP argument */
    reg_t fa3;   /* FP argument */
    reg_t fa4;   /* FP argument */
    reg_t fa5;   /* FP argument */
    reg_t fa6;   /* FP argument */
    reg_t fa7;   /* FP argument */

    reg_t fs2;   /* FP saved register */
    reg_t fs3;   /* FP saved register */
    reg_t fs4;   /* FP saved register */
    reg_t fs5;   /* FP saved register */
    reg_t fs6;   /* FP saved register */
    reg_t fs7;   /* FP saved register */
    reg_t fs8;   /* FP saved register */
    reg_t fs9;   /* FP saved register */
    reg_t fs10;  /* FP saved register */
    reg_t fs11;  /* FP saved register */

    reg_t ft8;   /* FP temporary */
    reg_t ft9;   /* FP temporary */
    reg_t ft10;  /* FP temporary */
    reg_t ft11;  /* FP temporary */


    reg_t pc;   /* PROGRAM COUNTER */
} __packed;

void processor_init(void);
void processor_destroy(void);
void processor_set_stackptr(uintptr ptr);

struct riscv64_processor {
    reg_t x0;  /* UN-USABLE REGISTER (raise exception else) */
    reg_t x1;  /* Adress return */
    reg_t x2;  /* Stack pointer */
    reg_t x3;  /* Global pointer */
    reg_t x4;  /* thread pointer */
    reg_t x5;  /* temporary register - Alternate link register */
    reg_t x6;  /* temporary register */
    reg_t x7;  /* temporary register */
    reg_t x8;  /* frame pointer */
    reg_t x9;  /* saved register */
    reg_t x10; /* function arguments */
    reg_t x11; /* function arguments */
    reg_t x12; /* function arguments */
    reg_t x13; /* function arguments */
    reg_t x14; /* function arguments */
    reg_t x15; /* function arguments */
    reg_t x16; /* function arguments */
    reg_t x17; /* function arguments */
    reg_t x18; /* saved register */
    reg_t x19; /* saved register */
    reg_t x20; /* saved register */
    reg_t x21; /* saved register */
    reg_t x22; /* saved register */
    reg_t x23; /* saved register */
    reg_t x24; /* saved register */
    reg_t x25; /* saved register */
    reg_t x26; /* saved register */
    reg_t x27; /* saved register */
    reg_t x28; /* temporary register */
    reg_t x29; /* temporary register */
    reg_t x30; /* temporary register */
    reg_t x31; /* temporary register */
    reg_t pc;  /* PROGRAM COUNTER */
} __packed;

#endif