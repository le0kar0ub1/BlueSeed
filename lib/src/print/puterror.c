#include "lib.h"

void puterror(char *s)
{
    for (; *s; s++)
        write(2, s, 1);
}
