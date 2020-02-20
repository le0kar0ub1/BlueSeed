#include "env/env.h"
#include "loader/elf/loader.h"
#include "shared/runtime/elftool.h"

extern struct env *environnement;

/* Initialized during elftool_init to decrease the compute in run-time */
extern archElf_Ehdr *ehdr;
extern archElf_Phdr *phdr;
extern archElf_Shdr *shdr;
extern archElf_Sym  *symtab;
extern uint         symtab_entries;
extern char         *shdrtab;
extern char         *strtab; 

virtaddr_t elf_getSymbolOffsetFromAddr(virtaddr_t sym)
{
    for (uint i = 0; i < ehdr->e_phnum; i++) {
        if ((archval_t)phdr[i].p_paddr <= (archval_t)sym &&
        (phdr[i].p_paddr + phdr[i].p_memsz) >= (archval_t)sym) {
            virtaddr_t off = SUB_TO_PTR(sym, (archval_t)phdr[i].p_paddr);
            off = ADD_TO_PTR(off, (archval_t)phdr[i].p_offset);
            return (off);
        }
    }
    return (NULL);
}