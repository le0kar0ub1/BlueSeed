#include "lib.h"

int nbr_char_str(char *input, char cut)
{
    int i = 0;

    for (; *input; input++)
        if (*input == cut)
            i++;
    return (i);
}
