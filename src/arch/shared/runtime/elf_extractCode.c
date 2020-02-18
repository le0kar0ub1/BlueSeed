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
    uint8 *loc = (uint8 *)virtToHost(vpc);
    processor_set_pc((reg_t)ADD_TO_PTR(vpc, 0x1));
    return (*loc);
}

extractor8_t extractCodeB(void)
{
    extractor8_t extract = (extractor8_t)extractCode();
    return (extract);
}

extractor16_t extractCodeW(void)
{
    extractor16_t extract;
    extract =  (extractor16_t)extractCode() << 8;
    extract += (extractor16_t)extractCode() << 0;
    return (extract);
}

extractor32_t extractCodeD(void)
{
    extractor32_t extract;
    extract =  (extractor32_t)extractCode() << 24;
    extract += (extractor32_t)extractCode() << 16;
    extract += (extractor32_t)extractCode() << 8;
    extract += (extractor32_t)extractCode() << 0;
    return (extract);
}

extractor64_t extractCodeQ(void)
{
    extractor64_t extract;
    extract  = (extractor64_t)extractCode() << 56;
    extract += (extractor64_t)extractCode() << 48;
    extract += (extractor64_t)extractCode() << 40;
    extract += (extractor64_t)extractCode() << 32;
    extract += (extractor64_t)extractCode() << 24;
    extract += (extractor64_t)extractCode() << 16;
    extract += (extractor64_t)extractCode() << 8;
    extract += (extractor64_t)extractCode() << 0;
    return (extract);
}