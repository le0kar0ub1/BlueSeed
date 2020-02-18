#ifndef _ELFTOOL_H_
#define _ELFTOOL_H_

#include "env/env.h"

void elftool_init(void);
virtaddr_t elftool_getAddrFromSym(char const *);

#endif