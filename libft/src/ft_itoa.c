/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:07:23 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/05 12:09:22 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int	ft_sign(int num)
{
	if (num > 0)
		return (num);
	else
		return (-num);
}

static	char	*ft_edgecase(int num)
{
	char	*res;

	res = 0;
	if (num == -2147483648)
		res = ft_strdup("-2147483648");
	if (num == 0)
		res = ft_strdup("0");
	return (res);
}

char	*ft_itoa(int num)
{
	char	*res;
	int		len;

	len = ft_intlen(num);
	if (num == -2147483648 || num == 0)
		return (ft_edgecase(num));
	if (num < 0)
		len++;
	res = malloc ((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num < 0)
		res[0] = '-';
	num = ft_sign(num);
	while (num > 0)
	{
		len--;
		res[len] = num % 10 + '0';
		num = num / 10;
	}
	return (res);
}

// COMMENTS:

// char	*ft_itoa(int n)
// {
// 	char	*res;
// 	int		len;

// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	if (n == 0)
// 		return (ft_strdup("0"));
// 	len = ft_intlen(n);
// 	if (n < 0) //increment len for the '-' that will be added
// 		len++;
// 	res = malloc ((len + 1) * sizeof(char));
// 	if (!res)
// 		return (NULL);
// 	res[len] = '\0; 
// res[len] is at the end of res that is why you add null term
// 	if (n < 0)
// 		res[0] = '-';
// 	n = ft_sign(n);
// 	while (n > 0)
// 	{
// 		len--; 
// because len is at the end '\0' we want to go 1 position back
// 		res[len] = n % 10 + '0';
// 		n = n / 10;
// 	}
// 	return (res);
// }
