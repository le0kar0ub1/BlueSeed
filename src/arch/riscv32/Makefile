 #
# Makefile Compiling object for RISCV32 target
 #

SOURCE_DIR_RISCV32		:=	core 	\
							.

PREFIX_BUILD_RISCV32	:=	$(shell realpath --relative-to $(REALPATH_PROJECT)/$(ROOT_SRC_DIR) .)

SRC_RISCV32 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SOURCE_DIR_RISCV32)))

OBJ_RISCV32 	:= 	$(patsubst ./%$(EXTENSION_SRC), $(BUILDIR)/$(PREFIX_BUILD_RISCV32)/%$(EXTENSION_OBJ), $(SRC_RISCV32))

.PHONY: all

all:	$(OBJ_RISCV32)

$(BUILDIR)/$(PREFIX_BUILD_RISCV32)/%$(EXTENSION_OBJ): ./%$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"