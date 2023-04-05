/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:38:22 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:21 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		idx;

	ptr = malloc((ft_strlen(str) + 1) * sizeof(char));
	idx = 0;
	if (!ptr)
		return (0);
	while (str[idx] != '\0')
	{
		ptr[idx] = str[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

// COMMENTS:

// OPTION 2 with ft_memcpy:

// char	*ft_strdup(const char *str)
// {
// 	size_t	length;
// 	char	*sCopy;
// 	int		counter;

// 	length = ft_strlen(str) + 1;
// 	sCopy = malloc(length);
// 	counter = 0;
// 	if (sCopy == 0)
// 	{
// 		return (0);
// 	}
// 	ft_memcpy(sCopy, str, length);
// 	return (sCopy);
// }
