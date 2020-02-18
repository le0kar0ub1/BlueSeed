#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "def/typedef.h"

#ifdef DEBUG
    #define ARE_ASSERT_FATAL 0x1
#else
    #define ARE_ASSERT_FATAL 0x0
#endif

/* Compile-time macro */
#if SYSTEMSZ == 64
    typedef uint64 *archptr_t;
    typedef uint64  archval_t;
#else
    typedef uint32 *archptr_t;
    typedef uint32  archval_t;
#endif

#endif