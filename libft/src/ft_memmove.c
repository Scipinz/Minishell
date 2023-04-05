/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:21:45 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:33 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (num > 0)
		{
			((unsigned char *)dst)[num - 1] = ((unsigned char *)src)[num - 1];
			num--;
		}
	}
	else
		ft_memcpy(dst, src, num);
	return (dst);
}
