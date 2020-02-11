#include "lib.h"

char *return_get_line(char *buff, char *ret)
{
    free(buff);
    return (ret);
}

int len_tab(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}
