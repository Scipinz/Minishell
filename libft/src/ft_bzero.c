/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 18:21:25 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:09:45 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *str, size_t num)
{
	ft_memset(str, '\0', num);
}

// COMMENTS:

// whole function is basically:
// ft_memset(s, '\0', n);

// OR:

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*p;
// 	size_t			i;

// 	p = s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		p[i] = '\0';
// 		i++;
// 	}
// }