#include "builtin.h"
#include "hookpoint.h"
#include "loader/elf/loader.h"
#include "env/env.h"

void help(void)
{
    printf("%s is a cross-plateform RISCV emulator\n", PROJECT_NAME);
    printf("Built here for emulating %s target and running on %s machine\n", TARGETED_ARCH, ARCH_HOST);
    printf("\nUSAGE:\n");
    printf("    ./%s $EXEC [...options]\n", PROJECT_NAME);
    printf("\nOPTIONS:\n");
    printf("    - `--verbose`   : display information during environnement init\n");
    printf("    - `--explicit`  : display the current executed instruction\n");
    printf("    - `--debug`     : debug environnement (CLI)\n");
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
    /* AFTER-LOADING ENVIRONNEMMENT SETUP */
    init_environnement();
    /* JUMP ON THE ENTRY POINT OF THE TARGETED ARCH */
    verbose_log("Arch hookpoint entry...\n");
    arch_hookpoint();
    /* ENVIRONNEMENT CLEANUP */
    exit_environnement();
    free_environement(environnement);
    return (0);
}
