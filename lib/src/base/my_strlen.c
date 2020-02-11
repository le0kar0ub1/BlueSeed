int my_strlen(char const *str)
{
    int a = 0;

    for (; str[a]; a++);
    return (a);
}
