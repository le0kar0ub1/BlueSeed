#include "lib.h"

int chars_to_cut(char *str, int i, char cut)
{
    int y = i, a = 0;

    for (; str[y] && str[y] != cut; y++, a++);
    if (str[y] == 0)
        return (-1);
    return (a + 2);
}

char **str_to_tab(char *str, char cut)
{
    char **tab = malloc(8 * (nbr_char_str(str, cut) + 1));
    int i = 0, j = 0, a = 0;

    if (tab == NULL)
        return (NULL);
    for (; str[i] != 0; i++, j++, a = 0) {
        if ((tab[j] = malloc(chars_to_cut(str, i, cut))) == NULL)
            return (NULL);
        for (; str[i] && str[i] != cut; i++, a++)
            tab[j][a] = str[i];
        tab[j][a] = 0;
    }
    tab[j] = NULL;
    free(str);
    return (tab);
}
