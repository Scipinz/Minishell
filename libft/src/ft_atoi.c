/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 18:21:12 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:09:17 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atoi(const char *str)
{
	int		idx;
	long	res;
	long	sign;

	idx = 0;
	res = 0;
	sign = 1;
	while (ft_isspace((str[idx])))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (ft_isdigit(str[idx]))
	{
		res = res * 10 + str[idx] - '0';
		idx++;
	}
	return (sign * res);
}

// COMMENTS:

// res = res * 10 + str[idx] - '0';
// - '0' to make char to int
// res * 10 to go to the following place in the number
// that will be converted to an int.