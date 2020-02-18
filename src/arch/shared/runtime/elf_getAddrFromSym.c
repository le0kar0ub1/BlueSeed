#include "env/env.h"
#include "loader/elf/loader.h"
#include "shared/runtime/elftool.h"

extern struct env *environnement;

archElf_Sym *symtab;

void elftool_init(void)
{
    archElf_Ehdr *ehdr = environnement->host.link;
    archElf_Shdr *shdr = ADD_TO_PTR(ehdr, ehdr->e_shoff);
    char *shdrtab = (char *)(ADD_TO_PTR(ehdr, shdr[ehdr->e_shstrndx].sh_offset));
    for (uint i = 0; i < ehdr->e_shnum; i++)
        if (!strcmp(".symtab", (char *)&(shdrtab[shdr[i].sh_name]))) {
            symtab = (archElf_Sym *)ADD_TO_PTR(ehdr, shdr[i].sh_offset);
            elftool_getAddrFromSym(NULL);
            return;
        }
    RAISE(ERR_EXEC_FMT_NUM);
}

virtaddr_t elftool_getAddrFromSym(char const *sym)
{
    // if (!sym)
        // RAISE(ERR_EXEC_FMT_NUM);
    virtaddr_t off = NULL;
    for (uint i = 0; symtab[i].st_name != 0; i++);
        // printf("SYM: %s\n", );
    return (off);
}