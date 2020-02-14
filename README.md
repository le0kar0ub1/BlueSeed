# BlueSeed, the RISC-V emulator

*_BlueSeed is a cross-plateform (in-build) RISC-V emulator_*

## DEPENDENCIES

- *gcc*  for x86_64-elf target (dev under 9.2.1)
- *nasm*                       (dev under 2.14.02)
- *make*                       (dev under 4.3)

## INSTALL

_BlueSeed has been built with a toolchain builder_

*make toolchain*

## BUILD

*make*


## RUN

*make run*


## ROADMAP

- [X] toolchain
  - [X] cross-plateform build
  - [X] build system independant
- [ ] instruction set
  - [ ] RV32I Base Instruction Set
  - [ ] RV64I Base Instruction Set
  - [ ] RV32M Standard Extension
  - [ ] RV64M Standard Extension
  - [ ] RV32A Standard Extension
  - [ ] RV64A Standard Extension
  - [ ] RV32F Standard Extension
  - [ ] RV64F Standard Extension
  - [ ] RV32D Standard Extension
  - [ ] RV64D Standard Extension
- [ ] emulation
  - [ ] elf loader
  - [ ] virtual processor
  - [ ] program exec
  - [ ] syscall host interface
  - [ ] threading (unlikely)
- [ ] target arch
  - [ ] riscv32
  - [ ] riscv64
  - [ ] riscv128 
- [ ] runtime command
  - [ ] break
  - [ ] dump
- [ ] memory scheluder

_Will be implemented ?_
- [ ] component interaction/emulation
- [ ] self interface
  - [ ] syscall
  - [ ] ...

## EPILOGUE

_BlueSeed is in developpment_
