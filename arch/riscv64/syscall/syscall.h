#ifndef _SYSCALL_TABLE_H_
#define _SYSCALL_TABLE_H_

/*
** There is no established norm on riscv software interrupt.
** By the way we will implemente some accepted syscall.
*/

/* RISCV SYSCALL TABLE (?) | MAPPING | X86_64 */
int syscall[100][2] =
{
 /* RISCV */     /* X86_64 */
    {17,            79},     /* getcwd */
    {25,            72},     /* fcntl */
    {29,            16},     /* ioctl */
    {57,            3},      /* close */
    {63,            0},      /* read */
    {64,            1},      /* write */
    {65,            19},     /* readv */
    {66,            20},     /* writev */
    {80,            5},      /* fstat */
    {93,            60},     /* exit */
    {96,            218},    /* set_tid_address */
    {113,           228},   /* clock_gettime */
    {134,           13},    /* rt_sigaction */
    {135,           14},    /* rt_sigprocmask */
    {153,           100},   /* times */
    {160,           63},    /* uname */
    {165,           98},    /* getrusage */
    {169,           96},    /* gettimeofday */
    {179,           99},    /* sysinfo */
    {214,           12},    /* brk */
    {215,           11},    /* munmap */
    {222,           9},     /* mmap */
    {226,           10},    /* mprotect */
    {233,           28},    /* madvise */
    {261,           302},   /* prlimit64 */
    {1024,          2},    /* open */
    {1038,          4}     /* stat */
};

#endif