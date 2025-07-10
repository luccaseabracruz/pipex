# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 11:48:51 by lseabra-          #+#    #+#              #
#    Updated: 2025/07/10 13:06:22 by lseabra-         ###   ########.fr        #
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
SRCS = $(addprefix $(SRCS_PATH)/, )

# Object files
OBJS            = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))

# Bonus mark
#BONUS_MARK      = .bonus

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Utility commands
#TCH     = touch
RM      = rm -f
RM_DIR  = rm -rf
AR      = ar rcs
MKDIR_P = mkdir -p

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MAIN) $(OBJS) $< -o $@

$(BUILD_PATH)/%.o: $(SRCS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo "$(BLUE)[Build directory created.]$(RESET)"

#bonus: $(BONUS_MARK)

#$(BONUS_MARK): $(OBJS) | $(BUILD_PATH)

clean:
	@$(RM_DIR) $(BUILD_PATH)
	@echo "$(BLUE)[Cleaned build files.]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)[Full clean: library removed.]$(RESET)"

re: fclean all
