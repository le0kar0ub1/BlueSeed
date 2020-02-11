char *my_strcpy(char *dest, char const *src)
{
    for (; *src; src++, dest++)
        *dest = *src;
    *dest = 0;
    return (dest);
}
