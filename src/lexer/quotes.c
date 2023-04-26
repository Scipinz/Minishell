/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 16:51:07 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/20 16:09:35 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int    check_quotes(char *input)
{
    int    i;

    i = 0;
    while ((input[i] != '\'' && input[i] != '\"') && input[i])
        i++;
    return i;
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
