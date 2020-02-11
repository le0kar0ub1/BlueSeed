char *my_revstr(char *str)
{
    int count = 0;
    int count2 = 0;
    char ch = 'a';

    while (str[count] != '\0')
        count = count + 1;
    count2 = 0;
    count = count - 1;
    while (count > count2) {
        ch = str[count];
        str[count] = str[count2];
        str[count2] = ch;
        count = count - 1;
        count2 = count2 + 1;
    }
    return (str);
}
