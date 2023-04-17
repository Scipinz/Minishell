/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:08:28 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/18 01:53:18 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/* 
Tuesdays & Wednesdays

Finish by Friday:
	prompt
	lexer (expand)

Finish by tbd:
	parser (expand)
	executer 

Finish by tbd:
	builtins & signals 

*/

void	ft_read_line_example();

int	main(int argc, char **argv, char **envp)
{

	ft_read_line_example();
	return (3);
}

void	ft_parse_tokes(char **tokens)
{
	int		i;
	int		j;
	char	*operators[10] = { "<", ">", "<<", ">>", "&", "&&", "|", "||" };
	
	i = 0;
	while (tokens[i] != NULL)
	{
		j = 0;
		while (operators[j] != NULL)
		{
			if (ft_strcmp(tokens[i], operators[j]) == 0)
			{
				printf("Operator: %s\n", tokens[i]);
			}
			j++;
		}
		i++;
	}
}

void	ft_read_line_example()
{
	char			*input;
	char			**tokens;
	const char 		delimiter = ' '; // Add to .h

	while (1)
	{
		// ===== [ Read Input ] =====
		input = readline("$ ");
		if (ft_strcmp(input, "exit") == 0)
		{
			free(input);
			break ;
		}

		printf("Input string: %s\n", input);
		// add_history(input);


		// ===== [ Tokens ] =====
		tokens = ft_split(input, delimiter);
		ft_parse_tokes(tokens);


		// ===== [ Exit ] =====
		free (input);
		free (tokens);
	}
}
