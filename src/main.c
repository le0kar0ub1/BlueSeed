#include "builtin.h"

void architecture_target(struct opt *opt)
{
    opt->arch = NULL;
}

int main(int ac, char **av)
{
    if (ac < 1)
        RAISE(ERR_INP_MSG, ERR_INP_NUM);
    struct opt *opt = mgetopt(av);
    architecture_target(opt);
    return (0);
}
