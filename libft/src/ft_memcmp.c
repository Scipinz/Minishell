/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:19:19 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:26 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *src, const void *src2, size_t num)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			idx;

	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)src2;
	idx = 0;
	while (idx < num)
	{
		if (ptr1[idx] != ptr2[idx])
		{
			return (ptr1[idx] - ptr2[idx]);
		}
		idx++;
	}
	return (0);
}
