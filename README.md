# BlueSeed, the RISC-V emulator

*_BlueSeed is a cross-plateform (in-build) RISC-V emulator_*

## DEPENDENCIES

- `gcc`  for x86_64-elf target (dev under 9.2.1)
- `nasm`                       (dev under 2.14.02)
- `make`                       (dev under 4.3)

## INSTALL

_BlueSeed have a toolchain builder_

`make toolchain TARGET=$HOST_ARCH` | `./mktoolchain/mktoolchain $HOST_ARCH`

## BUILD

`make TARGET=$TARGET_ARCH`


## RUN

`make run EXEC=$BINARY` | `./BlueSeed $BINARY`


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
- [ ] target arch
  - [ ] riscv32
  - [ ] riscv64
- [ ] emulation
  - [ ] elf loader
  - [ ] virtual processor
  - [ ] program exec
  - [ ] syscall host interface
  - [ ] threading (unlikely)

_Will be implemented ?_
- [ ] runtime command
  - [ ] break
  - [ ] dump
- [ ] memory scheluder
- [ ] component interaction/emulation
- [ ] self interface
  - [ ] syscall
  - [ ] ...

## EPILOGUE

_BlueSeed is in developpment_
