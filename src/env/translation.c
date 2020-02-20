#include "env/env.h"
#include "shared/runtime/elftool.h"

/* PROGRAM ADDRESS TRANSLATION  */
extern struct env *environnement;

// bool isAddressInfile(virtaddr_t virt)
// {
//     if ((uint64)environnement->virtual.link > (uint64)virt ||
// (uint64)ADD_TO_PTR(environnement->virtual.link, environnement->virtual.size) < (uint64)virt)
//         return (false);
//     return (true);
// }

hostaddr_t virtToHost(virtaddr_t virt)
{
    hostaddr_t host = elf_getSymbolOffsetFromAddr(virt);
    if (!host)
        return ((hostaddr_t)virt);
    return ((hostaddr_t)(((uint64)environnement->host.link) + ((uint64)host)));
}

virtaddr_t hostToVirt(hostaddr_t host)
{
    return ((virtaddr_t)((((uint64)host) + ((uint64)environnement->virtual.link)) - ((uint64)environnement->host.link)));
}