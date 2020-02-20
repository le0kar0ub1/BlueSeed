#include <sys/mman.h>
#include "loader/elf/loader.h"

void *map_file(char const *exec)
{
    struct stat st;
    int fd = open(exec, O_RDONLY);

    if (fd == -1 || fstat(fd, &st) == -1)
        RAISE(ERR_INP_NUM);
    if (!S_ISREG(st.st_mode))
        RAISE(ERR_INP_NUM);
    void *mapped = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (!mapped)
        RAISE(ERR_OUTOFMEM_NUM);
    close(fd);
    return (mapped);
}

void munmap_file(void *mapped, char const *exec)
{
    struct stat st;
    int fd = open(exec, O_RDONLY);

    if (fd == -1 || fstat(fd, &st) == -1)
        RAISE(ERR_INP_NUM);
    munmap(mapped, st.st_size);
    close(fd);
}

bool file_header_checkup(archElf_Ehdr *ehdr)
{
    if (ehdr->e_ident[EI_MAG0] != ELFMAG0 || ehdr->e_ident[EI_MAG1] != ELFMAG1
|| ehdr->e_ident[EI_MAG2] != ELFMAG2 || ehdr->e_ident[EI_MAG3] != ELFMAG3)
        return (false);
    /* ELF32 == 1 & ELF64 == 2 */
    if (ehdr->e_ident[EI_CLASS] != SYSTEMSZ / 32)
        return (false);
    if (ehdr->e_ident[EI_DATA] == ELFDATANONE)
        return (false);
    if (ehdr->e_ident[EI_VERSION] != EV_CURRENT)
        return (false);
    if (ehdr->e_type != ET_EXEC)
        return (false);
    if (ehdr->e_machine != EM_RISCV)
        return (false);
    return (true);
}