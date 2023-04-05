/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:12:15 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:20 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstcount;

	lstcount = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		lstcount++;
	}
	return (lstcount);
}

// COMMENTS:

// lst = lst->next;
// is vergelijkbaar met i++; in een array
