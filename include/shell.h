/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:01:32 by kblok         #+#    #+#                 */
/*   Updated: 2023/06/12 16:14:48 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

//includes
# include "../libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <termios.h>
# include <errno.h>

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
	ARGUMENT,
	PROGRAM
}	t_token_type;

typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

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

typedef struct s_ast_node
{
	t_token_type		type;
	char				*value;
	struct s_ast_node	**children;
	int					num_children;
}	t_ast_node;

typedef struct s_cmd {
	int		fd_in;
	int		fd_out;
	char	*arg;

}	t_cmd;

typedef struct s_shell {
	t_lexer		*lexer;
	t_env		*env;
	size_t		cmd_len;
	t_cmd		*cmd;
	int			exit_code;
}	t_shell;

extern t_shell	g_shell;

// main
int			main(int argc, char **argv, char **envp);
int			clean_all(t_lexer *lexer, int exit, bool input);
char		*read_command_line(void);

//signals
void		init_signals(void);

//env
t_env		*parse_env(char **envp);
int			add_env(t_env **head, char *env);
int			fill_env(t_env *env, char *str);
t_env		*get_env(t_env *head, char *path);
void		sort_env(t_env **head, t_env *new);
t_env		*clear_list(t_env **head);
int			remove_node(t_env **head, char *key);

//lexer
t_lexer		*lexer(char *input);
int			is_special(char c);
int			symbol_length(char *input);
int			token_length(char *input);
void		print_list(t_lexer *head);
void		post_process(char *input, t_lexer *lexer);
bool		check_type(char *input, char *str);
int			check_quotes(char *input);
int			quote_check(int end);
bool		clear_lexer(t_lexer **head);

//parser
void		*ft_protec_malloc(void *ptr);
t_ast_node	*ft_new_ast_node(t_lexer **curr, char *input, int num_child);
t_ast_node	*parse_command(t_lexer **curr, char *input);
t_ast_node	*parse_pipe(t_ast_node *root, t_lexer **curr, char *input);
t_ast_node	*parser(t_lexer *head, char *input);
void		ft_print_ast(t_ast_node *node, int indent_level);

#endif