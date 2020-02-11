#include "lib.h"

void my_putstr(char const *str)
{
    write(1, str, len(str));
}
