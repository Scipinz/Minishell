/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 13:47:30 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/22 16:01:07 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* 
Environment

1. Add stuff when working on executer
*/

t_env	*get_env(t_env *head, char *path)
/* add this to parser if(!get_env(g_shell.env, "PATH"))return (NULL); */
{
	while (head)
	{
		if (ft_strlen(head->key) == ft_strlen(path) \
			&& ft_strncmp(head->key, path, ft_strlen(head->key)) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	fill_env(t_env *env, char *str)
{
	size_t	len[2];

	len[0] = 0;
	while (str[len[0]] != '=')
		len[0]++;
	while (str[len[0] + len[1] + 1])
		len[1]++;
	env->key = ft_calloc(sizeof(char), len[0] + 1);
	env->value = ft_calloc(sizeof(char), len[1] + 1);
	if (!env->key || !env->value)
	{
		free(env->value);
		free(env->key);
		free(env);
		return (0);
	}
	ft_memcpy(env->key, str, len[0]);
	ft_memcpy(env->value, &str[len[0] + 1], len[1]);
	return (1);
}

int	add_env(t_env **head, char *env)
{
	t_env	*new;

	new = ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (0);
	if (!fill_env(new, env))
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
