/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:43:16 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:52 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int	ft_left(char const *str, char const *set)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!ft_strchr(set, str[idx]))
			break ;
		idx++;
	}
	return (idx);
}

static	int	ft_right(char const *str, char const *set)
{
	int	idx;

	idx = ft_strlen(str);
	while (idx > 0)
	{
		if (!ft_strchr(set, str[idx - 1]))
			break ;
		idx--;
	}
	return (idx);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int	left;
	int	right;

	if (!str)
		return (0);
	left = ft_left(str, set);
	right = ft_right(str, set);
	if (left > right)
		return (ft_strdup(""));
	return (ft_substr(str, left, (right - left)));
}

// COMMENTS:
// if (ft_strchr(set, str[idx]) == 0) "== 0 is gelijk aan false"
// 	idx = ft_strlen(str); hier eindigt het op de \0 daarom in je if idx - 1
