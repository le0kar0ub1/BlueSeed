#include "builtin.h"
#include "loader/elf/loader.h"

void elf_loader(char const *file)
{
    struct env *loader = load_file(file);

    if (!loader)
        RAISE(ERR_INP_NUM);
    verbose_log("ELF header checkup...\n");
    if (!file_header_checkup(loader->host.link))
        RAISE(ERR_ELF_HEADER_NUM);
    virtual_loading(loader);
    archElf_Ehdr *ehdr = loader->host.link;
    archElf_Shdr *shdr = ADD_TO_PTR(ehdr, ehdr->e_shoff);
    char *shdrtab = (char *)(ADD_TO_PTR(ehdr, shdr[ehdr->e_shstrndx].sh_offset));
    for (uint i = 0; i < ehdr->e_shnum; i++) {
        printf("SECTION: %s\n", (char *)&(shdrtab[shdr[i].sh_name]));
    }
}