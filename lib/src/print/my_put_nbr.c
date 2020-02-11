#include "lib.h"

void puti(int n)
{
    int mod = 0xA, sub = 0x0, cur = 0x0;

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

void putl(long n)
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
