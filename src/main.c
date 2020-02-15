#include "builtin.h"
#include "arch_entry.h"

void help(void)
{
    printf("%s is a cross-plateform RISCV processor emulator\n", PROJECT_NAME);
    printf("USAGE:\n");
    printf("    ./%s $EXEC\n", PROJECT_NAME);
    printf("Supported arch:\n    %s\n", SUPPORTED_ARCH);
    exit(0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        RAISE(ERR_INP_NUM);
    if (!strcmp(av[1], "-h") || !strcmp(av[1], "--help"))
        help();
    struct opt *opt = mgetopt(av);
    /* JUMP ON THE ENTRY POINT OF THE TARGETED ARCH */
    arch_entry_point(opt->exec);
    return (0);
}
