 #
# Makefile Compiling object which are arch independant & calling the targeted ARCH
 #

SHARED_SOURCE_DIR	:=	$(ARCH_SHARED)							\
						$(ARCH_SHARED)/riscvhandler				\

SHARED_PREFIX_BUILD	:=	$(shell realpath --relative-to $(REALPATH_PROJECT)/$(ROOT_SRC_DIR) .)

SHARED_SOURCE 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SHARED_SOURCE_DIR)))

SHARED_OBJECT 	:= 	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(SHARED_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(SHARED_SOURCE))

.PHONY: all

all:	$(SHARED_OBJECT)	target_building

target_building:
ifneq ($(filter $(TARGET),$(ALLOWED_ARCH)),)
	@echo -e "\nBuilding the given target..."
	@make -C $(TARGET) --no-print-directory
else
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mThe given TARGET isn't allowed ($(ALLOWED_ARCH))\e[0m\n"
	@exit 1
endif

$(BUILDIR)/$(SHARED_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"