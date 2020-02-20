#ifndef _ENV_H_
#define _ENV_H_

#include "builtin.h"

typedef void * hostaddr_t ;
typedef void * virtaddr_t;

struct host_env
{
    hostaddr_t link;
    hostaddr_t end;
};

struct virtual_env
{
    virtaddr_t link;
    virtaddr_t entry;
    virtaddr_t end;
};

struct env
{
    struct host_env    host;
    struct virtual_env virtual;
} __packed;

hostaddr_t virtToHost(virtaddr_t);
virtaddr_t hostToVirt(hostaddr_t);

void free_environement(struct env *env);
void exit_environnement(void);
void init_environnement(void);

#endif