CC		:=	gcc #-coverage

ARRC	:=	ar rc

LIB		:=	libmy.a

LDIR	:=	../build/mylib

includeDir := $(addprefix -I../inc/,			\
								/				\
								basics/			\
								def/			\
								datastructure/	\
								assembly/)

CFLAGS	:=	$(includeDir)		\
			-Wall 				\
			-Wextra 			\
			-Wnested-externs	\
			-Winline			\
			-Wuninitialized		\
			#-Wpadded			\
			-lm

RM	:=	rm -rf

SRC :=	$(wildcard src/*.c src/**/*.c)

OBJ := 	$(patsubst src/%.c, $(LDIR)/%.o, $(SRC))

.PHONY: all re

all:	$(LIB)

fclean:
	$(RM) $(LDIR)

re:	fclean all

$(LIB):	$(OBJ)
	@$(ARRC) $(LIB) $(OBJ)
	@echo -e " LINKED   $@"
	@mv $(LIB) $(LDIR)

$(LDIR)/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC   $@"
