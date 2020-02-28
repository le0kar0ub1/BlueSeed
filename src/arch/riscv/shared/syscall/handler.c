#include "builtin.h"
#include "syscall/syscall.h"
#include "shared/processor/processor.h"
#include "env/env.h"

extern struct env *environnement;

extern struct syscallmap sysmap;

void exec_syscall(void)
{
    uint syscall = (uint)processor_get_a7();
    for (uint i = 0; sysmap.riscv[i] != -1; i++)
        if (sysmap.riscv[i] == (int)syscall) {
            sysmap.handler[i](sysmap.host[i]);
            return;
        }
    RAISE(ERR_SYSCALL_NUM);
}