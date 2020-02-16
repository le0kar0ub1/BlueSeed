#include "builtin.h"
#include "loader/elf/loader.h"

void elf_loader(char const *file)
{
    Elf64_Ehdr *ehdr = load_file(file);
    void *mapped = ehdr;

    if (!mapped)
        RAISE(ERR_INP_NUM);
    if (!file_header_checkup(mapped))
        RAISE(ERR_ELF_HEADER_NUM);
    printf("SIZEOF: %d %s\n", SYSTEMSZ, TARGETED_ARCH);
}