#ifndef _EXTRCTOR_H_
#define _EXTRCTOR_H_

#include "env/env.h"
#include "loader/elf/loader.h"

typedef uint8 * extractor_t;

/* CODE EXTRACTOR */
uint8 extractCode(void);
extractor_t extractCodeB(void);
extractor_t extractCodeW(void);
extractor_t extractCodeD(void);
extractor_t extractCodeQ(void);

#endif