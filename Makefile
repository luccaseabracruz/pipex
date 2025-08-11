# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 11:48:51 by lseabra-          #+#    #+#              #
#    Updated: 2025/08/11 14:08:20 by lseabra-         ###   ########.fr        #
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

# Names
NAME                = pipex
PROJECT_NAME        = PIPEX

# Paths
SRCS_PATH           = srcs
SRCS_BONUS_PATH     = srcs_bonus
BUILD_PATH          = build

# Source files
SRCS = $(addprefix $(SRCS_PATH)/, \
    main.c exec.c    get_path.c utils.c \
)
SRCS_BONUS = $(addprefix $(SRCS_BONUS_PATH)/, \
    main_bonus.c    children_utils_bonus.c    init_data_bonus.c \
    clean_bonus.c   get_path.c utils.c \
)

# Object files
OBJS       = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS_BONUS:.c=.o)))

# Marks
MANDATORY_MARK = .mandatory
BONUS_MARK     = .bonus

# Compiler and flags
CC     = cc
CFLAGS = -Wall -Wextra -Werror -g

# Utility commands
TC      = touch
RM      = rm -f
RM_DIR  = rm -rf
AR      = ar rcs
MKDIR_P = mkdir -p
MAKE    = make --no-print-directory

# LIBFT
LIBFT_PATH = libft
LIBFT_NAME = $(LIBFT_PATH)/libft.a

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(MANDATORY_MARK)

$(MANDATORY_MARK): $(OBJS) $(LIBFT_NAME)
	@$(RM) $(BONUS_MARK)
	@$(TC) $(MANDATORY_MARK)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_NAME) -o $@
	@echo "$(GREEN)[$(PROJECT_NAME)] Executable compiled: $(NAME)$(RESET)"

$(BUILD_PATH)/%.o: $(SRCS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(SRCS_BONUS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo "$(GREEN)[$(PROJECT_NAME)] Build directory created$(RESET)"

$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_PATH) bonus

clean:
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM_DIR) $(BUILD_PATH)
	@echo "$(GREEN)[$(PROJECT_NAME)] Cleaned build files $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_MARK)
	@echo "$(GREEN)[$(PROJECT_NAME)] Full clean: Executable $(NAME) removed $(RESET)"

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(OBJS_BONUS) $(LIBFT_NAME)
	@$(RM) $(MANDATORY_MARK)
	@$(TC) $(BONUS_MARK)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_NAME) -o $(NAME)
	@echo "$(GREEN)[$(PROJECT_NAME)] Bonus executable compiled: $(NAME)$(RESET)"

re: fclean all
