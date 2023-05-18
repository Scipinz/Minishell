/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:53:00 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/18 14:31:23 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	parser(char *input, t_lexer *lexer)
{
	if (!parse_cmds(input, lexer))
		return (0);
	if (!parsed_files(input, lexer))
		return (0);
	return (1);
}
