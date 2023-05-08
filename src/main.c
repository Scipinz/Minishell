/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:08:28 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/08 13:13:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

t_lexer    *ft_temp_node(t_lexer *lexer_root, int token_type, char *value)
{
    int         i;
    t_lexer     *current;
    t_lexer     *root;
    t_lexer     *new;

    current = lexer_root;
    root = current;
    i = 0;

    while (current)
    {
        if (current->next == NULL)
        {
            new = malloc(sizeof(t_lexer));
            new->value_temp = value;
            new->type = token_type;
            new->pos = i + 1;
            new->len = i + 1;
            new->adjacent = 0;
            current->next = new;
            break ;
        }
        i++;
        current = current->next;
    }
    return (root);
}

void print_ast_node(t_ast_node *node, int depth)
{
    if (!node)
    {
        return;
    }
    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }
    printf("%s", node->type);
    if (node->value)
    {
        printf(": %s", node->value);
    }
    printf("\n");
    for (int i = 0; i < node->num_children; i++)
    {
        print_ast_node(node->children[i], depth + 1);
    }
}



int	main(void)
{
    t_lexer     *lex_head;
    t_lexer     *lex_node;
    t_lexer     *lex_root;

    // Create new node
    lex_head = malloc(sizeof(t_lexer));
    lex_head->value_temp = "ls -l";
    lex_head->type = COMMAND;
    lex_head->len = 1;
    lex_head->pos = 0;
    lex_head->next = NULL;

    lex_root = lex_head;

    // ls -l | grep Makefile
    lex_root = ft_temp_node(lex_root, PIPE, "|");
    lex_root = ft_temp_node(lex_root, COMMAND, "grep");
    lex_root = ft_temp_node(lex_root, ARGUMENT, "Makefile");

    // print
    // while (lex_root)
    // {
    //     printf("Command: %s, \t\t Type: %d, \t\t Position: %d\n", lex_root->value_temp, lex_root->type, lex_root->pos);
    //     lex_root = lex_root->next;
    // }

    t_ast_node  *ast_root;
    ast_root = ft_parse(lex_root);
    print_ast_node(ast_root, 0);
/* 
    program
  command: ls
    argument: -l
    argument: /
  pipe: |
    command: grep
      argument: foo
    command: wc
      argument: -l
 */
}
