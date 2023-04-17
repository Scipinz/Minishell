/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:08:28 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/17 18:35:05 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clean_all(bool input)
{
	free (input);
	return (0);
}

static int	exec_shell(char *input)
{
	// lexer(input);
	free(input);
	return (1);
}

char	*read_command_line(void)
{
	char *input;

	input = readline("[pls work]: ");
	if (!input)
	{
		ft_putendl_fd("exit", 1);
		rl_clear_history();
		exit(clean_all(input));
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
		input = read_command_line();
		exec_shell(input);
	}
	printf("%s", input);
	return (0);
}

// Tuesdays & Wednesdays

// Finish by Friday:
// prompt
// lexer (expand)

// Finish by tbd:
// parser (expand)
// executer 

// Finish by tbd:
// builtins & signals
