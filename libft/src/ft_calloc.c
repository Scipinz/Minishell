/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 18:20:55 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:09:59 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	total;

	total = count * size;
	if (!total)
		return (NULL);
	res = malloc(total);
	if (!res)
		return (NULL);
	ft_bzero(res, total);
	return (res);
}

// COMMENTS:

// count = how many blocks on the memory (size of array)
// size = how big the size of the memory in 1 block (size of each element)
// returns: succes --> address of memory block | failure --> null pointer

// OresTION WITHOUT ft_bzero():

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*res;
// 	size_t		idx;

// 	idx = 0;
// 	res = malloc(count * size);
// 	if (res == 0)
// 	{
// 		return (0);
// 	}
// 	while (idx < (count * size))
// 	{
// 		res[idx] = 0;
// 		idx++;
// 	}
// 	return (res);
// }
