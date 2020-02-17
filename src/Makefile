 #
# Makefile Compiling object which are arch independant & calling the targeted ARCH
 #

ROOT_SOURCE_DIR	:=	$(ROOT_SRC_DIR)									\
					$(addprefix ./,									\
								opt									\
								control								\
								loader								\
								runtimeTools						\
								sheduler							\
					)

ROOT_PREFIX_BUILD	:=	$(shell realpath --relative-to $(REALPATH_PROJECT)/$(ROOT_SRC_DIR) .)

ROOT_SOURCE 	=	$(wildcard ./*$(EXTENSION_SRC)										\
								$(addsuffix /*$(EXTENSION_SRC), $(ROOT_SOURCE_DIR))		\
								$(addsuffix /**/*$(EXTENSION_SRC), $(ROOT_SOURCE_DIR))	\
					)

ROOT_OBJECT 	= 	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/%$(EXTENSION_OBJ), $(ROOT_SOURCE))


.PHONY: all	subBuild

all:	projectHeader	$(ROOT_OBJECT)	subBuild

projectHeader:
ifeq ($(TARGET),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mNo TARGET architecture given, processus stopped\e[0m\n"
	@exit 1
else ifeq ($(filter $(TARGET),$(ALLOWED_ARCH)),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mThe given TARGET isn't allowed ($(ALLOWED_ARCH))\e[0m\n"
	@exit 1
else
	@echo -e "\n *"
	@echo -e "*  Building $(BINARY)"
	@echo -e " *\n"
endif

subBuild:
	@make -C $(ROOT_ARC_DIR) --no-print-directory

$(BUILDIR)/$(ROOT_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(REALPATH_PROJECT) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"