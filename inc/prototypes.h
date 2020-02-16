#ifndef _PROTOTYPES_H_
#define _PROTOTYPES_H_

#include "opt/opt.h"

/* BUILT IN */

/* START */
void help(void);
int main(int, char **);

/* OPT */
struct opt *mgetopt(char **);

#endif