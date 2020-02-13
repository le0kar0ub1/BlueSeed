CC		:=	gcc

NASM	:=	nasm

BINARY	:=	blueSeed

BUILDIR	:=	build

LDFLAGS	:=	-L./$(BUILDIR)/mylib -lmy

TARGET_ARCH	:= riscv64 riscv32 riscv128 x86 x64

EXTENSION_SRC	:=	.c
EXTENSION_OBJ	:=	.o

ROOT_SRC_DIR	= src/
ROOT_INC_DIR	= inc/

INCLUDE_DIR := $(addprefix -I$(ROOT_INC_DIR),	\
							/					\
							basics/				\
							def/				\
							datastructure/		\
							assembly/			\
							opt/				\
							$(addprefix arch/,			\
										/				\
										$(TARGET_ARCH)	\
										)				\
							)

SOURCE_DIR	:=	$(addprefix $(ROOT_SRC_DIR),	\
							/					\
							opt/				\
							$(addprefix arch/,			\
										/				\
										$(TARGET_ARCH)	\
										)				\
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
				# -Werror

CFLAGSDEBUG	:= -D DEBUG -g3

RM		:=	rm -rf

SRC_C   :=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SOURCE_DIR)))

OBJ 	:= 	$(patsubst $(ROOT_SRC_DIR)%$(EXTENSION_SRC), $(BUILDIR)/%$(EXTENSION_OBJ), $(SRC_C))

.PHONY: all fclean run disassemble debug clean

all:	$(BINARY)

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(BINARY) | source-highlight -s asm -f esc256 | less -eRiMX

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

fclean:
	@$(RM) $(BUILDIR) $(BINARY) vgcore.*

$(BUILDIR)/%$(EXTENSION_OBJ): $(ROOT_SRC_DIR)%$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $@"

run:
	@./$(BINARY) --target=riscv64 sample/sample.bin
