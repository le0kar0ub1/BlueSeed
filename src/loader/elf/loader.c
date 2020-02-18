#include "builtin.h"
#include "loader/elf/loader.h"

struct env *elf_loader(char const *file)
{
    struct env *loader = load_file(file);

    if (!loader)
        RAISE(ERR_INP_NUM);
    verbose_log("ELF header checkup...\n");
    if (!file_header_checkup(loader->host.link))
        RAISE(ERR_ELF_HEADER_NUM);
    verbose_log("Generating environnement...\n");
    virtual_loading(loader);
    return (loader);
}