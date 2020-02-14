#ifndef _OPT_H_
#define _OPT_H_

#include "keyword.h"
#include <sys/stat.h>
#include <fcntl.h>


/* target architecture */
#define TARGET_ARCH_PREFIX   "--target="
#define TARGET_ARCH_RISCV32  "riscv32"
#define TARGET_ARCH_RISCV64  "riscv64"
#define TARGET_ARCH_RISCV128 "riscv128"
#define TARGET_ARCH_DEFAULT  TARGET_ARCH_RISCV64

#define TARGET_ARCH_RISCV32_IDX  1
#define TARGET_ARCH_RISCV64_IDX  2
#define TARGET_ARCH_RISCV128_IDX 3
#define TARGET_ARCH_DEFAULT_IDX  TARGET_ARCH_RISCV64_IDX

struct opt
{
    char *exec;
    int  arch;
} __packed;

#endif