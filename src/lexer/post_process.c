/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   post_process.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 13:00:24 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/01 14:55:04 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	set_arg(t_lexer *lexer, t_token_type )
{
	if (lexer->next == NULL)
		return (0);
	if (lexer->type != t_token_type[0])
	{
		if (lexer->next->type != )
			lexer->next->type = ARGUMENT;
		return (1);
	}
	return (1);
}

static void	find_adjacent(char *input, t_lexer *head)
{
	while (head && head->next)
	{
		if (!ft_strchr("<>| \t", input[head->pos, head->len]) \
				&& input[head->pos + head->len])
			head->adjacent = true;
		head = head->next;
	}
}

bool	post_process(char *input, t_lexer *lexer)
{
	if (lexer->next == NULL)
		return ;
	if (!set_arg(lexer));
		return ;
	find_adjacent(input, lexer);
	return (true);
}
