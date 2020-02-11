#include "lib.h"

long long power(long long max, int power)
{
    long long ret = power;

    for (; max != 1; max--)
        ret *= power;
    return (ret);
}

void int_put(int n)
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

void more_types(char const *format, va_list ap, int *i)
{
    switch (format[*i]) {
    case 'c':
        my_putchar(va_arg(ap, int));
        return;
    case 'b':
        bin_put(va_arg(ap, long long));
        return;
    case 'f':
        float_put(va_arg(ap, double), format[*i + 0x1] - 0x30);
        *i += 0x1;
        return;
    default:
        my_putchar('%');
        my_putchar(format[*i]);
    }
}

void switch_types(char const *format, va_list ap, int *i)
{
    switch (format[*i]) {
        case 's':
            sput(va_arg(ap, char *));
            return;
        case 'd':
            int_put(va_arg(ap, int));
            return;
        case 'x':
            hexa_put(va_arg(ap, long long));
            return;
        case 'l':
            long_put(va_arg(ap, long));
            return;
        case 'L':
            address_put(va_arg(ap, long long));
            return;
    }
    more_types(format, ap, i);
}

void print(char const *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0x0; format[i] ; i++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        else {
            i++;
            switch_types(format, ap, &i);
        }
    }
    va_end(ap);
}
