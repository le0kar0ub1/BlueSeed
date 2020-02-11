#include "lib.h"

char *my_strstr(char *str, char *find)
{
    int k = 0;

    while (*str && find[k]) {
        if (*str == find[k])
            k++;
        else
            k = 0;
    }
    if (find[k] == 0)
        return (str - k);
    return (NULL);
}
