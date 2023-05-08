/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:01:32 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/08 10:51:30 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/libft.h"

//=========================================================: Enum
typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

//=========================================================: CMD & Args
// Describe a simple command and arguments
typedef struct s_command
{
    char    command;
    int     arg_count;
    char    **arguments;
    char    **options;
} t_command;


//=========================================================: CMD Table
// Describes a complete command with the multiple pipes 
// if any and input/output redirection if any.
typedef struct s_table
{
    char        *in_file;
    char        *out_file;
    char        *err_file;
    int         cmd_count;
    t_command   *command;
} t_table;



//=========================================================: Lexer
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

typedef struct s_env {
	char			*value;
	char			*key;
	struct s_env	*next;
}	t_env;

typedef struct s_shell {
	t_lexer		*lexer;
	t_env		*env;
	int			exit_code;
}	t_shell;

extern t_shell	g_shell;




#endif
