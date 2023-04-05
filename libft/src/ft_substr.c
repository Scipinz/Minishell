/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:44:27 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:56 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t num)
{
	char	*substring;
	size_t	strlen;

	strlen = ft_strlen(str);
	if (str == '\0')
		return (0);
	if (strlen < start)
		return (ft_strdup(""));
	if (strlen < num)
		return (ft_strdup(start + str));
	if (ft_strlen(str) - start < num)
		num = ft_strlen(str) - start;
	substring = (char *)ft_calloc(num + 1, sizeof(char));
	if (!substring)
		return (0);
	if (start >= strlen)
		return (substring);
	ft_strlcpy(substring, str + start, num + 1);
	return (substring);
}

// COMMENTS:

// ft_strlcpy(substring, str + start, num + 1);
// strlcpy purely for src --> dest.
