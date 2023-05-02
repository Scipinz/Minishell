/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:01:32 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/02 14:42:09 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

//includes
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>

//defines
# define SPECIAL_CHARS "<>|"

//structs
typedef enum e_token_type {
	INFILE,
	OUTFILE,
	COMMAND,
	PIPE,
	HEREDOC,
	OUTFILE_APPEND,
	ARGUMENT
}	t_token_type;

typedef struct s_lexer {
	t_token_type	type;
	int				len;
	int				pos;
	int				adjacent;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_shell {
	t_lexer		*lexer;
	int			exit_code;
}	t_shell;

extern t_shell	g_shell;

//functions
//lexer
t_lexer	*lexer(char *input);
int		is_special(char c);
int		symbol_length(char *input);
int		lexer_length(char *input);
void	print_list(t_lexer *head);
void	post_process(char *input, t_lexer *lexer);
bool	check_type(char *input, char *str);
int		check_quotes(char *input);
int		quote_check(int end);
bool	clear_lexer(t_lexer **head);

#endif