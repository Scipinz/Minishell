/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:08:28 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/22 16:12:09 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

t_shell	g_shell;

int	clean_all(t_lexer *lexer, int exit, bool input)
{
	clear_list(&g_shell.env);
	clear_lexer(&lexer);
	lexer = NULL;
	return (exit);
}

static int	exec_shell(char *input)
{
	g_shell.lexer = lexer(input);
	if (!g_shell.lexer)
	{
		clean_all(g_shell.lexer, 0, false);
		free(input);
		return (1);
	}
	// if (!parser(input, g_shell.lexer))
	// {
	// 	free(input);
	// 	exit(clean_all(g_shell.lexer, EXIT_FAILURE, true));
	// }
	lexer(input);
	clean_all(g_shell.lexer, 0, false);
	free(input);
	return (1);
}

char	*read_command_line(void)
{
	char	*input;

	input = readline("[minishell]: ");
	if (!input)
	{
		ft_putendl_fd("exit", 1);
		rl_clear_history();
		exit(clean_all(NULL, g_shell.exit_code, true));
	}
	if (input && *input)
		add_history(input);
	return (input);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	while (1)
	{
		init_signals();
		input = read_command_line();
		exec_shell(input);
	}
	return (0);
}

/*
kblok work: Friday & Saturday

lexer -> parser -> expander -> executor

kblok
	lexer
	envp
	free
	? norminette

qbeukelm
	? table of commands
	? seg fault
	? separate functions
 */
