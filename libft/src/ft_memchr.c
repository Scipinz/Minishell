/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:12:55 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:23 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *src, int c, size_t num)
{
	unsigned char	*ptr;
	size_t			idx;

	ptr = (unsigned char *)src;
	idx = 0;
	if (!src)
		return (NULL);
	while (idx < num)
	{
		if (ptr[idx] == (unsigned char)c)
		{
			return ((unsigned char *)src + idx);
		}
		idx++;
	}
	return (NULL);
}

// COMMENTS:

// unsigned char *ptr has to be made to convert const void *s
// to an unsigned char *, which is initialized with p. this is
// because otherwise in the if statement s[i] would be a
// const void * and could not be compared to c which is an int.
// char has int value.
