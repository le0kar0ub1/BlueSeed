#ifndef _ERROR_H__
#define _ERROR_H__

void RAISE(int errorcode);

#define ERR_INP_NUM          1
#define ERR_ARCH_NUM         2
#define ERR_BADARG_NUM       3
#define ERR_OPCODE_NUM       4
#define ERR_ELF_HEADER_NUM   5
#define ERR_EXEC_FMT_NUM     6
#define ERR_OUTOFMEM_NUM     7

#define ERR_UNKNOW_SYM_NUM   8
#define ERR_UNKNOW_SEC_NUM   9

#define ERR_SEGFAULT_NUM     10

#define ERR_SYSCALL_NUM      11

#endif