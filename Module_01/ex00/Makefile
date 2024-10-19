# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 14:51:25 by passunca          #+#    #+#              #
#    Updated: 2024/09/14 15:40:59 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

MAKE	= make -C
SHELL	:= bash --rcfile ~/.bashrc

# Default test values
IN_PATH		?= $(SRC_PATH)
ARG				=

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

NAME 			 	= brainz.out
TESTER			= CPP00_01_tester

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_SEP 			= =====================================================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= src
BUILD_PATH	= .build
TEMP_PATH		= .temp
INC_PATH		= inc

FILES				= main.cpp
FILES				+= Zombie.cpp
FILES				+= newZombie.cpp
FILES				+= randomChump.cpp

SRC					= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS				= $(SRC:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CXX					= c++
CXXFLAGS		= -Wall -Wextra -Werror
CXXFLAGS		+= -std=c++98
DEBUG_FLAGS	= -g
INC					= -I $(INC_PATH)


#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

### Core Utils
RM			= rm -rf
AR			= ar rcs
MKDIR_P	= mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

##@ CPP00_00 Compilation Rules 🏗

all: $(NAME)	## Compile

$(NAME): $(BUILD_PATH) $(OBJS)			## Compile
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) mandatory version$(D)"
	$(CXX) $(CXXFLAGS) -I $(INC_PATH) $(OBJS) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🖔$(D)]"

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME) $(TEMP_PATH)			## Compile w/ debug symbols

-include $(BUILD_PATH)/%.d

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo -n "$(MAG)█$(D)"
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(TEMP_PATH):
	$(MKDIR_P) $(TEMP_PATH)
	@echo "* $(YEL)Creating $(CYA)$(TEMP_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

##@ Test Rules 🧪

test: all $(TEMP_PATH)			## Run tests
	@echo "[$(YEL)Running $(GRN)$(NAME)$(YEL) tests$(D)]"
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "$(CYA)$(NAME)$(D): $(MAG)Get Output$(D)"
	./$(NAME) > $(TEMP_PATH)/test_out.txt
	@echo "$(CYA)$(NAME)$(D): $(MAG)Get Diff$(D)"
	sed 's/\[[^]]*\] //' ./19920104_091532.log > $(TEMP_PATH)/reflog.txt
	sed 's/\[[^]]*\] //' $(TEMP_PATH)/test_out.txt > $(TEMP_PATH)/trim.txt
	diff $(TEMP_PATH)/trim.txt $(TEMP_PATH)/reflog.txt
	@echo "$(YEL)$(_SEP)$(D)"

##@ Debug Rules 

gdb: all $(NAME) $(TEMP_PATH)			## Debug w/ gdb
	tmux split-window -h "gdb --tui --args ./$(NAME)"
	tmux resize-pane -L 5
	# tmux split-window -v "btop"
	make get_log

vgdb: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck) & gdb
	tmux split-window -h "valgrind $(VGDB_ARGS) --log-file=gdb.txt ./$(NAME) $(ARG)"
	make vgdb_cmd
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(NAME)"
	tmux resize-pane -U 18
	# tmux split-window -v "btop"
	make get_log

valgrind: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck)
	tmux set-option remain-on-exit on
	tmux split-window -h "valgrind $(VAL_ARGS) $(VAL_LEAK) ./$(NAME) $(ARG)"

massif: all $(TEMP_PATH)		## Run Valgrind w/ Massif (gather profiling information)
	@TIMESTAMP=$(shell date +%Y%m%d%H%M%S); \
	if [ -f massif.out.* ]; then \
		mv -f massif.out.* $(TEMP_PATH)/massif.out.$$TIMESTAMP; \
	fi
	@echo " 🔎 [$(YEL)Massif Profiling$(D)]"
	valgrind --tool=massif --time-unit=B ./$(NAME) $(ARG)
	ms_print massif.out.*
# Learn more about massif and ms_print:
### https://valgrind.org/docs/manual/ms-manual.html

get_log:
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

vgdb_cmd: $(NAME) $(TEMP_PATH)
	@printf "target remote | vgdb --pid=" > $(TEMP_PATH)/gdb_commands.txt
	@printf "$(shell pgrep -f valgrind)" >> $(TEMP_PATH)/gdb_commands.txt
	@printf "\n" >> $(TEMP_PATH)/gdb_commands.txt
	@cat .vgdbinit >> $(TEMP_PATH)/gdb_commands.txt

##@ Clean-up Rules 󰃢

clean: 				## Remove object files
	@echo "*** $(YEL)Removing $(MAG)$(NAME)$(D) and deps $(YEL)object files$(D)"
	@if [ -d "$(BUILD_PATH)" ] || [ -d "$(TEMP_PATH)" ]; then \
		if [ -d "$(BUILD_PATH)" ]; then \
			$(RM) $(BUILD_PATH); \
			echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \
		fi; \
		if [ -d "$(TEMP_PATH)" ]; then \
			$(RM) $(TEMP_PATH); \
			echo "* $(YEL)Removing $(CYA)$(TEMP_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to clean!$(D)]"; \
	fi

fclean: clean			## Remove executable and .gdbinit
	@if [ -f "$(NAME)" ]; then \
		if [ -f "$(NAME)" ]; then \
			$(RM) $(NAME); \
			echo "* $(YEL)Removing $(CYA)$(NAME)$(D) file: $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to be fcleaned!$(D)]"; \
	fi

re: fclean all	## Purge & Recompile

##@ Help 󰛵

help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-18s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

.PHONY: bonus clean fclean re help

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)



