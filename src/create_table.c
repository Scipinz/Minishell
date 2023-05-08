/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_table.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 10:47:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/05/08 13:05:44 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* 

Abstract Syntax Tree


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


 */


t_ast_node *ft_parse(t_lexer *head) 
{
    t_ast_node  *root = calloc(1, sizeof(t_ast_node));

    root->type = "program";
    root->children = calloc(1, sizeof(t_ast_node *));
    root->num_children = 0;

    t_lexer *curr = head;

    while (curr) 
    {
        // Construct nodes for each type of token
        if (curr->type == COMMAND) 
        {
            t_ast_node *cmd = calloc(1, sizeof(t_ast_node));
            cmd->type = "command";
            cmd->value = curr->value_temp;
            cmd->children = calloc(1, sizeof(t_ast_node *));
            cmd->num_children = 0;

            // Add arguments as children of the command node
            curr = curr->next;
            while (curr && curr->type == ARGUMENT)
            {
                t_ast_node *arg = calloc(1, sizeof(t_ast_node));
                arg->type = "argument";
                arg->value = curr->value_temp;
                arg->children = NULL;
                arg->num_children = 0;
                cmd->children = realloc(cmd->children, (cmd->num_children + 1) * sizeof(t_ast_node *));
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
            t_ast_node *pipe_op = calloc(1, sizeof(t_ast_node));
            pipe_op->type = "pipe";
            pipe_op->value = "|";
            pipe_op->children = calloc(2, sizeof(t_ast_node *));
            pipe_op->num_children = 2;

            // Add the left and right commands as children of the pipe node
            t_ast_node *left_cmd = root->children[root->num_children - 1];
            t_ast_node *right_cmd = calloc(1, sizeof(t_ast_node));
            right_cmd->type = "command";
            right_cmd->value = curr->next->value_temp;
            right_cmd->children = calloc(1, sizeof(t_ast_node *));
            right_cmd->num_children = 0;
            curr = curr->next;

            while (curr && curr->type == ARGUMENT) 
            {
                t_ast_node *arg = calloc(1, sizeof(t_ast_node));
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




// t_command	*parse_command(t_lexer **head)
// {
//     t_command	*command;
//     t_lexer		*token;

//     command = ft_calloc(sizeof(t_command), 1);
//     while (*head && (*head)->type == ARGUMENT)
//     {
//         token = *head;
//         *head = (*head)->next;
//         command->arg_count++;
//         command->arguments = ft_realloc(command->arguments, sizeof(char*) * command->arg_count);
//         command->arguments[command->arg_count - 1] = ft_substr(token->value, 0, token->len);
//         free(token);
//     }
//     if (*head && (*head)->type == PIPE)
//     {
//         *head = (*head)->next;
//         command->command = parse_command(head);
//     }
//     return (command);
// }