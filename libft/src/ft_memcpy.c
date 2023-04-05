/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:20:40 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:31 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	size_t	idx;

	idx = 0;
	if (!dst && !src)
		return (0);
	while (idx < num)
	{
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		idx++;
	}
	return (dst);
}

//COMMENTS:
//- size of the dst buffer should be greater than the number
//of bytes you want to copy.
//- the memory of src and dst buffer should not overlap.
//memcpy doesnt check the '\0', so carefully using with strings.
//- the behavior of memcpy can be undefined if you try
//to acces the dst and src buffer beyond their length
//- memcpy doesnt check the validity of dst and src buffer
