# BlueSeed Documentation

BlueSeed is a little project without ambition that explore a new world.

## RISC-V A BLURRY WORLD

[RISC-V](https://riscv.org) is an open source hardware [ISA](https://en.wikipedia.org/wiki/Instruction_set_architecture) (Instruction Set Architecture) type [RISC](https://en.wikipedia.org/wiki/Reduced_instruction_set_computer) (Reduce Instruction Set Computer).
This ISA is not much used to date but has potential to exploit.

The problem is that, there is a lot of lacks in tools used for RISC-V developpement.

Advanced in this world is so complicated and there are few information and precedent on the subject.
By the way, we will try for the best.

## BLUESEED

BlueSeed is a basic emulator for RISC-V 32/64 (128 maybe later).

The project can be built for a lot of plateform thanks to his toolchain builder which allows corss-compiling.

The idea is that the TARGET architecture to emulate is selected in compile-time.
The repository architecture is made to easily accommodate new architectures if needed (scalability).

The system calls are interfaced with the host machine, there is no self emulator interface. 
Software interrupts are interfaced only for x86, x64 and ARM host machine.

BlueSeed specifity:
  - Binary format : ELF
  - Emultation options (describe in root README)
  - Instruction Set handled:
    - rv32i (standard Instruction Set)
    - rv64i (standard Instruction Set)
    - compressed (32/64)

The [ELF](https://refspecs.linuxbase.org/elf/elf.pdf) loader is very basic and does not allow dynamic linkage with shared object, etc...
Unfortunately GCC needs this to work.

BlueSeed own a runtime debugger. 
Lauch the binary with the “--debug” will open a Command Line Interface (CLI) and execute instruction one by one.
Handled command are display using the command “help” in the CLI.

As an emulator, BlueSeed is very permissive, keep that in mind.

Take time to read the [RISC-V official specification](https://content.riscv.org/wp-content/uploads/2019/06/riscv-spec.pdf), and there was light.

Feel free to fork, use, improve.
