#include "builtin.h"
#include "opt/opt.h"

// char const *emulatorFlags[20] =
// {
//     "--verbose",
//     NULL
// };

bool IS_RUN_VERBOSE = false;

bool getFlag(char *arg)
{
    if (!strcmp("--verbose", arg)) {
        IS_RUN_VERBOSE = true;
        return (true);
    }
    return (false);
}

struct opt *mgetopt(char **av)
{
    struct opt *op = malloc(sizeof(struct opt));
    memset(op, 0, sizeof(struct opt));

    for (int inc = 1; av[inc]; inc++) {
        if (!op->exec && open(av[inc], O_RDONLY) != -1)
            op->exec = av[inc];
        else if (!getFlag(av[inc]))
            RAISE(ERR_BADARG_NUM);
    }
    return (op);
}