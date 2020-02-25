#ifndef _DEBUGGER_H_
#define _DEBUGGER_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "control/config.h"

#define DEBUG_PROMPT "[\e[0;34mBlueSeed\e[0m] " 

void debugger(void);
void debugger_handle_dump(char const *);
void debugger_dump_register(char const *);
void debugger_handle_next(void);
void debugger_handle_help(char const *);
void debugger_handle_exit(char const *);

#define CMD_NEXT_SHORT "n"
#define CMD_NEXT_LONG  "next"

#endif