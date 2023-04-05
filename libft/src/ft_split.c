/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:34:01 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:59 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_free(char **str, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

static	char	*ft_wordcopy(char *str, char c)
{
	int		idx;
	int		len;
	char	*tmp;
	char	*pos;

	idx = 0;
	len = 0;
	pos = (char *)str;
	while (*str && *str != c)
	{
		str++;
		len++;
	}
	str = pos;
	tmp = malloc ((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	while (idx < len)
	{
		tmp[idx] = str[idx];
		idx++;
	}
	tmp[idx] = '\0';
	return (tmp);
}

static int	ft_array(char **rtnstr, char *str, char c)
{
	int	idx;

	idx = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		rtnstr[idx] = ft_wordcopy(str, c);
		if (!rtnstr[idx])
		{
			ft_free(rtnstr, idx);
			return (0);
		}
		idx++;
		while (*str != c && *str)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (1);
}

static	int	ft_wordcount(char const *str, char c)
{
	int	idx;
	int	wcount;

	idx = 0;
	wcount = 0;
	if (!str)
		return (0);
	while (str[idx])
	{
		if (str[idx] != c && str[idx])
			wcount++;
		while (str[idx] != c && str[idx + 1])
			idx++;
		idx++;
	}
	return (wcount);
}

char	**ft_split(char const *str, char c)
{
	int		endres;
	char	**res;
	int		array;

	if (!str)
		return (NULL);
	endres = ft_wordcount(str, c);
	res = malloc (sizeof(char *) * (endres + 1));
	if (!res)
		return (NULL);
	array = ft_array(res, (char *)str, c);
	if (!array)
		return (0);
	res[endres] = NULL;
	return (res);
}
