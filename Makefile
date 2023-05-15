# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kblok <kblok@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/16 20:46:21 by kblok         #+#    #+#                  #
#    Updated: 2023/05/04 14:00:05 by kblok         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#==============================================================================: Filename
NAME		= 	minishell 

#==============================================================================: Source to object conversion 
OBJS		= 	$(SRCS:srcs/%.c=objs/%.o)

#==============================================================================: Compile variables
CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -Wunreachable-code
MAKEFLAGS	=	--no-print-directory
RM			=	rm -rf
MKDIR		=	mkdir -p
AR			=	-lreadline -L ~/.brew/opt/readline/lib
HEADERS		= 	-I include -I ~/.brew/opt/readline/include

#============================================================================: Include files
LIBFT		= 	libft

#============================================================================: Source files 
SRCS		=	$(addprefix src/, \
						main.c \
				$(addprefix lexer/, \
					check.c \
					lexer_utils.c \
					lexer.c \
					post_process.c \
					quotes.c) \
				$(addprefix env/, \
					env.c \
					env_utils.c) \
					# clean_env.c \
				$(addprefix signals/, \
					signals.c))

#============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#============================================================================: Make commands
all: libft message $(NAME)

#============================================================================: Main compile
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(OBJS) $(HEADERS) -lreadline $(AR) $(LIBFT)/libft.a -o $(NAME)
	@echo "$(GREEN)✅Done compiling $(NAME) $(RESET)"

#============================================================================: File compile
objs/%.o: srcs/%.c
	@$(MKDIR) objs
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#============================================================================: Build messages
message:
	@echo "$(BLUE)🔨Creating object folder$(RESET)"
	@echo "$(GREEN)🔨Compiling: $(MAGENTA)$(NAME)...$(RESET)"

#============================================================================: Remove object files
clean:
	@$(RM) objs/
	@$(MAKE) clean -C $(LIBFT)
	@echo "$(RED)🧹Removed object folders!$(RESET)"

#============================================================================: Remove object files and executables
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT)
	@echo "$(RED)🧹Removed $(NAME)!$(RESET)"

#============================================================================: Remove object files and executables then remake executables
re: fclean all

.PHONY: all run objs message clean fclean re