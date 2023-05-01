/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_lexer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 12:36:13 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/01 12:36:29 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

bool	clear_lexer(t_lexer **head)
{
	t_lexer	*next;
	t_lexer	*temp;

	temp = *head;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp->next;
	}
	*head = NULL;
	return (false);
}
