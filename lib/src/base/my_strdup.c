#include "lib.h"

char *my_strdup(char *s)
{
    char *dup;

    if (s == NULL)
        return (NULL);
    dup = malloc(len(s) + 1);
    if (dup == NULL)
        return (NULL);
    my_strcpy(dup, s);
    return (dup);
}
