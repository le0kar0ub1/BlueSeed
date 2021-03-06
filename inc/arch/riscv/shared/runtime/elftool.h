#ifndef _ELFTOOL_H_
#define _ELFTOOL_H_

#include "env/env.h"
#include "loader/elf/loader.h"

void elftool_init(void);
virtaddr_t elftool_getAddrFromSym(char const *);
virtaddr_t elftool_getSecAddrFromName(char const *);
archElf_Shdr *elftool_getSectionFromName(char const *);
void *elftool_getSectionContentFromName(char const *);
uint elftool_getSectionSizeFromName(char const *);
char const *elftool_getSymFromAddr(virtaddr_t);

virtaddr_t elf_getSymbolOffsetFromAddr(virtaddr_t sym);

char *elf_getRunningSymbol(virtaddr_t virt);

#endif