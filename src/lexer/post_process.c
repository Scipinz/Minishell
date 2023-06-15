/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   post_process.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 13:00:24 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/18 14:08:37 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	find_adjacent(char *input, t_lexer *head)
{
	while (head && head->next)
	{
		if (!ft_strchr("<>| \t", input[head->pos + head->len]) \
				&& input[head->pos + head->len])
			head->adjacent = true;
		head = head->next;
	}
}

static int	set_arg(t_lexer *lexer)
// Emphasise check argument vs doc
{
	if (lexer->next == NULL)
		return (0);
	if (lexer->type != INFILE \
			&& lexer->type != OUTFILE \
			&& lexer->type != PIPE \
			&& lexer->type != HEREDOC \
			&& lexer->type != OUTFILE_APPEND)
	{
		if (lexer->next->type != INFILE \
			&& lexer->next->type != OUTFILE \
			&& lexer->next->type != PIPE \
			&& lexer->next->type != HEREDOC \
			&& lexer->next->type != OUTFILE_APPEND)
			lexer->next->type = ARGUMENT;
		return (1);
	}
	return (1);
}

static int	infile_output(char *input, t_lexer *lexer)
// Confusing In/Out/OutAppend/Her - Files
{
	char	*str;

	str = ft_substr(input, lexer->pos, lexer->len);
	if (!str)
		return (0);
	if (lexer->type == OUTFILE && input[lexer->pos] == '>' \
		&& lexer->next->type != INFILE \
		&& lexer->next->type != HEREDOC)
		lexer->next->type = OUTFILE;
	else if (lexer->type == INFILE && input[lexer->pos] == '<' \
		&& lexer->next->type != OUTFILE \
		&& lexer->next->type != OUTFILE_APPEND)
		lexer->next->type = INFILE;
	else if (lexer->type == OUTFILE_APPEND && ft_strncmp(str, ">>", 3) == 0 \
		&& lexer->next->type != INFILE \
		&& lexer->next->type != HEREDOC)
		lexer->next->type = OUTFILE_APPEND;
	else if (lexer->type == HEREDOC && ft_strncmp(str, "<<", 3) == 0 \
		&& lexer->next->type != OUTFILE \
		&& lexer->next->type != OUTFILE_APPEND)
		lexer->next->type = HEREDOC;
	free(input);
	return (1);
}

void	post_process(char *input, t_lexer *lexer)
{
	while (lexer != NULL)
	{
		if (lexer->next == NULL)
			return ;
		if (!infile_output(input, lexer))
			return ;
		if (!set_arg(lexer))
			return ;
		find_adjacent(input, lexer);
		lexer = lexer->next;
	}
}
