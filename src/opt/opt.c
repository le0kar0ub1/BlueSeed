#include "builtin.h"
#include "opt/opt.h"

struct opt *mgetopt(char **av)
{
    struct opt *op = malloc(sizeof(struct opt));
    memset(op, 0, sizeof(struct opt));

    for (int inc = 1; av[inc]; inc++) {
        if (!op->exec && open(av[inc], O_RDONLY) != -1)
            op->exec = av[inc];
        else
            RAISE(ERR_BADARG_NUM);
    }
    return (op);
}