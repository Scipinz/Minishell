/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 16:25:29 by kblok         #+#    #+#                 */
/*   Updated: 2022/03/09 16:21:59 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_cases(const char format, va_list *arg, int *idx)
{
	if (format == 'c')
		*idx += ft_putchar(va_arg(*arg, int));
	else if (format == 's')
		*idx += ft_putstr(va_arg(*arg, char *));
	else if (format == 'd' || format == 'i')
		*idx += ft_putnbr(va_arg(*arg, int));
	else if (format == 'p')
	{
		*idx += ft_putstr("0x");
		*idx += ft_putnbr_base(va_arg(*arg, size_t), HEX_LOWER);
	}
	else if (format == 'u')
		*idx += ft_putnbr_base(va_arg(*arg, unsigned int), DECIMAL);
	else if (format == 'x')
		*idx += ft_putnbr_base(va_arg(*arg, unsigned int), HEX_LOWER);
	else if (format == 'X')
		*idx += ft_putnbr_base(va_arg(*arg, unsigned int), HEX_UPPER);
	else if (format == '%')
		*idx += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		idx;

	idx = 0;
	va_start (arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			ft_cases(*format, &arg, &idx);
		}
		else
		{
			write(1, (char *)format, 1);
			idx++;
		}
		format++;
	}
	va_end (arg);
	return (idx);
}
