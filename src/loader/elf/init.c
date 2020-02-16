#include "loader/elf/loader.h"
#include "sys/mman.h"

void *load_file(char const *exec)
{
    struct stat st;
    int fd = open(exec, O_RDONLY);

    if (fd == -1 || fstat(fd, &st) == -1)
        RAISE(ERR_INP_NUM);
    if (!S_ISREG(st.st_mode))
        RAISE(ERR_INP_NUM);
    void *mapped = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    close(fd);
    return (mapped);
}

bool file_header_checkup(void *mapped)
{
    return (true);
}