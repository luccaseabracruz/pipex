# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 11:48:51 by lseabra-          #+#    #+#              #
#    Updated: 2025/07/21 21:51:52 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                 COLOR CODES                                  #
#==============================================================================#

GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
RESET   = \033[0m

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# Executable name
NAME                = pipex

# Main file
MAIN = main.c

# Paths
SRCS_PATH           = srcs
BUILD_PATH          = build

# Source files
SRCS = $(addprefix $(SRCS_PATH)/, exec.c get_path.c utils.c)

# Object files
OBJS            = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))

# Bonus mark
#BONUS_MARK      = .bonus

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Utility commands
RM      = rm -f
RM_DIR  = rm -rf
AR      = ar rcs
MKDIR_P = mkdir -p

# LIBFT
LIBFT_PATH = libft
LIBFT_NAME = $(LIBFT_PATH)/libft.a

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(LIBFT_NAME) -o $@ -g
	@echo "$(GREEN)[Executable compiled: $(NAME).]$(RESET)"

$(BUILD_PATH)/%.o: $(SRCS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo "$(BLUE)[Build directory created.]$(RESET)"

$(LIBFT_NAME):
	make -C $(LIBFT_PATH) bonus

clean:
	@$(RM_DIR) $(BUILD_PATH)
	@echo "$(BLUE)[Cleaned build files.]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)[Full clean: library removed.]$(RESET)"

re: fclean all
