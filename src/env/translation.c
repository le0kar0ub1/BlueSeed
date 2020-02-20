#include "env/env.h"
#include "shared/runtime/elftool.h"

/* PROGRAM ADDRESS TRANSLATION  */
extern struct env *environnement;

hostaddr_t virtToHost(virtaddr_t virt)
{
    if ((uint64)virt > ((uint64)environnement->host.end - (uint64)environnement->host.link))
        return ((hostaddr_t)virt);
    return ((hostaddr_t)(((uint64)environnement->host.link) + ((uint64)virt)));
}

virtaddr_t hostToVirt(hostaddr_t host)
{
    return ((virtaddr_t)(((uint64)host) - ((uint64)environnement->host.link)));
}