# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 11:48:51 by lseabra-          #+#    #+#              #
#    Updated: 2025/07/10 11:53:39 by lseabra-         ###   ########.fr        #
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

# Library name
NAME                = libft.a

# Paths
BUILD_PATH          = build
SRCS_PATH           = srcs
FT_PRINTF_SRCS_PATH = srcs_ft_printf
GNL_SRCS_PATH       = srcs_gnl

# Source files
SRCS = $(addprefix $(SRCS_PATH)/, \
    ft_isalpha.c    ft_isdigit.c    ft_isalnum.c    ft_isascii.c \
    ft_isprint.c    ft_strlen.c     ft_memset.c     ft_bzero.c \
    ft_memcpy.c     ft_memmove.c    ft_strlcpy.c    ft_strlcat.c \
    ft_toupper.c    ft_tolower.c    ft_strchr.c     ft_strrchr.c \
    ft_strncmp.c    ft_memchr.c     ft_memcmp.c     ft_strnstr.c \
    ft_atoi.c       ft_calloc.c     ft_strdup.c     ft_substr.c \
    ft_strjoin.c    ft_strtrim.c    ft_split.c      ft_itoa.c \
    ft_strmapi.c    ft_striteri.c   ft_putchar_fd.c ft_putstr_fd.c \
    ft_putendl_fd.c ft_putnbr_fd.c \
)
BONUS_SRCS = $(addprefix $(SRCS_PATH)/, \
    ft_lstnew_bonus.c      ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
    ft_lstlast_bonus.c     ft_lstadd_back_bonus.c  ft_lstdelone_bonus.c \
    ft_lstclear_bonus.c    ft_lstiter_bonus.c      ft_lstmap_bonus.c \
)
FT_PRINTF_SRCS = $(addprefix $(FT_PRINTF_SRCS_PATH)/, \
    ft_printf.c         ft_print_c.c      ft_print_s.c      ft_print_p.c \
    ft_print_d.c        ft_print_u.c      ft_print_hex.c \
    ft_putchar_count.c  ft_putstr_count.c ft_uintlen_base.c \
    ft_putnbr_count.c   ft_putunbr_count.c \
)
GNL_SRCS = $(addprefix $(GNL_SRCS_PATH)/, get_next_line.c get_next_line_utils.c)
GNL_BONUS_SRCS = $(addprefix $(GNL_SRCS_PATH)/, get_next_line_bonus.c get_next_line_utils_bonus.c)

# Object files
OBJS            = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))
BONUS_OBJS      = $(addprefix $(BUILD_PATH)/, $(notdir $(BONUS_SRCS:.c=.o)))
FT_PRINTF_OBJS  = $(addprefix $(BUILD_PATH)/, $(notdir $(FT_PRINTF_SRCS:.c=.o)))
GNL_OBJS        = $(addprefix $(BUILD_PATH)/, $(notdir $(GNL_SRCS:.c=.o)))
GNL_BONUS_OBJS  = $(addprefix $(BUILD_PATH)/, $(notdir $(GNL_BONUS_SRCS:.c=.o)))

# Bonus mark
BONUS_MARK      = .bonus

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Utility commands
TCH     = touch
RM      = rm -f
RM_DIR  = rm -rf
AR      = ar rcs
MKDIR_P = mkdir -p

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)
	@$(AR) $(NAME) $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)
	@echo "$(GREEN)[Library $(NAME) created!]$(RESET)"

$(BUILD_PATH)/%.o: $(SRCS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(FT_PRINTF_SRCS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(GNL_SRCS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo "$(BLUE)[Build directory created.]$(RESET)"

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(GNL_BONUS_OBJS) | $(BUILD_PATH)
	@$(AR) $(NAME) $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(GNL_BONUS_OBJS)
	@$(TCH) $(BONUS_MARK)
	@echo "$(YELLOW)[Bonus library $(NAME) created with bonus objects!]$(RESET)"

clean:
	@$(RM_DIR) $(BUILD_PATH)
	@$(RM) $(BONUS_MARK)
	@echo "$(BLUE)[Cleaned build files.]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)[Full clean: library removed.]$(RESET)"

re: fclean all
