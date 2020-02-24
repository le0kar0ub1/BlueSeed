#ifndef _COMPRESSED_INSTRUCTION_H_
#define _COMPRESSED_INSTRUCTION_H_

#include "def/typedef.h"
#include "def/keyword.h"

struct opcode_CRtype
{
    uint opcode : 2;
    uint rs2    : 5;
    uint rx     : 5;
    uint funct4 : 4;
} __packed;

struct opcode_CItype
{
    uint opcode : 2;
    uint imm    : 5;
    uint rx     : 5;
    uint imm2   : 1;
    uint funct3 : 3;
} __packed;

struct opcode_CSStype
{
    uint opcode : 2;
    uint rs2    : 5;
    uint imm    : 6;
    uint funct3 : 3;
} __packed;

struct opcode_CIWtype
{
    uint opcode : 2;
    uint rd     : 3;
    uint imm    : 10;
    uint funct3 : 3;
} __packed;

struct opcode_CLtype
{
    uint opcode : 2;
    uint rd     : 3;
    uint imm1   : 2;
    uint rs1    : 3;
    uint imm2   : 3;
    uint funct3 : 3;
} __packed;

struct opcode_CStype
{
    uint opcode : 2;
    uint rs2    : 3;
    uint imm1   : 2;
    uint rs1    : 3;
    uint imm2   : 3;
    uint funct3 : 3;
} __packed;

struct opcode_CAtype
{
    uint opcode : 2;
    uint rs2    : 3;
    uint imm1   : 2;
    uint rs1    : 3;
    uint funct6 : 6;
} __packed;

struct opcode_CBtype
{
    uint opcode : 2;
    uint offset : 5;
    uint rs1    : 3;
    uint imm2   : 3;
    uint funct3 : 3;
} __packed;

struct opcode_CJtype
{
    uint opcode : 2;
    uint target : 11;
    uint funct3 : 3;
} __packed;

#endif