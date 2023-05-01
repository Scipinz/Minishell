/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 12:27:00 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/01 12:35:47 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	print_list(t_lexer *head)
{
	while (head != NULL)
	{
		printf("position: %d\t length: %d\t type: %d\n", head->pos, \
				head->len, head->type);
		head = head->next;
	}
}
