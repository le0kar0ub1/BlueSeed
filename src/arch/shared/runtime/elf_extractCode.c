#include "env/env.h"
#include "loader/elf/loader.h"
#include "shared/runtime/elftool.h"
#include "processor/processor.h"
#include "shared/runtime/extractor.h"

extern struct env *environnement;

uint8 extractCode(void)
{
    virtaddr_t vpc = (virtaddr_t)processor_get_pc();
    /* If running out of RX data then fault */
    if (vpc > environnement->virtual.end || vpc < environnement->virtual.entry)
        RAISE(ERR_SEGFAULT_NUM);
    uint8 *loc = virtToHost(vpc);
    return (*loc);
}

extractor_t extractCodeB(void)
{
    extractor_t extract = vmalloc(0x1 * sizeof(extractor_t));
    extract[0] = extractCode();
    return (extract);
}

extractor_t extractCodeW(void)
{
    extractor_t extract = vmalloc(0x2 * sizeof(extractor_t));
    extract[1] = extractCode();
    extract[0] = extractCode();
    return (extract);
}

extractor_t extractCodeD(void)
{
    extractor_t extract = vmalloc(0x4 * sizeof(extractor_t));
    extract[3] = extractCode();
    extract[2] = extractCode();
    extract[1] = extractCode();
    extract[0] = extractCode();
    return (extract);
}

extractor_t extractCodeQ(void)
{
    extractor_t extract = vmalloc(0x8 * sizeof(extractor_t));
    extract[7] = extractCode();
    extract[6] = extractCode();
    extract[5] = extractCode();
    extract[4] = extractCode();
    extract[3] = extractCode();
    extract[2] = extractCode();
    extract[1] = extractCode();
    extract[0] = extractCode();
    return (extract);
}