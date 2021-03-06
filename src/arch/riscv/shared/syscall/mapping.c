#include "syscall/syscall.h"

struct syscallmap sysmap =
{
    .host  = {
        79, 72, 16, 3, 0, 1, 19, 20, 5, 60, 218, 228, 13, 14, 100, 63, 98, 96, 99, 12, 11, 9, 10, 28, 302, 2, 4, -1
    },

    .riscv   = {
        17, 25, 29, 57, 63, 64, 65, 66, 80, 93, 96, 113, 134, 135, 153, 160, 165, 169, 179, 214, 215, 222, 226, 233, 261, 1024, 1038, -1
    },

    .handler = {
        syscall_getcwd,
        syscall_fcntl,
        syscall_ioctl,
        syscall_close,
        syscall_read,
        syscall_write,
        syscall_readv,
        syscall_writev,
        syscall_fstat,
        syscall_exit,
        syscall_set_tid_address,
        syscall_clock_gettime,
        syscall_rt_sigaction,
        syscall_rt_sigprocmask,
        syscall_times,
        syscall_uname,
        syscall_getrusage,
        syscall_gettimeofday,
        syscall_sysinfo,
        syscall_brk,
        syscall_munmap,
        syscall_mmap,
        syscall_mprotect,
        syscall_madvise,
        syscall_prlimit64,
        syscall_open,
        syscall_stat
    }
};