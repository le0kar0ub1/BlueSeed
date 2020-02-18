#include "builtin.h"
#include "hookpoint.h"
#include "loader/elf/loader.h"
#include "env/env.h"

void help(void)
{
    printf("%s is a cross-plateform RISCV processor emulator\n", PROJECT_NAME);
    printf("USAGE:\n");
    printf("    ./%s $EXEC\n", PROJECT_NAME);
    printf("Supported arch:\n    %s\n", SUPPORTED_ARCH);
    exit(0);
}

struct env *environnement;

int main(int ac, char **av)
{
    if (ac < 2)
        RAISE(ERR_INP_NUM);
    if (!strcmp(av[1], "-h") || !strcmp(av[1], "--help"))
        help();
    /* Get Opt */
    struct opt *opt = mgetopt(av);
    verbose_log("Parsing arguments...\n");
    /* ELF LOADER */
    environnement = elf_loader(opt->exec);
    /* JUMP ON THE ENTRY POINT OF THE TARGETED ARCH */
    verbose_log("Arch hookpoint entry...\n");
    arch_hookpoint();
    free_environement(environnement);
    return (0);
}
