#include "env/env.h"
#include "loader/elf/loader.h"
#include "shared/runtime/elftool.h"
#include "shared/processor/processor.h"
#include "shared/runtime/extractor.h"

extern struct env *environnement;

extern archElf_Sym  *symtab;
extern uint         symtab_entries;
extern char         *strtab; 

char *elf_getRunningSymbol(virtaddr_t virt)
{
    int diff = -1;
    char *sym = NULL;

    if (!symtab || !strtab)
        RAISE(ERR_UNKNOW_SYM_NUM);
    for (uint i = 0; i < symtab_entries; i++) {
        if (symtab[i].st_value <= (archuval_t)virt && ((symtab[i].st_info & (1 << STT_NOTYPE)) == 0))
            if (diff > (int)((archuval_t)virt - symtab[i].st_value) || diff == -1) {
                diff = ((archuval_t)virt - symtab[i].st_value);
                sym = ((char *)ADD_TO_PTR(strtab, symtab[i].st_name));
            }
    }
    return (sym);
}