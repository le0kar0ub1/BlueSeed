# Project

*_BlueSeed is a `BASIC` cross-plateform RISC-V emulator wroten in C (and a well hidden assembly file)_*

[Project Documentation (incomplete)](doc/project.md)

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
  - [ ] RV32I Base Instruction Set
  - [ ] RV64I Base Instruction Set
  - [ ] Compressed Instruction Set (Introduced recently)
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
  - [ ] riscv64
- [ ] emulation
  - [X] elf loader (no dynamic linkage)
  - [X] virtual processor
  - [X] program exec
  - [X] syscall host interface (limited)
  - [ ] Debug
    - [X] Display the running instruction
    - [X] Dump the processor state
    - [ ] Runtime register set
    - [ ] Runtime jump/break over symbols
    - [ ] Breakpoints ?

## SPECIFITY

The only binary format accepted is [ELF](https://refspecs.linuxbase.org/elf/elf.pdf)

Software interrupts are interfaced with the host machine and based on [RV8 project](https://rv8.io/syscalls.html)

The BlueSeed ELF loader does not handle dynamic linkage etc... You can't execute GCC binary so far.

## EPILOGUE

_BlueSeed is in developpment_

RISC-V is a young architecture. There is yet a quantity of lacks & implementation problems.

[RISC-V official spec](https://content.riscv.org/wp-content/uploads/2019/06/riscv-spec.pdf)