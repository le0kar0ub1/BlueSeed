#include "lib.h"

void long_put(long n)
{
    long mod = 0xA, sub = 0x0, cur = 0x0;

    if (n < 0x0) {
        my_putchar('-');
        n *= -0x1;
    }
    for (; n % mod != n; mod *= 0XA);
    for (; mod != 0x1; mod /= 0xA) {
        sub = (n % (mod / 0xA));
        cur = ((n % mod) - sub) / (mod / 0XA);
        my_putchar(cur + 0x30);
    }
}

void float_put(double n, int prec)
{
    int z = 0x0;
    long part = (long)n;

    if (prec > 0x9 || prec < 0x0)
        return;
    if (n < 0x0) {
        n *= -0x1;
        my_putchar('-');
        part = (long)n;
    }
    prec = power(0xA, prec);
    long_put(part);
    my_putchar(',');
    if ((long)(n * 0xA) == 0x0) {
        for (double tmp = n; tmp != 0x0 && (long)tmp == 0x0; z++, tmp *= 0xA);
        for (; z > 0x0; z--)
            my_putchar(0x30);
    }
    n = (n - part) * prec;
    long_put((long)n);
}

void hexa_put(long long n)
{
    long long max = 0x0, ch = 0x0, save = n;

    if (n < 0) {
        my_putchar('-');
        n *= -0x1;
    }
    sput("0x");
    for (; n / 0x10 > 0; n /= 0x10, max++);
    for (; max >= 0; max--) {
        ch = n % 0x10;
        if (ch > 0x9)
            my_putchar(0x41 + (ch - 0xA));
        else
            my_putchar(ch + 0x30);
        if (max == 0x0 || max == 0x1)
            n = save;
        else
            n = save / power(max, 0x10);
    }
}

void bin_put(long long n)
{
    long long max = 0x0, ch = 0x0, save = n;

    if (n < 0) {
        my_putchar('-');
        n *= -0x1;
    }
    sput("0b");
    for (; n / 0x2 > 0; n /= 0x2, max++);
    for (; max >= 0; max--) {
        ch = n % 0x2;
        my_putchar(ch + 0x30);
        if (max == 0x0 || max == 0x1)
            n = save;
        else
            n = save / power(max, 0x2);
    }
}

void address_put(long long n)
{
    long long mod = 0xA, sub = 0x0, cur = 0x0;

    if (n < 0x0) {
        my_putchar('-');
        n *= -0x1;
    }
    for (; n % mod != n; mod *= 0XA);
    for (; mod != 0x1; mod /= 0xA) {
        sub = (n % (mod / 0xA));
        cur = ((n % mod) - sub) / (mod / 0XA);
        my_putchar(cur + 0x30);
    }
}
