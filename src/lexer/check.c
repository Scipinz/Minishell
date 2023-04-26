/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 17:02:08 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/20 16:07:57 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

bool check_type(char *input, char *str)
{
	int i;

	i = 0;
	while (input[i])
	{
		if ((input[i] == '\'' && input[i + 1] == '<') \
			|| (input[i] == '\"' && input[i + 1] == '<'))
			return (false);
		if ((input[i] == '\'' && input[i + 1] == '>') \
			|| (input[i] == '\"' && input[i + 1] == '>'))
			return (false);
		if ((input[i] == '\'' && input[i + 1] == '|') \
			|| (input[i] == '\"' && input[i + 1] == '|'))
			return (false);
		if ((input[i] == '\'' && ft_strncmp(str, ">>", 3) == 0) \
			|| (input[i] == '\"' && ft_strncmp(str, ">>", 3) == 0))
			return (false);
		if ((input[i] == '\'' && ft_strncmp(str, "<<", 3) == 0) \
			|| (input[i] == '\"' && ft_strncmp(str, "<<", 3) == 0))
			return (false);
		i++;
	}
	return (true);
}

int symbol_length(char *input)
{
    int i;

    i = 0;
    while (input[i] && !ft_isspace(input[i]))
    {
        if ((input[i] == '<' && input[i + 1] == '<') || \
            (input[i] == '>' && input[i + 1] == '>'))
            return (2);
        else
            return (1);
        i++;
    }
    return (0);
}

int lexer_length(char *input)
{
    int i;

    i = 0;
    while (input[i] && !ft_isspace(input[i]) && !is_special(input[i]))
        i++;
    return (i);
}

int is_special(char c)
{
    int i;

    i = 0;
    while (SPECIAL_CHARS[i] || c == '\"' || c == '\'')
    {
        if (c == SPECIAL_CHARS[i] || c == '\"' || c == '\'')
            return (1);
        i++;
    }
    return (0);
}
