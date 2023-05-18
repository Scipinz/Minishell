/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:52:43 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/18 14:16:41 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char **parse_arg(char *input, t_lexer *lexer, int arg_len)
{
	char	*str;
	char	**arg;
	int		i;

	i = 0;
	arg = ft_calloc(arg_len + 1, sizeof(char *));
	if (!arg)
		return (NULL);
	while (lexer && arg_len > i)
	{
		while (lexer->next && (lexer->type != ARGUMENT && \
			lexer->type != COMMAND))
			lexer->next;
		str = is_adjacent(input, lexer);
		if (!str)
			return (NULL);
		if (lexer->adjacent)
			lexer->next;
		arg[i] = str;
		i++;
		lexer = lexer->next;
	}
	arg[i] = 0;
	return (arg);
}

static size_t	arg_count(t_lexer *lexer)
{
	int i;

	i = 0;
	while (lexer && lexer->type == COMMAND)
	{
		if ((lexer->type == ARGUMENT || lexer->type == COMMAND))
			i++;
		lexer = lexer->next;
	}
	return (i);
}

static size_t	cmd_count(t_lexer *lexer)
{
	int	i;
	
	i = 0;
	if (!lexer)
		return (0);
	while (lexer)
	{
		if (lexer->type == COMMAND)
			i++;
		lexer = lexer->next;
	}
	return (i);
}

int	parse_cmds(char *input, t_lexer *lexer)
{
	int		arg_len;
	size_t	i;
	
	g_shell.cmd_len = cmd_count(lexer);
	g_shell.cmd = ft_calloc(sizeof(t_cmd), g_shell.cmd_len);
	if (!g_shell.cmd)
		return (0);
	i = 0;
	while (lexer)
	{
		g_shell.cmd[i].fd_in = STDIN_FILENO;
		g_shell.cmd[i].fd_out = STDOUT_FILENO;
		arg_len = arg_count(lexer);
		if (arg_len)
		{
			g_shell.cmd[i].arg = parse_arg(input, lexer, arg_len);
			if (!g_shell.cmd[i].arg)
				return (0);
		}
		while (lexer && lexer->type && lexer->next != PIPE)
			lexer = lexer->next;
		lexer = lexer->next;
		i++;
	}
	return (1);
}
