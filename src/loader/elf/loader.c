#include "builtin.h"
#include "loader/elf/loader.h"

void load_section(void *dest, void *src, archElf_Shdr *shdr)
{
    if (shdr->sh_addr)
        memcpy(ADD_TO_PTR(dest, shdr->sh_addr), ADD_TO_PTR(src, shdr->sh_offset), shdr->sh_size);
    else
        memcpy(ADD_TO_PTR(dest, shdr->sh_offset), ADD_TO_PTR(src, shdr->sh_offset), shdr->sh_size);
}

static inline uint get_loadsize(archElf_Shdr *shdr, uint entries)
{
    uint max = 0;

    for (uint i = 0; i < entries; i++)
        if (max < (shdr[i].sh_addr + shdr[i].sh_size))
            max = shdr[i].sh_addr + shdr[i].sh_size;
    return (ALIGN(max, 0x1000));
}

static inline uint get_execsize(archElf_Shdr *shdr, char *shdrtab, uint entries)
{
    for (uint i = 0; i < entries; i++)
        if (!strcmp(".text", (char *)&(shdrtab[shdr[i].sh_name])))
            return (shdr[i].sh_size);
    RAISE(ERR_EXEC_FMT_NUM);
    return (0);
}

struct env *virtual_loading(void *mapped)
{
    struct env *loader = vmalloc(sizeof(struct env));
    archElf_Ehdr *ehdr = (archElf_Ehdr *)mapped;
    archElf_Shdr *shdr = ADD_TO_PTR(ehdr, ehdr->e_shoff);
    uint alloc = get_loadsize(shdr, ehdr->e_shnum);

    loader->host.link = vmalloc(alloc);
    loader->host.end  = (hostaddr_t)ADD_TO_PTR(loader->host.link, alloc);
    loader->virtual.entry = (virtaddr_t)ehdr->e_entry;
    loader->virtual.end   = (virtaddr_t)(uint64)ADD_TO_PTR(loader->virtual.entry, get_execsize(shdr, (char *)(ADD_TO_PTR(ehdr, shdr[ehdr->e_shstrndx].sh_offset)), ehdr->e_shnum));
    memset(loader->host.link, 0x0, alloc);
    /* memcpy the head of the file */
    memcpy(loader->host.link, mapped, ehdr->e_ehsize);
    memcpy(ADD_TO_PTR(loader->host.link, ehdr->e_phoff), ADD_TO_PTR(mapped, ehdr->e_phoff), (ehdr->e_phentsize * ehdr->e_phnum));
    memcpy(ADD_TO_PTR(loader->host.link, ehdr->e_shoff), ADD_TO_PTR(mapped, ehdr->e_shoff), (ehdr->e_shentsize * ehdr->e_shnum));
    
    for (uint i = 0; i < ehdr->e_shnum; i++)
        load_section(loader->host.link, mapped, &(shdr[i]));
    return (loader);
}

struct env *elf_loader(char const *file)
{
    void *mapped = map_file(file);

    verbose_log("ELF header checkup...\n");
    if (!file_header_checkup(mapped))
        RAISE(ERR_ELF_HEADER_NUM);
    verbose_log("Generating environnement...\n");
    /* Load the file */
    struct env *loader = virtual_loading(mapped);
    /* unmap unused memory */
    munmap_file(mapped, file);
    return (loader);
}