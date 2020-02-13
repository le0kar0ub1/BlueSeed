#ifndef _PROTOTYPES_H_
#define _PROTOTYPES_H_

#include "opt.h"

/* BUILT IN */

/* START */
void help(void);
int main(int, char **);
void arch_entry_point(struct opt *);

/* OPT */
struct opt *mgetopt(char **);
int opt_target_arch(char *);


#endif