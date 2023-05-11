#include "shell.h"

char *add_adjacent(char *input, t_lexer *lexer)
{
    
}

char *is_adjacent(char *input, t_lexer *lexer)
{
    char *temp;

    if (lexer->adjacent)
        return (add_adjacent(input, lexer))
    temp = ft_substr(input, lexer->pos, lexer->len);
    if (!temp)
        return (NULL);
    return (temp);
}
