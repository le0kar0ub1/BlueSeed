#include "lib.h"

bool my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (false);
    for (; *s1 && *s2 && *s1 == *s2; s1++, s2++);
    if (*s1 == 0x0 && *s2 == 0x0)
        return (true);
    return (false);
}
