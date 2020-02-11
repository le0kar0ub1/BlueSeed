#include "lib.h"

char *int_to_char(int nbr)
{
    int keep = 0;
    int mod = 10;
    int alloc = 1;
    int i = 0;
    char *str;

    for (int count = 1; count < nbr; alloc++)
        count = count * 10;
    if ((str = malloc(sizeof(char) * (alloc + 1))) == NULL)
        return (NULL);
    for (; keep != nbr; i++) {
        str[i] = (nbr % mod - keep) / (mod / 10) + 48;
        keep = nbr % mod;
        mod = mod * 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
