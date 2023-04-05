/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:42:30 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:42 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *str, const char *str2, size_t num)
{
	size_t	idx;

	idx = 0;
	while (idx < num)
	{
		if (str[idx] == '\0' || str2[idx] == '\0')
			return ((unsigned char)str[idx] - (unsigned char)str2[idx]);
		else if (str[idx] != str2[idx])
		{
			return ((unsigned char)str[idx] - (unsigned char)str2[idx]);
		}
		idx++;
	}
	return (0);
}

// COMMENTS:

// 	return ((unsigned char)str[idx] - (unsigned char)str2[idx]);
// \200 is an octal value of a weird char. so you have to cast
// it to an unsigned char otherwise it won't go above 127.
