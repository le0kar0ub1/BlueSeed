#ifndef _ENV_H_
#define _ENV_H_

#include "builtin.h"

typedef void * hostaddr_t ;
typedef void * virtaddr_t;

struct host_env
{
    uint loadsize;
    hostaddr_t link;
};

struct virtual_env
{
    virtaddr_t link;
    virtaddr_t entry;
};

struct env
{
    struct host_env    host;
    struct virtual_env virtual;
} __packed;

hostaddr_t virtToHost(virtaddr_t, struct env *);
virtaddr_t hostToVirt(hostaddr_t, struct env *);

#endif