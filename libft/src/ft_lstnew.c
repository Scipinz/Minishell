/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:12:08 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:16 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = malloc (sizeof(t_list));
	if (!new_element)
		return (0);
	new_element -> content = content;
	new_element -> next = NULL;
	return (new_element);
}

// COMMENTS:

//	new_element -> input = content;
// input die je erin gooit wordt de content in de "void content"
// in de struct. dat wordt de new_element. Denk aan cat > cat.txt.

// new_element -> next = NULL;
// dit is vergelijkbaar aan '\0' in een array.

// t_list	*elem;
// elem is een pointer. als de notatie "elem -> next" dan wijst
// hij dus naar next.
// hence de "->" operator.

// return (1);
// 1 staat voor verkeerd.

// "echo $?" in shell
// output geven van je meest recente command.
