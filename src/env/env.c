/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 13:47:30 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/18 14:15:46 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* 
Environment

1. Get env path "setup"
2. Send env to parser -> PATH - Variables (Seperate)
*/

int env_str(t_env *env, char *str)
{

}

int	add_env(t_env **head, char *env)
{
	t_env	*new;

	new = ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (0);
	if (!add_str_env(new, env))
		return (0);
	if (*head == NULL)
	{
		*head = new;
		return (1);
	}
	sort_env(head, new);
	return (1);
}

t_env	*parse_env(char **envp)
{
	t_env	*head;

	head = NULL;
	if (!envp)
		return (NULL);
	while (*envp)
	{
		if (!add_env(&head, *envp))
			return (clear_list(&head));
		envp++;
	}
	return (head);
}
