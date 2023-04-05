/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:36:32 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:07 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (c == '\0')
		return (((char *)str) + ft_strlen(str));
	return (ft_memchr(str, c, ft_strlen(str)));
}

// COMMENTS:

// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == (unsigned char)c)
// 		{
// 			return ((char *)str + i);
// 		}
// 		i++;
// 	}
// 	if (str[i] == (unsigned char)c)
// 	{
// 		return ((char *)str + i);
// 	}
// 	return (0);
// }

// if statement na while loop is voor '\0' als je die zoekt.
