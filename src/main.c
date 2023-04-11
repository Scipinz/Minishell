/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:08:28 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/11 09:59:47 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// Tuesdays & Wednesdays

// Finish by Friday:
// prompt
// lexer (expand)

// Finish by tbd:
// parser (expand)
// executer 

// Finish by tbd:
// builtins & signals

void	ft_read_line_example();

int	main(int argc, char **argv, char **envp)
{

	ft_read_line_example();
	return (3);
}

void	ft_read_line_example()
{
	char	*input;
	char	*token;
	char	**tokens;

	while (1)
	{
		input = readline("$ ");

		if (ft_strcmp(input, "exit") == 0)
		{
			free(input);
			break ;
		}

		printf("Input: %s\n", input);
		// add_history(input);

		free (input);
	}
}
