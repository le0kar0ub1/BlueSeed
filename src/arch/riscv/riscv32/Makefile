 #
# Makefile Compiling object for RISCV32 target
 #

RISCV32_SOURCE_DIR		:=	isa			\
							.

RISCV32_PREFIX_BUILD	:=	$(shell realpath --relative-to $(REALPATH_PROJECT)/$(ROOT_SRC_DIR) .)

RISCV32_SOURCE 		:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(RISCV32_SOURCE_DIR)))

RISCV32_ASM_SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(RISCV32_SOURCE_DIR)))

RISCV32_OBJECT 		= 	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(RISCV32_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(RISCV32_SOURCE))

RISCV32_ASM_OBJECT 	= 	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(RISCV32_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(RISCV32_ASM_SOURCE))

.PHONY: all

all:	$(RISCV32_OBJECT)	$(RISCV32_ASM_OBJECT)

$(BUILDIR)/$(RISCV32_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"

$(BUILDIR)/$(RISCV32_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@exit
	@$(CC) -c $< -o $@
	@-echo -e "     AS      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"