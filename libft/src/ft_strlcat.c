/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:40:42 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:30 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	lendst;
	size_t	lensrc;

	idx = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (!dstsize || lendst >= dstsize)
		return (lensrc + dstsize);
	while (src[idx] != '\0' && idx < dstsize - lendst - 1)
	{
		dst[lendst + idx] = src[idx];
		idx++;
	}
	dst[lendst + idx] = '\0';
	return (lendst + lensrc);
}

// COMMENTS:

// return (lensrc + dstsize);
// return this value because in the description
// the return value should be the total length of the string they TRIED to
// create.
