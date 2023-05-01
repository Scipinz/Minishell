# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kblok <kblok@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/16 20:46:21 by kblok         #+#    #+#                  #
#    Updated: 2023/05/01 12:31:32 by kblok         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#==============================================================================: Filename
NAME		= 	minishell

#==============================================================================: Source to object conversion 
OBJS		= 	$(SRCS:srcs/%.c=objs/%.o)

#==============================================================================: Compile variables
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
MAKEFLAGE	=	--no-print-directory
RM			=	rm -rf
AR			=	ar rcs
MKDIR		=	mkdir -p objs
HEADERS		= 	-I include -I $(LIBFT)

#============================================================================: Include files
LIBFT		= 	libft/

#============================================================================: Source files 
SRCS		=	$(addprefix src/, \
						main.c \
					$(addprefix lexer/, \
						lexer.c \
						check.c \
						quotes.c \
						print_list.c \
				))

#============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#============================================================================: Make commands
all: message $(NAME)

#============================================================================: Executable run command
run:
	@./$(NAME) $(ARGS)

#============================================================================: Main compile
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(OBJS) $(HEADERS) $(LIBFT)/libft.a -o $(NAME)
	@echo "$(GREEN)✅Done compiling $(NAME)$(RESET)"

#============================================================================: File compile
objs/%.o: srcs/%.c
	@$(MKDIR)
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
	@$(MAKE) clean -C libft
	@echo "$(RED)🧹Removed object folders!$(RESET)"

#============================================================================: Remove object files and executables
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft
	@echo "$(RED)🧹Removed $(NAME)!$(RESET)"

#============================================================================: Remove object files and executables then remake executables
re: fclean all

.PHONY: all run objs message clean fclean re