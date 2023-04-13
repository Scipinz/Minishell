/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:08:28 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/05 13:24:09 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clean(bool exit)
{
	free (input);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	while (1)
	{
		input = read_line_command();
	}
	printf("%s", input);
	clean(true);
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
