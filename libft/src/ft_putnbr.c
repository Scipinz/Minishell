/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:32:05 by kblok         #+#    #+#                 */
/*   Updated: 2021/11/16 19:32:06 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int num)
{
	if (num == -2147483648)
		ft_putstr("-2147483648");
	else if (num < 0)
	{
		ft_putchar('-');
		ft_putnbr(-num);
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
	return (ft_intlen(num));
}
