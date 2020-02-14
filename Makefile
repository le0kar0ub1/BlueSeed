ROOT_TOOLCHAIN	:= 	mktoolchain
MKTOOLCHAIN		:=	mktoolchain

CC		:=	gcc

NASM	:=	nasm

PROJECT	:=	BlueSeed
BINARY	:=	BlueSeed_$(shell lscpu | head -n 1 | cut -d ' ' -f 2- | xargs)-0.1.0.bin

BUILDIR	:=	build

LDFLAGS	:=

TARGET_ARCH	:= riscv32 riscv64 riscv128
TARGET_IS	:= rv32i rv64i rv32m rv64m rv32a rv64a rv32f rv64f rv32d rv64d

EXTENSION_SRC	:=	.c
EXTENSION_OBJ	:=	.o

ROOT_SRC_DIR	= src
ROOT_INC_DIR	= inc
ROOT_ARC_DIR	= arch

INCLUDE_DIR :=	$(addprefix -I$(ROOT_INC_DIR)/,				\
						.									\
						def									\
						control								\
						assembly							\
						opt									\
				)

INCLUDE_DIR	+= $(addprefix -I$(ROOT_ARC_DIR)/,		\
						.							\
						$(TARGET_ARCH)				\
						$(addprefix isa/,			\
									$(TARGET_IS)	\
						)							\
				)

SOURCE_DIR	:=	$(ROOT_SRC_DIR)									\
				$(addprefix $(ROOT_SRC_DIR)/,					\
							opt									\
							arch								\
							$(addprefix arch/,	$(TARGET_ARCH))	\
				)

CFLAGS		:=	$(INCLUDE_DIR)						\
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
				'-D SUPPORTED_ARCH="$(TARGET_ARCH)"'	\
				'-D INSTRUCTION_SET="$(TARGET_IS)"'

CFLAGSDEBUG	:= -D DEBUG -g3

RM		:=	rm -rf

SRC_C 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SOURCE_DIR)))

OBJ 	:= 	$(patsubst $(ROOT_SRC_DIR)/%$(EXTENSION_SRC), $(BUILDIR)/%$(EXTENSION_OBJ), $(SRC_C))

.PHONY: all fclean debug clean

all:	$(PROJECT)

buildheader:
	@echo -e "\n *"
	@echo -e "*  Building $(BINARY)"
	@echo -e " *\n"

disassemble: $(PROJECT)
	@objdump --no-show-raw-insn -d -Mintel $(PROJECT) | source-highlight -s asm -f esc256 | less -eRiMX

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += $(CFLAGSDEBUG)
endif

re:	fclean all

$(PROJECT):	buildheader $(OBJ)
	@$(CC) -o $(PROJECT) $(OBJ) $(LDFLAGS)
	@-echo -e " LINKED      $@"

clean:
	@$(RM) $(BUILDIR)

fclean:	clean
	@$(RM) $(PROJECT) vgcore.*

$(BUILDIR)/%$(EXTENSION_OBJ): $(ROOT_SRC_DIR)/%$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $@"

run:
	@make --no-print-directory debug=1
	@./$(PROJECT) --target=riscv64 sample/sample.bin

toolchain:
	@./$(ROOT_TOOLCHAIN)/$(MKTOOLCHAIN) $(TARGET)