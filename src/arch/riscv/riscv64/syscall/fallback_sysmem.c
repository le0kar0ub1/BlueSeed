#include "builtin.h"
#include "syscall/syscall.h"
#include "processor/processor.h"
#include "env/env.h"

void syscall_getcwd(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), processor_get_a2(), syscall));
}

void syscall_fcntl(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), processor_get_a1(), processor_get_a2(),syscall));
}

void syscall_ioctl(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), processor_get_a1(), processor_get_a2(), syscall));
}

void syscall_close(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg1(processor_get_a0(), syscall));
}

void syscall_read(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), processor_get_a2(), syscall));
}

void syscall_write(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), processor_get_a2(), syscall));
}

void syscall_readv(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), processor_get_a2(), syscall));
}

void syscall_writev(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), processor_get_a2(), syscall));
}

void syscall_fstat(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg2((uint64)virtToHost((virtaddr_t)processor_get_a0()), (uint64)virtToHost((virtaddr_t)processor_get_a1()), syscall));
}

void syscall_exit(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg1(processor_get_a0(), syscall));
}

void syscall_set_tid_address(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg1((uint64)virtToHost((virtaddr_t)processor_get_a0()), syscall));
}

void syscall_clock_gettime(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg2(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), syscall));
}

void syscall_rt_sigaction(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg4(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), (uint64)virtToHost((virtaddr_t)processor_get_a2()), processor_get_a3(), syscall));
}

void syscall_rt_sigprocmask(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg4(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), (uint64)virtToHost((virtaddr_t)processor_get_a2()), processor_get_a3(), syscall));
}

void syscall_times(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg1((uint64)virtToHost((virtaddr_t)processor_get_a0()), syscall));
}

void syscall_uname(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg1((uint64)virtToHost((virtaddr_t)processor_get_a0()), syscall));
}

void syscall_getrusage(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg2(processor_get_a0(), (uint64)virtToHost((virtaddr_t)processor_get_a1()), syscall));
}

void syscall_gettimeofday(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg2((uint64)virtToHost((virtaddr_t)processor_get_a0()), (uint64)virtToHost((virtaddr_t)processor_get_a1()), syscall));
}

void syscall_sysinfo(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg1((uint64)virtToHost((virtaddr_t)processor_get_a0()), syscall));
}

void syscall_brk(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg1(processor_get_a0(), syscall));
}

void syscall_munmap(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg2(processor_get_a0(),processor_get_a1(), syscall));
}

void syscall_mmap(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg6(processor_get_a0(), processor_get_a1(), processor_get_a2(), processor_get_a3(), processor_get_a4(), processor_get_a6(), syscall));
}

void syscall_mprotect(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), processor_get_a1(), processor_get_a2(), syscall));
}

void syscall_madvise(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3(processor_get_a0(), processor_get_a1(), processor_get_a2(), syscall));
}

void syscall_prlimit64(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg4(processor_get_a0(), processor_get_a1(), (uint64)virtToHost((virtaddr_t)processor_get_a2()), (uint64)virtToHost((virtaddr_t)processor_get_a3()), syscall));
}

void syscall_open(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg3((uint64)virtToHost((virtaddr_t)processor_get_a0()), processor_get_a1(), processor_get_a2(), syscall));
}

void syscall_stat(uint syscall)
{
    processor_set_a7((uint64)exec_syscall_arg2((uint64)virtToHost((virtaddr_t)processor_get_a0()), (uint64)virtToHost((virtaddr_t)processor_get_a1()), syscall));
}