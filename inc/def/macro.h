#ifndef CMP_H_
#define CMP_H_

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>
#include "fatalAssert.h"
#include "typedef.h"

#define decto(x) while (x --> 0)
#define incto(x, y) while (x ++< y)

#define APPLY_AND_LOWER_MASK(x, y) (x & ((1 << y) - 1))
#define APPLY_AND_UPPER_MASK(x, y) (x & ((UINT_MAX) - ((1 << y) - 1)))

#define swap(x,y) (x ^= y ^= x ^= y)

#define arrsize(x) (sizeof(x) / sizeof(*x))

#define asmv __asm__ volatile /* fire asm instruction */

#define len(x) strlen(x)

/* ALIGN ON A POWER OF 2 */
#define ROUND_POWERUP(x) (pow(2, (int)log2(x)) * 2)
static inline bool isTwoPower(uint64 x)
{
    return ((x & (x - 1)) == 0);
}

static inline uint64 ROUND_POWER2(uint64 to)
{
    if (isTwoPower(to))
        return (to);
    return (ROUND_POWERUP(to));
}

static inline bool is_num(char c)
{
    if (c <= 0x39 && c >= 0x30)
        return (true);
    return (false);
}

static inline bool sis_num(char *s)
{
    for (; *s && is_num(*s); s++);
    if (*s == 0x0)
        return (true);
    return (false);
}

static inline bool is_alpha(char c)
{
    if ((( c <= 0x5A && c >= 0x41) ||
(c <= 0x7A && c >= 0x61)) || c == 0x5f || is_num(c))
        return (true);
    return (false);
}

static inline bool sis_alpha(char *s)
{
    for (; *s && is_alpha(*s); s++);
    if (*s == 0x0)
        return (true);
    return (false);
}

static inline bool cmp(int x, int y)
{
    if (x != y)
        return (false);
    return (true);
}

static inline long absl(long x)
{
    return (x *= (x < 0x0) ? -0x1 : 0x1);
}

static inline void pexit(char const *s)
{
    if (s)
        write(2, s, len(s));
    exit(84);
}

static inline void criticalPtr(void *ptr)
{
    if (!ptr)
        exit(0);
}

static inline void critical(int val, int must)
{
    if (val != must)
        exit(0);
}

#endif
