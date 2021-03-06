#ifndef _OPT_H_
#define _OPT_H_

#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "def/keyword.h"

struct opt
{
    char *exec;
} __packed;

bool getFlag(char *);
struct opt *mgetopt(char **);

#endif