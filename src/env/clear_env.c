/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_env.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:33:11 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/22 15:58:49 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_env	*clear_list(t_env **head)
{
	t_env	*temp_head;
	t_env	*temp;

	temp_head = *head;
	while (temp_head)
	{
		temp = temp_head->next;
		free(temp_head->value);
		free(temp_head->key);
		free(temp_head);
		temp_head = temp;
	}
	*head = NULL;
	return (NULL);
}

int	remove_node(t_env **head, char *key)
{
	t_env	*env;
	t_env	*temp;

	env = get_env(*head, key);
	if (!env)
		return (0);
	if (*head == env)
	{
		*head = (*head)->next;
		free(env->value);
		free(env->key);
		free(env);
		return (1);
	}
	temp = *head;
	while (temp->next != env)
		temp = temp->next;
	temp->next = temp->next->next;
	free(env->value);
	free(env->key);
	free(env);
	return (1);
}
