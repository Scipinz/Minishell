/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:01:32 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/20 16:12:55 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

//includes
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>

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
} t_token_type;

typedef struct s_lexer {
	t_token_type	type;
	int				len;
	int				pos;
	struct s_lexer	*next;
} t_lexer;

//functions
//lexer_check
int is_special(char c);
int symbol_length(char *input);
int lexer_length(char *input);

//quote_check
bool check_type(char *input, char *str);
int check_quotes(char *input);
int	quote_check(int end);

#endif