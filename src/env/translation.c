#include "env/env.h"

/* PROGRAM ADDRESS TRANSLATION  */
extern struct env *environnement;

hostaddr_t virtToHost(virtaddr_t virt)
{
    return ((hostaddr_t)(((uint64)environnement->host.link) + (((uint64)virt) - ((uint64)environnement->virtual.link))));
}

virtaddr_t hostToVirt(hostaddr_t host)
{
    return ((virtaddr_t)((((uint64)host) + ((uint64)environnement->virtual.link)) - ((uint64)environnement->host.link)));
}