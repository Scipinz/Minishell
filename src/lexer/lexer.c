/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 16:27:21 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/20 16:10:10 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	add_token(t_lexer **head, int len, int pos, t_token_type type)
{
	t_lexer	*new;
	t_lexer	*empty;

	new = ft_calloc(sizeof(t_lexer), 1);
	if (!new)
		return (0);
	new->len = len;
	new->pos = pos;
	new->type = type;
	new->next = NULL;
	if (!head)
		*head = new;
	else
	{
		empty = *head;
		while (empty->next)
			empty = empty->next;
		empty->next = new;
	}
	return (1);
}

int	set_type(t_token_type *type, char *input, int pos, int len)
{
	char	*str;
	bool	expand;

	str = ft_substr(input, pos, len);
	if (!str)
		return (0);
	expand = check_type(input, str);
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

	if (set_type(&type, input, i, len) == 0)
		return ;
	if (add_token(head, len, i, type) == 0)
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
		if (input[i] == '\"' || input[i] == '\'')
		{
			i++;
			len = quote_check(check_quotes(&input[i]));
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
	return (head);
}
