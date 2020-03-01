# Project

*_BlueSeed is a `BASIC` cross-plateform RISC-V emulator._*

[Project Documentation (incomplete).](doc/project.md)

## DEPENDENCIES

- `gcc` (dev under 9.2.1)
- `make` (dev under 4.3)

## INSTALL

_BlueSeed have a dependencies installer for cross-compiling._

`./mktoolchain/mktoolchain $TARGET`

_If no toolchain TARGET is given then defaulting to the host machine._


## BUILD

`make TARGET=$TARGET_ARCH`


## RUN

`./BlueSeedXXX $BINARY [...options]`

*Options list:*
  - `--verbose`   : display information during environnement init

  - `--explicit`  : display the current executed instruction

  - `--debug`     : debug environnement (CLI)


## ROADMAP

- [X] toolchain
  - [X] cross-plateform build
  - [X] build system independant
- [ ] instruction set
  - [X] RV32I Base Instruction Set
  - [X] RV64I Base Instruction Set
  - [X] Compressed Instruction Set (Introduced recently)
  - [ ] RV32M Standard Extension ?
  - [ ] RV64M Standard Extension ?
  - [ ] RV32A Standard Extension ?
  - [ ] RV64A Standard Extension ?
  - [ ] RV32F Standard Extension ?
  - [ ] RV64F Standard Extension ?
  - [ ] RV32D Standard Extension ?
  - [ ] RV64D Standard Extension ?
- [ ] target arch
  - [ ] riscv32
  - [X] riscv64
- [X] emulation
  - [X] elf loader (no dynamic linkage)
  - [X] virtual processor
  - [X] program exec
  - [X] syscall host interface (limited)
  - [X] Debug
    - [X] Display the running instruction
    - [X] Dump processor/register state
    - [X] Runtime register set
    - [X] Runtime jump (using address, no symbols)

## SPECIFITY

The only binary format accepted is [ELF](https://refspecs.linuxbase.org/elf/elf.pdf)

Software interrupts are interfaced with the host machine and based on [RV8 project](https://rv8.io/syscalls.html)

The BlueSeed ELF loader does not handle dynamic linkage etc... You can't execute GCC binary so far.

## EPILOGUE

_BlueSeed is in developpment_

RISC-V is a young architecture. There is yet a quantity of lacks & implementation problems.

[RISC-V official spec](https://content.riscv.org/wp-content/uploads/2019/06/riscv-spec.pdf)