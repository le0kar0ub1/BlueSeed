 #
# Makefile Compiling object which are arch independant & calling the targeted ARCH
 #

RISCV_INSTRUCTION_TYPE	:=	i_type		\
							b_type		\
							j_type		\
							r_type		\
							s_type		\
							u_type		\
							r4_type		\
							compressed	\
							pseudo

SHARED_SOURCE_DIR	:=	$(ARCH_SHARED)									\
						$(addprefix $(ARCH_SHARED)/,					\
								runtime									\
								memory									\
								debugger								\
								processor								\
								syscall									\
								register								\
								core									\
								$(addprefix opcode_dichotomy/,			\
										$(RISCV_INSTRUCTION_TYPE)		\
								)										\
						)

SHARED_PREFIX_BUILD	:=	$(shell realpath --relative-to $(REALPATH_PROJECT)/$(ROOT_SRC_DIR) .)

SHARED_C_SOURCE 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SHARED_SOURCE_DIR)))

SHARED_C_OBJECT 	:= 	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(SHARED_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(SHARED_C_SOURCE))

SHARED_ASM_SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(SHARED_SOURCE_DIR)))

SHARED_ASM_OBJECT 	:= 	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(SHARED_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(SHARED_ASM_SOURCE))


.PHONY: all	target_building

all:	shared_building		$(SHARED_C_OBJECT)	$(SHARED_ASM_OBJECT)	target_building

shared_building:
	@echo -e "\n\nBuilding shared $(TARGET_BASE) objects..."
	@echo ""

target_building:
	@echo -e "\n\nBuilding $(TARGET) specific target...\n"
	@make -C $(TARGET) --no-print-directory
	@echo ""

$(BUILDIR)/$(SHARED_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"

$(BUILDIR)/$(SHARED_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@exit
	@$(CC) -c $< -o $@
	@-echo -e "     AS      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"