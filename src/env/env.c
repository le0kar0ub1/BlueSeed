#include "env/env.h"

/* PROGRAM ADDRESS TRANSLATION  */

hostaddr_t virtToHost(virtaddr_t virt, struct env *env)
{
    return ((hostaddr_t)(((uint64)env->host.link) + (((uint64)virt) - ((uint64)env->virtual.link))));
}

virtaddr_t hostToVirt(hostaddr_t host, struct env *env)
{
    return ((virtaddr_t)((((uint64)host) - ((uint64)env->virtual.link)) - ((uint64)env->host.link)));
}