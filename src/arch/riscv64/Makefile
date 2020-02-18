 #
# Makefile Compiling object for RISCV64 target
 #

RISCV64_SOURCE_DIR		:=	core 		\
							isa			\
							memory		\
							processor	\
							syscall		\
							.

RISCV64_PREFIX_BUILD	:=	$(shell realpath --relative-to $(REALPATH_PROJECT)/$(ROOT_SRC_DIR) .)

RISCV64_SOURCE 		:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(RISCV64_SOURCE_DIR)))

RISCV64_ASM_SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(RISCV64_SOURCE_DIR)))

RISCV64_OBJECT 		= 	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(RISCV64_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(RISCV64_SOURCE))

RISCV64_ASM_OBJECT 	= 	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(RISCV64_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(RISCV64_ASM_SOURCE))

.PHONY: all

all:	$(RISCV64_OBJECT)	$(RISCV64_ASM_OBJECT)

$(BUILDIR)/$(RISCV64_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"

$(BUILDIR)/$(RISCV64_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@exit
	@$(CC) -c $< -o $@
	@-echo -e "     AS      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"