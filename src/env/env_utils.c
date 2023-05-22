/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 13:57:37 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/22 15:56:06 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sort_env(t_env **head, t_env *new)
{
	t_env	*temp;

	if (get_env(g_shell.env, new->key))
		remove_node(&g_shell.env, new->key);
	if (ft_strcmp((*head)->key, new->key) > 0)
	{
		new->next = (*head);
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next && ft_strcmp(temp->next->key, new->key) < 0)
		temp = temp->next;
	new->next = temp->next;
	temp->next = new;
}
