#include "env/env.h"
#include "loader/elf/loader.h"
#include "shared/runtime/elftool.h"

extern struct env *environnement;

/* Initialize during elftool_init to decrease the compute in run-time */
archElf_Ehdr *ehdr;
archElf_Shdr *shdr;
archElf_Sym  *symtab;
uint         symtab_entries;
char         *shdrtab;
char         *strtab; 

archElf_Shdr *elftool_getSectionFromName(char const *name)
{
    if (!shdr || !ehdr)
        RAISE(ERR_UNKNOW_SEC_NUM);
    for (uint i = 0; i < ehdr->e_shnum; i++)
        if (!strcmp(name, (char *)&(shdrtab[shdr[i].sh_name])))
            return (&(shdr[i]));
    RAISE(ERR_UNKNOW_SYM_NUM);
    return (NULL);
}

void *elftool_getSectionContentFromName(char const *name)
{
    if (!shdr || !ehdr)
        RAISE(ERR_UNKNOW_SEC_NUM);
    for (uint i = 0; i < ehdr->e_shnum; i++)
        if (!strcmp(name, (char *)&(shdrtab[shdr[i].sh_name])))
            return (ADD_TO_PTR(ehdr, shdr[i].sh_offset));
    RAISE(ERR_UNKNOW_SYM_NUM);
    return (NULL);
}

virtaddr_t elftool_getSecAddrFromName(char const *name)
{
    return ((virtaddr_t)(elftool_getSectionFromName(name)->sh_addr));
}

uint elftool_getSectionSizeFromName(char const *name)
{
    if (!shdr || !ehdr)
        RAISE(ERR_UNKNOW_SEC_NUM);
    for (uint i = 0; i < ehdr->e_shnum; i++)
        if (!strcmp(name, (char *)&(shdrtab[shdr[i].sh_name])))
            return ((uint)shdr[i].sh_size);
    RAISE(ERR_UNKNOW_SYM_NUM);
    return (0);
}

void elftool_init(void)
{
    ehdr = environnement->host.link;
    shdr = ADD_TO_PTR(ehdr, ehdr->e_shoff);
    shdrtab = (char *)(ADD_TO_PTR(ehdr, shdr[ehdr->e_shstrndx].sh_offset));
    symtab = (archElf_Sym *)elftool_getSectionContentFromName(".symtab");
    symtab_entries = (uint)elftool_getSectionSizeFromName(".symtab") / sizeof(archElf_Sym);
    strtab = (char *)elftool_getSectionContentFromName(".strtab");
}

virtaddr_t elftool_getAddrFromSym(char const *sym)
{
    if (!sym || !symtab || !strtab)
        RAISE(ERR_UNKNOW_SYM_NUM);
    for (uint i = 0; i < symtab_entries; i++)
        if (!strcmp(sym, (char *)ADD_TO_PTR(strtab, symtab[i].st_name)))
            return ((virtaddr_t)symtab[i].st_value);
    return (NULL);
}

char const *elftool_getSymFromAddr(virtaddr_t addr)
{
    if (!symtab || !strtab)
        RAISE(ERR_UNKNOW_SYM_NUM);
    for (uint i = 0; i < symtab_entries; i++)
        if (symtab[i].st_value == (uintptr)addr)
            return ((char *)ADD_TO_PTR(strtab, symtab[i].st_name));
    RAISE(ERR_UNKNOW_SEC_NUM);
    return (NULL);
}

