#ifndef _OPT_H_
#define _OPT_H_

/* target architecture */
#define TARGET_ARCH_PREFIX   "--target="
#define TARGET_ARCH_x86      "x86"
#define TARGET_ARCH_x64      "x64"
#define TARGET_ARCH_RISCV32  "riscv32"
#define TARGET_ARCH_RISCV64  "riscv64"
#define TARGET_ARCH_RISCV128 "riscv128"
#define TARGET_ARCH_DEFAULT  TARGET_ARCH_RISCV64

struct opt {
    char *arch;
    char *exec;
};

#endif