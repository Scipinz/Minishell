/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:08:28 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/18 10:20:03 by quentinbeuk   ########   odam.nl         */
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

//=========================================================: Parse
void	ft_parse_tokes(char **tokens)
{
	int		i;
	int		j;
	
	static const char	*operators[10] = { 
		"<", ">", "<<", ">>", "&", "&&", "|", "||" 
	}; // ! Add to .h

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

//=========================================================: Read Line
int		ft_read_line()
{
	char			*input;
	char			**tokens;
	const char 		delimiter = ' '; // ! Add to .h

	while (1)
	{
		// ===== [ Read Input ] =====
		input = readline("$ ");
		if (ft_strcmp(input, "exit") == 0)
		{
			free (input);
			break ;
		}
		printf("Input string: %s\n", input);


		// ===== [ Tokens ] =====
		tokens = ft_split(input, delimiter);
		if (tokens == NULL)
			return (FAILURE); // ! Handle error
		ft_parse_tokes(tokens);


		// ===== [ Exit ] =====
		free (input);
		free (tokens);
	}
	return (SUCCESS);
}

//=========================================================: Main
int	main(int argc, char **argv, char **envp)
{
	if (ft_read_line() != SUCCESS)
		return (FAILURE); // ! Handle error
	
	return (SUCCESS);
}
