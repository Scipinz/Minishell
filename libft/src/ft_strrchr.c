/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:42:58 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:49 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	idx;

	idx = ft_strlen(str);
	while (idx > 0)
	{
		if (str[idx] == (unsigned char)c)
		{
			return ((char *)str + idx);
		}
		idx--;
	}
	if (str[idx] == (unsigned char)c)
	{
		return ((char *)str + idx);
	}
	return (0);
}
