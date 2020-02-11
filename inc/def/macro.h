/*
** EPITECH PROJECT, 2018
** inline_cmp.h
** File description:
** inline_cmp.h
*/

#ifndef CMP_H_
#define CMP_H_

#include "stdbool.h"
#include "lib.h"
#include "fatalAssert.h"

#define decto(x, y) while (x --> 0)
#define incto(x, y) while (x ++< y)

#define swap(x,y) (x ^= y ^= x ^= y)

#define arrsize(x) (sizeof(x) / sizeof(*x))

#define asmv __asm__ volatile /* fire asm instruction */

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

static inline void *vmalloc(size_t size)
{
    void *ptr = malloc(size);
    fatalAssert(ptr);
    return (ptr);
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

#define retl my_putchar(0xA)

#define space my_putchar(0x20);

#endif
