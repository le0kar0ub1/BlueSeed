#ifndef _FATAL_ASSERT_H
#define _FATAL_ASSERT_H

#include "keyword.h"
#include "stdio.h"
#include "config.h"

static inline void CRASH(void)
{
    dprintf(2, "Program Crashed\n");
    exit(84);
}

#if ARE_ASSERT_FATAL
    #define fatalAssert(expr) if (__unexpected(!(expr))) {dprintf(2, \
        "assert(%s) failed\n    file: %s\n    function: %s\n    line: %d.\n", \
         #expr, __FILE__, __func__, __LINE__); CRASH();}
#else
    #define fatalAssert(expr)
#endif

/* PANIC IF ASSERT FAILED */
#define assert_eq(a, b)  fatalAssert((a) == (b))
#define assert_ne(a, b)  fatalAssert((a) != (b))
#define assert_lg(a, b)  fatalAssert((a) < (b))
#define assert_le(a, b)  fatalAssert((a) <= (b))
#define assert_gt(a, b)  fatalAssert((a) > (b))
#define assert_ge(a, b)  fatalAssert((a) > (b))

#endif
