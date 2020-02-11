#include "lib.h"

char **file_to_tab(char *file)
{
    char **tab;
    char *buffer;
    int fd = open(file, O_RDONLY), alloc = 1;

    if (fd == -1)
        return (NULL);
    for (; (buffer = get_next_line(fd)) != NULL; alloc++)
        free(buffer);
    tab = malloc(8 * alloc);
    close(fd);
    if ((fd = open(file, O_RDONLY)) == -1)
        return (NULL);
    for (alloc = 0; (buffer = get_next_line(fd)) != NULL; alloc++)
        tab[alloc] = buffer;
    tab[alloc] = NULL;
    close(fd);
    return (tab);
}
