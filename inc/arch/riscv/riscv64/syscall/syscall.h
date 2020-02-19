#ifndef _SYSCALL_TABLE_H_
#define _SYSCALL_TABLE_H_

#include "def/typedef.h"
#include "def/keyword.h"

/*
** There is no established norm on riscv software interrupt.
** By the way we will implement some accepted syscall.
*/

struct syscallHandler
{
    int  x86_64[100];
    int  riscv[100];
    int8 args[100];
} __packed;

void exec_syscall(void);
void exec_syscall_arg0(uint64);
void exec_syscall_arg1(uint64, uint64);
void exec_syscall_arg2(uint64, uint64, uint64);
void exec_syscall_arg3(uint64, uint64, uint64, uint64);
void exec_syscall_arg4(uint64, uint64, uint64, uint64, uint64);
void exec_syscall_arg5(uint64, uint64, uint64, uint64, uint64, uint64);
void exec_syscall_arg6(uint64, uint64, uint64, uint64, uint64, uint64, uint64);

/* RISCV SYSCALL TABLE (?) | MAPPING | X86_64 */
// int systemcall[100][3] =
// {
//  /* RISCV */     /* X86_64 */    /* ARGS NBR */
//     {17,               79,              2},    /* getcwd */
//     {25,               72,              3},    /* fcntl */
//     {29,               16,              3},    /* ioctl */
//     {57,               3,               1},     /* close */
//     {63,               0,               3},     /* read */
//     {64,               1,               3},     /* write */
//     {65,               19,              3},    /* readv */
//     {66,               20,              3},    /* writev */
//     {80,               5,               2},     /* fstat */
//     {93,               60,              1},    /* exit */
//     {96,               218,             1},   /* set_tid_address */
//     {113,              228,             2},   /* clock_gettime */
//     {134,              13,              4},    /* rt_sigaction */
//     {135,              14,              4},    /* rt_sigprocmask */
//     {153,              100,             1},   /* times */
//     {160,              63,              1},    /* uname */
//     {165,              98,              2},    /* getrusage */
//     {169,              96,              2},    /* gettimeofday */
//     {179,              99,              1},    /* sysinfo */
//     {214,              12,              1},    /* brk */
//     {215,              11,              2},    /* munmap */
//     {222,              9,               6},     /* mmap */
//     {226,              10,              3},    /* mprotect */
//     {233,              28,              3},    /* madvise */
//     {261,              302,             4},   /* prlimit64 */
//     {1024,             2,               3},     /* open */
//     {1038,             4,               2}      /* stat */
// };

#endif