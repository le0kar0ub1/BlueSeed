#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include "def/typedef.h"
#include "def/keyword.h"

struct opcode_Rtype
{
    uint opcode : 7;
    uint rd     : 5;
    uint funct3 : 3;
    uint rs1    : 5;
    uint rs2    : 5;
    uint funct7 : 7;
} __packed;

struct opcode_Itype
{
    uint opcode : 7;
    uint rd     : 5;
    uint funct3 : 3;
    uint rs1    : 5;
    uint imm    : 12; // 0 : 11
} __packed;

struct opcode_Stype
{
    uint opcode : 7;
    uint imm1   : 5; // 0 : 4
    uint funct3 : 3;
    uint rs1    : 5;
    uint rs2    : 5;
    uint imm2   : 7; // 11 : 5
} __packed;

struct opcode_Btype
{
    uint opcode : 7;
    uint imm1   : 5; // 4 : 1 | 11
    uint funct3 : 3;
    uint rs1    : 5;
    uint rs2    : 5;
    uint imm2   : 7; // 12 | 10 : 5
} __packed;

struct opcode_Utype
{
    uint opcode : 7;
    uint rd     : 5;
    uint imm    : 19; // 31 : 12
} __packed;

struct opcode_Jtype
{
    uint opcode : 7;
    uint rd     : 5;
    uint imm    : 19; // 20 | 10 : 1 | 11 | 19 : 12
} __packed;



/* 64 EXTENSION */
struct opcode_R4type
{
    uint opcode : 7;
    uint rd     : 5;
    uint funct3 : 3;
    uint rs1    : 5;
    uint rs2    : 5;
    uint funct2 : 3;
    uint rs3    : 4;
} __packed;

#endif