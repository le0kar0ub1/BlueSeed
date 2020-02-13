#ifndef _ERROR_H__
#define _ERROR_H__

#include "builtin.h"

static inline void RAISE(char const *msg, int errorcode) 
{
    dprintf(2, "%s\n", msg);
    exit (errorcode);
}

#define ERR_INP_MSG "Invalid Input"
#define ERR_INP_NUM 1

#define ERR_ARCH_MSG "Invalid target architecture"
#define ERR_ARCH_NUM 2

#define ERR_BADARG_MSG "Invalid argument"
#define ERR_BADARG_NUM 3

#endif