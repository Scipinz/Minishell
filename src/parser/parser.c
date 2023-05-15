#include "shell.h"

int	parser(char *input, t_lexer *lexer)
{
	if (!parse_cmds(input, lexer))
		return (0);
	if (!parsed_files(input, lexer))
		return (0);
	return (1);
}
