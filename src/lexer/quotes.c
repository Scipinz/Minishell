/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 16:51:07 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/18 18:42:03 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"



int	last_quote(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '\"')
		{
			j = i;
			break ;
		}
		i++;
	}
	return (j);
}

int	quote_check(int end)
{
	int	len;

	len = 0;
	if (end == 0)
		return (0);
	while (len < end)
		len++;
	return (len);
}
