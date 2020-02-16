ROOT_TOOLCHAIN	:= 	mktoolchain
MKTOOLCHAIN		:=	mktoolchain

# TODO: gcc cross-compiler
export CC		:=	gcc

export NASM		:=	nasm

export PROJECT			:=	BlueSeed
export REALPATH_PROJECT	:=	$(realpath .)
export ARCH_HOST		:=	$(shell lscpu | head -n 1 | cut -d ' ' -f 2- | xargs)
export VERSION			:=	0.1.0
export BIN_EXTENSION	:=	bin
export BINARY			:=	$(PROJECT)_$(ARCH_HOST)-$(VERSION)-$(TARGET).$(BIN_EXTENSION)

export BUILDIR	:=	$(realpath .)/build

export ALLOWED_ARCH	:= riscv32 riscv64
export HANDLE_IS	:= rv32i rv64i rv32m rv64m rv32a rv64a rv32f rv64f rv32d rv64d

export EXTENSION_SRC	:=	.c
export EXTENSION_OBJ	:=	.o

export ROOT_SRC_DIR	:= src
export ROOT_INC_DIR	:= inc
export ROOT_ARC_DIR	:= arch

export ARCH_SHARED	:= shared

export INCLUDE_DIR =	$(addprefix -I$(realpath $(ROOT_INC_DIR))/,				\
									.											\
									def											\
									control										\
									assembly									\
									opt											\
									loader										\
						)

INCLUDE_DIR	+= $(addprefix -I$(realpath $(ROOT_ARC_DIR))/,		\
						/										\
						$(TARGET)								\
						$(ARCH_SHARED)							\
						$(addprefix isa/,						\
									$(HANDLE_IS)				\
						)										\
				)

SOURCE_DIR	:=	$(ROOT_SRC_DIR)									\
				$(addprefix $(ROOT_SRC_DIR)/,					\
							opt									\
							arch								\
							control								\
							loader								\
				)

LDFLAGS	:=	--trace

export  CFLAGS	=	$(INCLUDE_DIR)					\
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

CFLAGS		+=	'-D PROJECT_NAME="$(PROJECT)"'			\
				'-D SUPPORTED_ARCH="$(ALLOWED_ARCH)"'	\
				'-D INSTRUCTION_SET="$(HANDLE_IS)"'

CFLAGSDEBUG	:= -D DEBUG -g3

RM			:=	rm -rf


ROOT_SOURCE 	=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SOURCE_DIR)))

ROOT_OBJECT 	= 	$(patsubst $(ROOT_SRC_DIR)/%$(EXTENSION_SRC), $(BUILDIR)/%$(EXTENSION_OBJ), $(ROOT_SOURCE))

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	= 	$(wildcard $(addprefix $(BUILDIR)/$(ROOT_ARC_DIR)/$(TARGET)/,		\
											*$(EXTENSION_OBJ)								\
											**/*$(EXTENSION_OBJ)							\
									)														\
						)																	\
						$(wildcard $(addprefix $(BUILDIR)/$(ROOT_ARC_DIR)/$(ARCH_SHARED)/,	\
											*$(EXTENSION_OBJ)								\
											**/*$(EXTENSION_OBJ)							\
									)														\
						)	

.PHONY: all fclean debug clean

all:	projectHeader	$(ROOT_OBJECT)	subBuild	$(BINARY)

subBuild:
	@make -C $(ROOT_SRC_DIR)/$(ROOT_ARC_DIR) --no-print-directory

projectHeader:
	@echo "$(INCLUDE_DIR)"
	@exit 0
ifeq ($(TARGET),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mNo TARGET architecture given, processus stopped\e[0m\n"
	@exit 1
else
	@echo -e "\n *"
	@echo -e "*  Building $(BINARY) $(TARGET) target"
	@echo -e " *\n"
endif

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(BINARY) | source-highlight -s asm -f esc256 | less -eRiMX

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += $(CFLAGSDEBUG)
endif

re:	fclean all

clean:
	@$(RM) $(BUILDIR)

fclean:	clean
	@$(RM) $(PROJECT)_$(ARCH_HOST)-$(VERSION)* vgcore.*

$(BINARY):	$(.SECONDEXPANSION) $(ROOT_OBJECT)
	@$(CC) -o $(BINARY) $(ROOT_OBJECT) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e " LINKED      $@"

$(BUILDIR)/%$(EXTENSION_OBJ): $(ROOT_SRC_DIR)/%$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"

run:
ifeq ($(EXEC),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mYou must specify a binary to exec\e[0m\n"
	@exit 1
else
	@./$(BINARY) $(EXEC)
endif

toolchain:
	@./$(ROOT_TOOLCHAIN)/$(MKTOOLCHAIN) $(TARGET)