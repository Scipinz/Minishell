/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 16:27:21 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/18 13:07:10 by qbeukelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	add_list(t_token_type *type, char *input, int pos, int len)
{
	len = 0;
	pos = 0;


	new->len = len;
	new->pos = pos;
	new->type = type;
	new->next = next;
	free();
	return(0);
}

int	get_type(t_token_type *type, char *input, int pos, int len)
{
	char	*str;
	bool	expand;

	str = ft_substr(input, pos, len);
	if (!str)
		return (0);
	expand = ?(input, str);
	if (input[pos] == '<' && expand)
		*type = INFILE;
	else if (input[pos] == '>' && expand)
		*type = OUTFILE;
	else if (input[pos] == '|' && expand)
		*type = PIPE;
	else if (ft_strncmp(str, ">>", 3) == 0 && expand)
		*type = OUTFILE_APPEND;
	else if (ft_strncmp(str, "<<", 3) == 0 && expand)
		*type = HEREDOC;
	else
		*type = COMMAND;
	free(str);
	return (1);
}

static void	set_lexer(t_lexer **head, char *input, int len, int i)
{
	t_token_type	type;

	// if (add_token(head, input, i, len) == 0)
	// 	return ;

	if (add_list(head, input, i, len) == 0)
		return ;

	// Create Table
	
}

t_lexer	*tokens(t_lexer *head, char *input)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (input[i] == '\"' || input[i] == "\'")
		{
			i++;
			// len = quote_check(last_quote(&input[i]));
		}
		else if (is_special(input[i]) == 0)
			len = lexer_length(&input[i]);
		else
			len = symbol_length(&input[i]);
		if (len == 0)
			continue ;
		set_lexer(&head, input, len, i);
		i += len;
		len = 0;
	}
	return (head);
}

t_lexer	*lexer(char *input)
{
	t_lexer *head;

	head = NULL;
	head = tokens(head, input);
}
