/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 12:26:03 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:49 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putnbr_base(size_t num, char const *base_format)
{
	size_t	idx;
	size_t	base;

	base = ft_strlen(base_format);
	idx = 0;
	if (num < base)
		idx += ft_putchar(base_format[num % base]);
	else
	{
		idx += ft_putnbr_base(num / base, base_format);
		idx += ft_putnbr_base(num % base, base_format);
	}
	return (idx);
}
