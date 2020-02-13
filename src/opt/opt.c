#include "builtin.h"
#include "opt.h"

char *opt_target_arch(char *arch)
{
    arch += strlen(TARGET_ARCH_PREFIX);
    if (!strcmp(arch, TARGET_ARCH_x86))
        return (strdup(TARGET_ARCH_x86));
    else if (!strcmp(arch, TARGET_ARCH_x64))
        return (strdup(TARGET_ARCH_x64));
    else if (!strcmp(arch, TARGET_ARCH_RISCV32))
        return (strdup(TARGET_ARCH_RISCV32));
    else if (!strcmp(arch, TARGET_ARCH_RISCV64))
        return (strdup(TARGET_ARCH_RISCV64));
    else if (!strcmp(arch, TARGET_ARCH_RISCV128))
        return (strdup(TARGET_ARCH_RISCV128));
    RAISE(ERR_ARCH_MSG, ERR_ARCH_NUM);
    return (NULL);
}

struct opt *mgetopt(char **av)
{
    struct opt *op = malloc(sizeof(struct opt));
    memset(op, 0, sizeof(struct opt));

    for (int inc = 1; av[inc]; inc++) {
        if (!strncmp(av[inc], TARGET_ARCH_PREFIX, strlen(TARGET_ARCH_PREFIX)) && !op->arch)
            op->arch = opt_target_arch(av[inc]);
        else if (!op->exec && open(av[inc], O_RDONLY) != -1)
            op->exec = av[inc];
        else
            RAISE(ERR_BADARG_MSG, ERR_BADARG_NUM);
    }
    if (!op->arch)
        op->arch = strdup(TARGET_ARCH_DEFAULT);
    return (NULL);
}