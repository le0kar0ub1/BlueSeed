#ifndef _EXTRCTOR_H_
#define _EXTRCTOR_H_

#include "def/typedef.h"
#include "env/env.h"
#include "loader/elf/loader.h"

typedef uint8  extractor8_t;
typedef uint16 extractor16_t;
typedef uint32 extractor32_t;
typedef uint64 extractor64_t;

/* CODE EXTRACTOR */
uint8 extractCode(void);
extractor8_t  extractCodeB(void);
extractor16_t extractCodeW(void);
extractor32_t extractCodeD(void);
extractor64_t extractCodeQ(void);

#endif