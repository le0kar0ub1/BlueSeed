.global exec_syscall_arg0
.global exec_syscall_arg1
.global exec_syscall_arg2
.global exec_syscall_arg3
.global exec_syscall_arg4
.global exec_syscall_arg5
.global exec_syscall_arg6

.text
exec_syscall_arg0:
    mov %rdi, %rax
    syscall
    ret

exec_syscall_arg1:
    mov %rsi, %rax
    syscall
    ret

exec_syscall_arg2:
    mov %rdx, %rax
    syscall
    ret

exec_syscall_arg3:
    mov %rcx, %rax
    syscall
    ret

exec_syscall_arg4:
    mov %r8, %rax
    mov %rcx, %r10
    syscall
    ret

exec_syscall_arg5:
    mov %r9, %rax
    mov %rcx, %r10
    syscall
    ret

exec_syscall_arg6:
    pop %rax
    mov %rcx, %r10
    syscall
    ret