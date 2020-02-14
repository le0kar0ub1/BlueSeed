ROOT_TOOLCHAIN	:= 	mktoolchain
MKTOOLCHAIN		:=	mktoolchain

CC		:=	gcc

NASM	:=	nasm

BINARY	:=	blueSeed

BUILDIR	:=	build

LDFLAGS	:=	-L./$(BUILDIR)/mylib -lmy

TARGET_ARCH	:= riscv32 riscv64 riscv128

EXTENSION_SRC	:=	.c
EXTENSION_OBJ	:=	.o

ROOT_SRC_DIR	= src
ROOT_INC_DIR	= inc

INCLUDE_DIR :=	$(addprefix -I$(ROOT_INC_DIR)/,				\
						.									\
						basics								\
						def									\
						datastructure						\
						assembly							\
						opt									\
						arch								\
						$(addprefix arch/, $(TARGET_ARCH))	\
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
				-ffreestanding						\
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

CFLAGS		+=	'-D PROJECT_NAME="$(BINARY)"'			\
				'-D SUPPORTED_ARCH="$(TARGET_ARCH)"'	\

CFLAGSDEBUG	:= -D DEBUG -g3

RM		:=	rm -rf

SRC_C 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SOURCE_DIR)))

OBJ 	:= 	$(patsubst $(ROOT_SRC_DIR)/%$(EXTENSION_SRC), $(BUILDIR)/%$(EXTENSION_OBJ), $(SRC_C))

.PHONY: all fclean debug clean

all:	mylib	$(BINARY)

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(BINARY) | source-highlight -s asm -f esc256 | less -eRiMX

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += $(CFLAGSDEBUG)
endif

re:	fclean all

mylib:
	@echo -e "BUILDING LIB"
	@make -C lib/ --no-print-directory
	@echo -e "\nBUILDING PROJECT"

$(BINARY):	$(OBJ)
	@$(CC) -o $(BINARY) $(OBJ) $(LDFLAGS)
	@-echo -e " LINKED      $@"

clean:
	@$(RM) $(BUILDIR)

fclean:	clean
	@$(RM) $(BINARY) vgcore.*

$(BUILDIR)/%$(EXTENSION_OBJ): $(ROOT_SRC_DIR)/%$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $@"

run:
	@make --no-print-directory debug=1
	@./$(BINARY) --target=riscv64 #sample/sample.bin

install:
	@./$(ROOT_TOOLCHAIN)/$(MKTOOLCHAIN) $(TARGET)