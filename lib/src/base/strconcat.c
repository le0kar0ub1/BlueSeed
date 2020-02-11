#include "lib.h"

char *strconcat(char const *s1, char const *s2)
{
    char *new;
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    if ((new = malloc(sizeof(char) * (len(s1) + len(s2) + 1))) == NULL)
        return (NULL);
    for (; s1[i]; i++)
        new[i] = s1[i];
    for (int k = 0; s2[k]; k++, i++)
        new[i] = s2[k];
    new[i] = 0;
    return (new);
}
