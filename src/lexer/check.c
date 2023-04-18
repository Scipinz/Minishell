/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 17:02:08 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/18 14:33:45 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int is_special(char c)
{
    int i;

    i = 0;
    while (SPECIAL_CHARS[i] || c == '\"' || c == "\'")
    {
        if (c == SPECIAL_CHARS[i] || c == '\"' || c == '\'')
            return (1);
        i++;
    }
    return (0);
}

int symbol_length(char *input)
{
    int i;

    i = 0;
    while (input[i] && !ft_isspace(input[i]))
    {
        if ((input[i] == '<' && input[i + 1] == '<') || \
            (input[i] == '>' && input[i + 1] == '>'))
            return (2);
        else
            return (1);
        i++;
    }
    return (0);
}

int lexer_length(char *input)
{
    int i;

    i = 0;
    while (input[i] && !ft_isspace(input[i]) && !is_special(input[i]))
        i++;
    return (i);
}
