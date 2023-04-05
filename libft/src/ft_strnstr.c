/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:42:25 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:12:44 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t num)
{
	size_t	idx;
	size_t	idx2;

	idx = 0;
	if (!needle || !*needle)
		return ((char *)haystack);
	while (idx < num && haystack[idx] != '\0')
	{
		idx2 = 0;
		while (haystack[idx + idx2] == needle[idx2] && idx + idx2 < num)
		{
			idx2++;
			if (needle[idx2] == '\0')
				return (((char *)haystack) + idx);
		}
		idx2 = 0;
		idx++;
	}
	return (0);
}

// COMMENTS:

	// idx2 = 0;
	// // Basicaly strcmp, consider making the fucntion strcmp
	// while (haystack[idx + idx2] == needle[idx2] && idx + idx2 < num)
	// {
	// 	idx2++;
	// 	if (needle[idx2] == '\0')
	// 		return (((char *)haystack) + idx);
	// }
	// idx2 = 0;
	// idx++;

// COMMENTS:
// if (!*needle) //same as (needle[idx] == '\0')
