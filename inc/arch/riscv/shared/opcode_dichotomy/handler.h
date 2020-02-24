#ifndef _OPCODE_HANDLER_H_
#define _OPCODE_HANDLER_H_

#include "shared/runtime/extractor.h"

bool opcode_handler_Btype(extractor32_t *);
bool opcode_handler_Itype(extractor32_t *);
bool opcode_handler_Stype(extractor32_t *);
bool opcode_handler_Rtype(extractor32_t *);
bool opcode_handler_Utype(extractor32_t *);
bool opcode_handler_Jtype(extractor32_t *);
bool opcode_handler_R4type(extractor32_t *);
bool opcode_handler_compressed(extractor32_t *);
bool opcode_handler_pseudo(extractor32_t *);

#endif