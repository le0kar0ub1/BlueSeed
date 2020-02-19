#include "builtin.h"
#include "syscall/syscall.h"
#include "processor/processor.h"

static struct syscallHandler syscallMapped =
{
    .x86_64 = {79, 72, 16, 3, 0, 1, 19, 20, 5, 60, 218, 228, 13, 14, 100, 63, 98, 96, 99, 12, 11, 9, 10, 28, 302, 2, 4, -1},

    .riscv  = {17, 25, 29, 57, 63, 64, 65, 66, 80, 93, 96, 113, 134, 135, 153, 160, 165, 169, 179, 214, 215, 222, 226, 233, 261, 1024, 1038, -1},

    .args   = {2, 3, 3, 1, 3, 3, 3, 3, 2, 1, 1, 2, 4, 4, 1, 1, 2, 2, 1, 1, 2, 6, 3, 3, 4, 3, 2, -1},
};

/* HANDLER BY NUMBER OF ARGUMENT */
void exec_syscall(void)
{
    uint syscall = (uint)processor_get_a7();
    for (uint i = 0; syscallMapped.riscv[i] != -1; i++)
        if (syscallMapped.riscv[i] == (int)syscall) {
            switch (syscallMapped.args[i]) {
                case 0:
                    exec_syscall_arg0(syscallMapped.x86_64[i]);
                    break;
                case 1:
                    exec_syscall_arg1(processor_get_a0(), syscallMapped.x86_64[i]);
                    break;
                case 2:
                    exec_syscall_arg2(processor_get_a0(), processor_get_a1(), syscallMapped.x86_64[i]);
                    break;
                case 3:
                    exec_syscall_arg3(processor_get_a0(), processor_get_a1(), 
                        processor_get_a2(), syscallMapped.x86_64[i]);
                    break;
                case 4:
                    exec_syscall_arg4(processor_get_a0(), processor_get_a1(), 
                        processor_get_a2(), processor_get_a3(), syscallMapped.x86_64[i]);
                    break;
                case 5:
                    exec_syscall_arg5(processor_get_a0(), processor_get_a1(), 
                        processor_get_a2(), processor_get_a3(), processor_get_a4(), syscallMapped.x86_64[i]);
                    break;
                case 6:
                    exec_syscall_arg6(processor_get_a0(), processor_get_a1(), 
                        processor_get_a2(), processor_get_a3(), processor_get_a4(), 
                        processor_get_a6(), syscallMapped.x86_64[i]);
                    break;
                default:
                    RAISE(ERR_SYSCALL_NUM);
            }
            return;
        }
    RAISE(ERR_SYSCALL_NUM);
}