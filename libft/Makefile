# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kblok <kblok@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/16 20:46:21 by kblok         #+#    #+#                  #
#    Updated: 2022/10/17 11:47:59 by kblok         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#==============================================================================: Filename
NAME	= 	libft.a

#==============================================================================: Source to object conversion 
OBJ		= 	$(SRCS:src/%.c=obj/%.o)

#==============================================================================: Compile variable
CC		= 	gcc
CFLAGS	= 	-Wall -Werror -Wextra -c
RM		=	rm -rf
AR		=	ar rcs
MKDIR	= 	mkdir -p obj

#==============================================================================: Source files 
include source.mk

#==============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

all: dirs message $(NAME)

run:
	@./$(NAME) $(ARGS)

#==============================================================================: Compile project
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)✅Done compiling $(NAME)$(RESET)"

dirs:
	@$(MKDIR)

message:
	@echo "$(BLUE)🔨Creating object folder$(RESET)"
	@echo "$(GREEN)🔨Compiling: $(MAGENTA)$(NAME)...$(RESET)"

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) -o $@ $< -I .
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#==============================================================================: Remove object files and folder
clean:
	@$(RM) obj/
	@echo "$(RED)🧹Cleaned object folders!$(RESET)"

#==============================================================================: Remove object files, folder and lib files/executables
fclean: clean
	@$(RM) $(NAME) *.out
	@echo "$(RED)🧹Cleaned $(NAME)!$(RESET)"

re: fclean all

.PHONY: all clean fclean re dirs message