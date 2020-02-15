 #
# Makefile Compiling object which are arch independant & call the target ARCH
 #

SOURCE_DIR_SHARED	:=	shared

PREFIX_BUILD_SHARED	:=	$(shell realpath --relative-to $(REALPATH_PROJECT)/$(ROOT_SRC_DIR) .)

SRC_SHARED 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(SOURCE_DIR_SHARED)))

OBJ_SHARED 	:= 	$(patsubst ./%$(EXTENSION_SRC), $(BUILDIR)/$(PREFIX_BUILD_SHARED)/%$(EXTENSION_OBJ), $(SRC_SHARED))

.PHONY: all

all:	$(OBJ_SHARED)	target_building

target_building:
ifneq ($(filter $(TARGET),$(ALLOWED_ARCH)),)
	@echo -e "\nBuilding the given target..."
	@make -C $(TARGET) --no-print-directory
else
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mThe given TARGET isn't allowed ($(ALLOWED_ARCH))\e[0m\n"
	@exit 1
endif

$(BUILDIR)/$(PREFIX_BUILD_SHARED)/%$(EXTENSION_OBJ): ./%$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"