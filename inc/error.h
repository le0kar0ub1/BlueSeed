#ifndef _ERROR_H__
#define _ERROR_H__

#include "builtin.h"

void RAISE(int errorcode);

#define ERR_INP_NUM 1
#define ERR_ARCH_NUM 2
#define ERR_BADARG_NUM 3
#define ERR_OPCODE_NUM 4

#endif