/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:38:35 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/05 12:09:52 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	int	idx;

	idx = 0;
	if (!str)
		return ;
	while (str[idx])
	{
		(*f)(idx, &str[idx]);
		idx++;
	}
}
