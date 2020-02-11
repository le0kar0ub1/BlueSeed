#include "lib.h"

int matoi(char const *s)
{
    int mod = 0x1, ret = 0x0;

    for (int k = len(s) - 0x1; k >= 0x0 && s[k] != '-'; k--, mod *= 0xA) {
        if (s[k] < 0x30 || s[k] > 0x39)
            return (-0x1);
        ret += (s[k] - 0x30) * mod;
    }
    if (s[0] == '-')
        return (ret * -0x1);
    return (ret);
}

long matol(char const *s)
{
    long mod = 0x1, ret = 0x0;

    for (int k = len(s) - 0x1; k >= 0x0 && s[k] != '-'; k--, mod *= 0xA) {
        if (s[k] < 0x30 || s[k] > 0x39)
            return (-0x1);
        ret += (s[k] - 0x30) * mod;
    }
    if (s[0] == '-')
        return (ret * -0x1);
    return (ret);
}
