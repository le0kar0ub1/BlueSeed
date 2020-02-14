#ifndef _BUILTIN_H_
#define _BUILTIN_H_

/* PREPROCESSOR */
// #pragma GCC
/* warning | error | diagnostic | ... + "message" */
// #pragma message ""
// #pragma once
// #pragma startup set() // call before main
// #pragma exit unset()  // call after main

/* STANDARD HEADERS */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/* PERSONNAL HEADERS */
#include "macro.h"
#include "typedef.h"
#include "keyword.h"
#include "bitfield.h"
#include "fatalAssert.h"
#include "config.h"
#include "error.h"
#include "prototypes.h"

#endif
