CC		:=	gcc

NASM	:=	nasm

BINARY	:=	Atomizer

BUILDIR	:=	build

LDFLAGS	:=	-L./$(BUILDIR)/mylib -lmy

includeDir := $(addprefix -Iinc/,			\
							/				\
							basics/			\
							def/			\
							datastructure/	\
							assembly/)

CFLAGS		:=	$(includeDir)		\
				-Wall 				\
				-Wextra 			\
				-Wnested-externs	\
				-Winline			\
				-Wuninitialized		\
				#-Wpadded			\
				-lm

CFLAGSDEBUG	:= -D DEBUG -g3

RM		:=	rm -rf

SRC_C   :=	$(wildcard src/*.c src/**/*.c)

OBJ 	:= 	$(patsubst src/%.c, $(BUILDIR)/%.o, $(SRC_C))

.PHONY: all fclean run disassemble debug clean

all:	mylib	$(BINARY)

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(BINARY) | source-highlight -s asm -f esc256 | less -eRiMX

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += -D DEBUG
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

fclean:
	@$(RM) $(BUILDIR) $(BINARY) vgcore.*

$(BUILDIR)/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $@"

run:
	@./$(BINARY)
