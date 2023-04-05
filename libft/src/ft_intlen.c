/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 20:07:15 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/05 12:08:57 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		len++;
	}
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}
