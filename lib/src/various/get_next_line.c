#include "lib.h"

char *alloc(char *str)
{
    static int ne = 2;
    char *new = malloc(sizeof(char) * (1024 * ne + 1));
    int i = 0;

    for (; str[i] != '\0'; i++)
        new[i] = str[i];
    new[i] = '\0';
    free(str);
    ne++;
    return (new);
}

char *cut_str(char **ret, char *buff, info_t *info)
{
    char *keep = NULL;
    int j = 0, h = 0;

    buff[info->size] = '\0';
    for (; buff[j] != '\0'; j++, info->iter = info->iter + 1) {
        info->bol = (buff[j] == '\n') ? 1 : 0;
        if (info->bol == 1)
            break;
        (*ret)[info->iter] = buff[j];
    }
    (*ret)[info->iter] = '\0';
    if (buff[j] == '\n') {
        keep = malloc(sizeof(char) * (1024 - j + 2));
        for (; buff[j + 1] != '\0'; h++, j++)
            keep[h] = buff[j + 1];
        keep[h] = '\0';
    }
    if (buff[j] == '\0' && info->size < 1024 && info->iter != 0)
        info->bol = 1;
    return (keep);
}

char *backline_in_keep(char *keep, char **ret)
{
    char *new_k = malloc(sizeof(char) * (1024 + 1));
    int i = 0;
    int k = 0;

    for (; keep[i] != '\n'; i++)
        (*ret)[i] = keep[i];
    (*ret)[i] = '\0';
    i++;
    for (; keep[i] != '\0'; i++, k++)
        new_k[k] = keep[i];
    new_k[k] = '\0';
    return (new_k);
}

int intra_getline(info_t *info, char **keep, char **ret, int in_k)
{
    int h = 0;

    in_k = 0;
    info->iter = 0;
    info->bol = 0;
    info->size = 1024;
    info->nbr_null = 0;
    if (*keep != NULL) {
        for (; (*keep)[h] != '\0' && (*keep)[h] != '\n'; h++, info->iter++) {
            (*ret)[info->iter] = (*keep)[h];
        }
        if ((*keep)[h] == '\n') {
            in_k = 1;
            *keep = backline_in_keep(*keep, ret);
            return (in_k);
        }
        (*ret)[info->iter] = '\0';
        *ret = alloc(*ret);
    }
    *keep = NULL;
    return (in_k);
}

char *get_next_line(int fd)
{
    char *buff = malloc(sizeof(char) * (1024 + 1));
    char *ret = malloc(sizeof(char) * (1024 + 2));
    static char *keep;
    static int nbr = 0, in_k = 0;
    info_t *info = malloc(sizeof(info_t));

    if (fd < 0 || (nbr > 2 && fd != 0) || ret == NULL || buff == NULL)
        return (NULL);
    in_k = intra_getline(info, &keep, &ret, in_k);
    if (in_k == 1)
        return (ret);
    while (1) {
        info->size = read(fd, buff, 1024);
        if ((nbr > 2 && fd != 0) || (info->size == -1) || (info->size == 0))
            return (NULL);
        nbr = info->size < 1024 ? nbr + 1 : nbr;
        keep = cut_str(&ret, buff, info);
        if (info->bol == 1)
            return (return_get_line(buff, ret));
        ret = alloc(ret);
    }
}
