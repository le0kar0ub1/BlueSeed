 #
# Makefile Compiling object for RISCV64 target
 #

SOURCE_DIR_RISCV64		:=	core 	\
							.
PREFIX_BUILD_RISCV64	:=	$(shell realpath --relative-to $(REALPATH_PROJECT)/$(ROOT_SRC_DIR) .)

SRC_RISCV64 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SOURCE_DIR_RISCV64)))

OBJ_RISCV64 	:= 	$(patsubst ./%$(EXTENSION_SRC), $(BUILDIR)/$(PREFIX_BUILD_RISCV64)/%$(EXTENSION_OBJ), $(SRC_RISCV64))

.PHONY: all

all:	$(OBJ_RISCV64)

$(BUILDIR)/$(PREFIX_BUILD_RISCV64)/%$(EXTENSION_OBJ): ./%$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"