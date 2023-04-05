/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 20:24:00 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:15 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(const char *str, const char *str2)
{
	int	idx;

	idx = 0;
	while (str[idx] == str2[idx] && str[idx] != '\0' & str2[idx] != '\0')
	{
		idx++;
	}
	return ((unsigned char)str[idx] - (unsigned char)str2[idx]);
}
