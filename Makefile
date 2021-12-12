# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 14:09:00 by adbenoit          #+#    #+#              #
#    Updated: 2021/12/12 19:11:07 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror #-fsanitize=address -g3
IFLAGS 	= -I./incs


# DIRECTORIES
BUILD 			:= .build
OBJ_DIR 		:= $(BUILD)/obj
SRC_DIR 		:= srcs
DIRS			:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))


# FILES
NAME			:= hotrace
SRC				:= main.c \
				   utils.c \
				   handle_data.c \
				   hash_data.c \
				   search_data.c \
				   insert_data.c \
				   read_file.c \
				   hotrace.c

OBJ				:= $(SRC:%.c=$(OBJ_DIR)/%.o)


# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m


# MAKEFILE
all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CL_LINE)"
	@echo "[1 / 1] - $(B_MAGENTA)$@$(NONE)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "$(B_GREEN)Compilation done !$(NONE)"


clean:
	@rm -Rf $(BUILD)
	@echo "$(B_RED)$(BUILD)$(NONE): $(B_GREEN)Delete$(NONE)"

fclean: clean
	@rm -Rf $(NAME)
	@echo "$(B_RED)$(NAME)$(NONE): $(B_GREEN)Delete$(NONE)"

re: fclean all

debug:
	@echo SRC = $(SRC)
	@echo OBJ = $(OBJ)

.PHONY: all clean fclean re debug

$(BUILD):
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c ./incs/hotrace.h | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs object : $(B_CYAN)$< $(NONE)...\r"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
