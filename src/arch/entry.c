#include "entry.h"
#include "builtin.h"

/* jump on the target architecture handler */
void arch_entry_point(struct opt *opt)
{
    void (*arch_entries[2])(char const *) = {entry_riscv32, entry_riscv64};
    arch_entries[opt->arch](opt->exec);
}