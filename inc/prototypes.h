#ifndef _PROTOTYPES_H_
#define _PROTOTYPES_H_

#include "opt/opt.h"

/* BUILT IN */

/* START */
void help(void);
int main(int, char **);

/* OPT */
struct opt *mgetopt(char **);

void verbose_log(char const *, ...);
void debug_log_instr(char const *, ...);

#endif