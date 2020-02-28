 #
# Root Makefile who set project var & call sub-build
 #

# Toolchain Builder
ROOT_TOOLCHAIN		:=	$(shell realpath mktoolchain)
MKTOOLCHAIN			:=	mktoolchain
TOOLCHAIN			:=	toolchain
BUILD_PROPERTIES	:=	build-properties

# Toolchain variable depend
export CC
export ARCH_HOST

export REALPATH_PROJECT	:=	$(realpath .)
export PROJECT			:=	BlueSeed
export VERSION			:=	0.1.0
export BIN_EXTENSION	:=	bin
export BINARY			=	$(PROJECT)_$(ARCH_HOST)-$(VERSION)-$(TARGET).$(BIN_EXTENSION)

export BUILDIR	:=	$(realpath .)/build

export ALLOWED_ARCH	:= riscv32 riscv64
export HANDLE_IS	:= rv32i rv64i rv32m rv64m rv32a rv64a rv32f rv64f rv32d rv64d compressed

export EXTENSION_SRC	:=	.c
export EXTENSION_OBJ	:=	.o
export EXTENSION_ASM	:=	.S

export ROOT_SRC_DIR	:= src
export ROOT_INC_DIR	:= inc
export ROOT_ARC_DIR	:= arch

export ARCH_SHARED	:= shared

export TARGET_BASE	:=	$(shell echo "$(TARGET)" | sed 's/[0-9]//g')

export INCLUDE_DIR =	$(addprefix -I$(realpath $(ROOT_INC_DIR))/,		.)

INCLUDE_DIR	+= $(addprefix -I$(realpath $(ROOT_INC_DIR)/$(ROOT_ARC_DIR)/$(TARGET_BASE))/,		\
						/																		\
						$(TARGET)																\
						$(ARCH_SHARED)															\
						$(addprefix isa/,														\
									$(HANDLE_IS)												\
						)																		\
				)

export	LDFLAGS	=	--trace

# Cleaner as possible
export  CFLAGS	=	$(INCLUDE_DIR)						\
					-MMD								\
					-MF		dep.d						\
					-Wall								\
					-Wextra				 				\
					-Wnested-externs					\
					-Winline							\
					-Wpragmas							\
					--std=gnu11							\
					-Wuninitialized						\
					-Wno-missing-braces					\
					-Wcast-align						\
					-Wwrite-strings						\
					-static					 			\
					-Wparentheses						\
					-Wunreachable-code					\
					-Wunused							\
					-Wmissing-field-initializers		\
					-Wswitch-enum						\
					-Wshadow				 			\
					-Wuninitialized				 		\
					-Wmissing-declarations				\
					-Wmissing-prototypes				\
					-Wstrict-prototypes					\
					-Wpointer-arith						\
					-lm									\
					# -Werror

# Compile-time Macro
CFLAGS		+=	'-D PROJECT_NAME="$(PROJECT)"'			\
				'-D SUPPORTED_ARCH="$(ALLOWED_ARCH)"'	\
				'-D INSTRUCTION_SET="$(HANDLE_IS)"'		\
				'-D TARGETED_ARCH="$(TARGET)"'


# Debug mode
export 	CFLAGSDEBUG	= 	-D DEBUG \
						-g3

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += $(CFLAGSDEBUG)
endif

export	RM	=	rm -rf

# System target adressing size
ifeq ($(TARGET), riscv64)
	CFLAGS +=	-D SYSTEMSZ=64
else
	CFLAGS +=	-D SYSTEMSZ=32
endif

.SECONDEXPANSION:
# Savage method
TARGET_BUILT_OBJECT	= 	$(shell find $(BUILDIR) -name '*$(EXTENSION_OBJ)')

.PHONY: all build fclean debug clean $(BINARY)

all:	toolchain	build	$(BINARY)

build:
	@make -C $(ROOT_SRC_DIR) --no-print-directory

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(BINARY) | source-highlight -s asm -f esc256 | less -eRiMX

re:	fclean all

clean:
	@$(RM) $(BUILDIR)

fclean:	clean
	@$(RM) $(PROJECT)_*.bin 
	@$(RM) vgcore.*
	@$(RM) $(shell $(realpath $(find . -name dep.d)))

$(BINARY):	$(.SECONDEXPANSION)
	@$(CC) -o $(BINARY) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e " LINKED      $@"

run:
# Savage method
ifeq ($(EXEC),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mYou must specify a binary to exec\e[0m\n"
	@exit 1
else
	@./$(PROJECT)_$(ARCH_HOST)-$(VERSION)* $(EXEC) --verbose --explicit
endif

help:
	@echo -e "make TARGET=riscvx"

toolchain:
ifeq ($(shell test -f $(ROOT_TOOLCHAIN)/$(BUILD_PROPERTIES) && echo -n built), built)
	$(eval CC			=	$(ROOT_TOOLCHAIN)/$(shell cat $(ROOT_TOOLCHAIN)/$(BUILD_PROPERTIES) | grep CC | cut -d = -f 2))
	$(eval ARCH_HOST	=	$(ROOT_TOOLCHAIN)/$(shell cat $(ROOT_TOOLCHAIN)/$(BUILD_PROPERTIES) | grep ARCH_HOST | cut -d = -f 2))
else
	$(eval CC			=	gcc)
	$(eval ARCH_HOST	=	$(shell lscpu | head -n 1 | cut -d ' ' -f 2- | xargs))
endif
