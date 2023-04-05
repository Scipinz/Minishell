/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:23:58 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:37 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *src, int c, size_t num)
{
	unsigned char	*ptr;
	size_t			idx;

	ptr = src;
	idx = 0;
	while (idx < num)
	{
		ptr[idx] = c;
		idx++;
	}
	return (src);
}
