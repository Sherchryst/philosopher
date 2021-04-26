# This is a minimal set of ANSI/VT100 color codes
Color_Off=\033[0m
_GREEN=\033[1;32m
_CYAN=\033[1;36m
BBlack="\[\033[1;30m\]"       # Black
BRed="\[\033[1;31m\]"         # Red    # Green
BYellow="\[\033[1;33m\]"      # Yellow
_Orange=\033[1;96m        # Blue
_Purple=\033[1;35m
BWhite="\[\033[1;37m\]"       # White

# DIRECTORIES
BUILD	= ./.build

SRC_DIR	= ./src/

# FILES
NAME	= philo_one

SRC		= main.c \
		  tools.c \

SRCS	= $(addprefix $(SRC_DIR), $(SRC))

DEP		:= $(SRC:%.c=$(BUILD)/%.d)
OBJ		:= $(SRC:%.c=$(BUILD)/%.o)

# COMPILATION
CC		= clang
CFLAGS	= -Wall -Werror -Wextra
DFLAGS	= -MP -MMD
INC		= -I./include

$(NAME):$(OBJ)
	@$(CC) $(INC) $(OBJ) -o $(NAME) -lpthread
	@echo ""
	@echo "${_GREEN}The executable file of ${Color_Off}${_Orange}"
	@echo "   ▄███████▄    ▄█    █▄     ▄█   ▄█        ▄██████▄            ▄██████▄  ███▄▄▄▄      ▄████████ "
	@echo "  ███    ███   ███    ███   ███  ███       ███    ███          ███    ███ ███▀▀▀██▄   ███    ███ "
	@echo "  ███    ███   ███    ███   ███▌ ███       ███    ███          ███    ███ ███   ███   ███    █▀  "
	@echo "  ███    ███  ▄███▄▄▄▄███▄▄ ███▌ ███       ███    ███          ███    ███ ███   ███  ▄███▄▄▄     "
	@echo "▀█████████▀  ▀▀███▀▀▀▀███▀  ███▌ ███       ███    ███          ███    ███ ███   ███ ▀▀███▀▀▀     "
	@echo "  ███          ███    ███   ███  ███       ███    ███          ███    ███ ███   ███   ███    █▄  "
	@echo "  ███          ███    ███   ███  ███▌    ▄ ███    ███          ███    ███ ███   ███   ███    ███ "
	@echo " ▄████▀        ███    █▀    █▀   █████▄▄██  ▀██████▀  ▀██████▀  ▀██████▀   ▀█   █▀    ██████████ "
	@echo "                                 ▀                                                 ${Color_Off}"
	@echo "                                                                             ${_GREEN}Has been created!${Color_Off}"


all: $(NAME)

clean:
	@rm -rf $(BUILD)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning build\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning exec\t\033[0;32m[OK]\033[0m"

re: fclean all

$(BUILD):
	@echo "\033[1;32m\nCreation of .build\033[0m \n"
	@mkdir $@

$(BUILD)/%.o: $(SRC_DIR)%.c | $(BUILD)
	@printf "\033[1;34mExecute: \t\033[1;33mCompilation of \033[1;36m$(notdir $<) \033[0m \
	 %-33.33s\r"
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ $(INC)

-include $(DEP)

.PHONY: all clean fclean re
