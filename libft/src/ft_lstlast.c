/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:11:55 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:10 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}

// COMMENTS:

// return (lst);
// return de pointer die naar NULL wijst.

// return (NULL);
// dit is daadwerkelijk NULL returnen
