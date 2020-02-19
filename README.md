# BlueSeed Project

*_BlueSeed is a `BASIC` multi-plateform RISC-V emulator wroten in C_*

## DEPENDENCIES

- `gcc` (dev under 9.2.1)
- `make` (dev under 4.3)

## INSTALL

_BlueSeed have a toolchain builder_

`make toolchain TARGET=$HOST_ARCH` | `./mktoolchain/mktoolchain $HOST_ARCH`

## BUILD

`make TARGET=$TARGET_ARCH`


## RUN

`make run EXEC=$BINARY` | `./BlueSeed $BINARY`


## ROADMAP

- [ ] toolchain
  - [ ] cross-plateform build
  - [ ] build system independant
- [ ] instruction set
  - [ ] RV32I Base Instruction Set
  - [ ] RV64I Base Instruction Set
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
  - [X] elf loader
  - [X] virtual processor
  - [X] program exec
  - [X] syscall host interface (limited)

## SPECIFITY

_The only binary format accepted is [ELF](https://refspecs.linuxbase.org/LSB_3.0.0/LSB-PDA/LSB-PDA/generic-elf.html)_

_Software interrupts are based on [RV8 project](https://rv8.io/syscalls.html)_


## EPILOGUE

_BlueSeed is in developpment_

[RISCV official spec](https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf)