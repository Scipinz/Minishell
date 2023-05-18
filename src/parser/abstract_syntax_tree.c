/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   abstract_syntax_tree.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 14:26:58 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/18 14:49:09 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Abstract Syntax Tree


                         __ PIPELINE__
                     ___/              \____
                    /                       \
            COMMAND                    __ PIPELINE _
          /        \                  /             \
    ARGUMENTS   REDIRECTIONS      COMMAND         _ COMMAND __
        |          |     |           |           /            \
       cat        <<     >       ARGUMENTS    ARGUMENTS   REDIRECTIONS
                   |     |         |   |      |   |   |        |
                 "..."  file      wc  -c      tr  -d " "       >
                                                               |
                                                             file2


NEEDS: Environment Path
NORM
Seperate functions */

t_ast_node *ft_parse(t_lexer *head) 
{
    t_ast_node  *root = ft_calloc(1, sizeof(t_ast_node));

    root->type = "program";
    root->children = ft_calloc(1, sizeof(t_ast_node *));
    root->num_children = 0;

    t_lexer *curr = head;

    while (curr) 
    {
        // Construct nodes for each type of token
        if (curr->type == COMMAND) 
        {
            t_ast_node *cmd = ft_calloc(1, sizeof(t_ast_node));
            cmd->type = "command";
            cmd->value = curr->value_temp;
            cmd->children = ft_calloc(1, sizeof(t_ast_node *));
            cmd->num_children = 0;

            // Add arguments as children of the command node
            curr = curr->next;
            while (curr && curr->type == ARGUMENT)
            {
                t_ast_node *arg = ft_calloc(1, sizeof(t_ast_node));
                arg->type = "argument";
                arg->value = curr->value_temp;
                arg->children = NULL;
                arg->num_children = 0;
                // ! First free than ft_calloc
                cmd->children = realloc(cmd->children, (cmd->num_children + 1) * sizeof(t_ast_node *)); // ! Dont use realloc
                cmd->children[cmd->num_children++] = arg;
                curr = curr->next;
            }

            // Add the command node as a child of the root
            root->children = realloc(root->children, (root->num_children + 1) * sizeof(t_ast_node *));
            root->children[root->num_children++] = cmd;
        } 
        else if (curr->type == PIPE)
        {
            // Construct a node for the pipe operator
            t_ast_node *pipe_op = ft_calloc(1, sizeof(t_ast_node));
            pipe_op->type = "pipe";
            pipe_op->value = "|";
            pipe_op->children = ft_calloc(2, sizeof(t_ast_node *));
            pipe_op->num_children = 2;

            // Add the left and right commands as children of the pipe node
            t_ast_node *left_cmd = root->children[root->num_children - 1];
            t_ast_node *right_cmd = ft_calloc(1, sizeof(t_ast_node));
            right_cmd->type = "command";
            right_cmd->value = curr->next->value_temp;
            right_cmd->children = ft_calloc(1, sizeof(t_ast_node *));
            right_cmd->num_children = 0;
            curr = curr->next;

            while (curr && curr->type == ARGUMENT) 
            {
                t_ast_node *arg = ft_calloc(1, sizeof(t_ast_node));
                arg->type = "argument";
                arg->value = curr->value_temp;
                arg->children = NULL;
                arg->num_children = 0;
                right_cmd->children = realloc(right_cmd->children, (right_cmd->num_children + 1) * sizeof(t_ast_node *));
                right_cmd->children[right_cmd->num_children++] = arg;
                curr = curr->next;
            }
            pipe_op->children[0] = left_cmd;
            pipe_op->children[1] = right_cmd;

            // Replace the left command with the pipe node as a child of the root
            root->children[root->num_children - 1] = pipe_op;
        }
        else 
        {
            // Handle unexpected tokens
            printf("Error: unexpected token %s\n", curr->value_temp);
            exit(1);
        }
    }
    return (root);
}


// OUTPUT: 
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
