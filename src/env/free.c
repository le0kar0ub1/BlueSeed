#include "env/env.h"

void free_environement(struct env *env)
{
    free(env->host.link);
    free(env);
}