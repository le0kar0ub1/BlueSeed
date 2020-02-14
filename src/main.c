#include "builtin.h"

void help(void)
{
    printf("%s is a multi-arch emulator\n", PROJECT_NAME);
    printf("USAGE:\n");
    printf("    ./%s --target=$ARCH $TOEXEC\n", PROJECT_NAME);
    printf("Supported arch:\n    %s\n", SUPPORTED_ARCH);
    exit(0);
}

int main(int ac, char **av)
{
    if (ac < 1)
        RAISE(ERR_INP_NUM);
    if (!strcmp(av[1], "-h") || !strcmp(av[1], "--help"))
        help();
    struct opt *opt = mgetopt(av);
    arch_entry_point(opt);
    return (0);
}
