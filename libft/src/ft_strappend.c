/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:38:49 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:02 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strappend(char const *str1, char const *str2)
{
	char	*str3;
	int		idx;
	int		idx2;

	idx = 0;
	idx2 = 0;
	if (!str1)
		return (ft_strdup(str2));
	str3 = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!str3)
		return (0);
	while (str1[idx] != '\0')
	{
		str3[idx] = str1[idx];
		idx++;
	}
	while (str2[idx2] != '\0')
	{
		str3[idx] = str2[idx2];
		idx++;
		idx2++;
	}
	str3[idx] = '\0';
	free((char *)str1);
	return (str3);
}
