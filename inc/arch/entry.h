#ifndef _ENTRY_H_
#define _ENTRY_H_

#include "opt.h"

void entry_point(struct opt *);

void entry_x86(char const *);
void entry_x64(char const *);
void entry_riscv32(char const *);
void entry_riscv64(char const *);
void entry_riscv128(char const *);

void (*arch_entries[5])(char const *) = {entry_x86, entry_x64, entry_riscv32, entry_riscv64, entry_riscv128};

#endif