#include "lib.h"

void my_put_tab(char **tab)
{
    for (; *tab; tab++) {
        my_putstr(*tab);
        my_putchar('\n');
    }
}
