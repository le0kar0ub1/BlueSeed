#ifndef _ELF_LOADER_H_
#define _ELF_LOADER_H_

#include "elf.h"
#include "builtin.h"
#include "env/env.h"

/* Compile-time macro */
#if SYSTEMSZ == 64
    typedef Elf64_Ehdr        archElf_Ehdr;
    typedef Elf64_Phdr        archElf_Phdr;
    typedef Elf64_Shdr        archElf_Shdr;
    typedef Elf64_Sym         archElf_Sym;
    typedef Elf64_Chdr        archElf_Chdr;
    typedef Elf64_Addr        archElf_Addr;
    typedef Elf64_Off         archElf_Off;
    typedef Elf64_Section     archElf_Section;
    typedef Elf64_Versym      archElf_Versym;
    typedef Elf64_Half        archElf_Half;
    typedef Elf64_Sword       archElf_Sword;
    typedef Elf64_Word        archElf_Word;
    typedef Elf64_Sxword      archElf_Sxword;
    typedef Elf64_Xword       archElf_Xword;
    typedef Elf64_Rel         archElf_Rel;
    typedef Elf64_Rela        archElf_Rela;
    typedef Elf64_Dyn         archElf_Dyn;
#else
    typedef Elf32_Ehdr        archElf_Ehdr;
    typedef Elf32_Phdr        archElf_Phdr;
    typedef Elf32_Shdr        archElf_Shdr;
    typedef Elf32_Sym         archElf_Sym;
    typedef Elf32_Chdr        archElf_Chdr;
    typedef Elf32_Addr        archElf_Addr;
    typedef Elf32_Off         archElf_Off;
    typedef Elf32_Section     archElf_Section;
    typedef Elf32_Versym      archElf_Versym;
    typedef Elf32_Half        archElf_Half;
    typedef Elf32_Sword       archElf_Sword;
    typedef Elf32_Word        archElf_Word;
    typedef Elf32_Sxword      archElf_Sxword;
    typedef Elf32_Xword       archElf_Xword;
    typedef Elf32_Rel         archElf_Rel;
    typedef Elf32_Rela        archElf_Rela;
    typedef Elf32_Dyn         archElf_Dyn;
#endif

void elf_loader(char const *);
struct env *load_file(char const *);
bool file_header_checkup(archElf_Ehdr *);
void virtual_loading(struct env *);

#endif