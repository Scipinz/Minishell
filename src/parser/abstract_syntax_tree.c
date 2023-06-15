/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   abstract_syntax_tree.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 14:26:58 by kblok         #+#    #+#                 */
/*   Updated: 2023/06/07 16:04:02 by kblok         ########   odam.nl         */
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
NEEDS: Environment Path
NORM
Seperate functions
*/
// ===================================================================: Protec
void	*ft_protec_malloc(void *ptr)
{
	if (ptr == NULL)
	{
		ft_printf("ERROR: Memory allocation\n");
		// return(ft_clean_exit(EXIT_CODE));
	}
	return (ptr);
}
// ===================================================================: New Node
t_ast_node	*ft_new_ast_node(t_lexer **curr, char *input, int num_child)
{
	t_ast_node	*cmd;

	cmd = ft_protec_malloc(ft_calloc(1, sizeof(t_ast_node)));
	cmd->num_children = num_child;
	// Check if there is a node
	if (curr)
	{
		cmd->type = (*curr)->type;
		cmd->value = ft_substr(input, (*curr)->pos, (*curr)->len);
	}
	else
	{
		cmd->type = PROGRAM;
		cmd->value = "program";
	}
	// Children
	if (num_child == 0)
		cmd->children = ft_calloc(1, sizeof(t_ast_node *));
	else
		cmd->children = ft_calloc(num_child, sizeof(t_ast_node *));
	return (cmd);
}
// ===================================================================: CMD
t_ast_node	*parse_command(t_lexer **curr, char *input)
{
	t_ast_node	*cmd;
	t_ast_node	*arg;

	cmd = ft_new_ast_node(curr, input, 0);
	// Add arguments as children of the command node
	*curr = (*curr)->next;
	while (*curr && (*curr)->type == ARGUMENT)
	{
		arg = ft_new_ast_node(curr, input, 0);
		cmd->children = realloc(cmd->children, \
			(cmd->num_children + 1) * sizeof(t_ast_node *));
		cmd->children[cmd->num_children++] = arg;
		*curr = (*curr)->next;
	}
	return (cmd);
}
// ===================================================================: Pipe
t_ast_node	*parse_pipe(t_ast_node *root, t_lexer **curr, char *input)
{
	t_ast_node	*pipe_op;
	t_ast_node	*left_cmd;
	t_ast_node	*right_cmd;
	t_ast_node	*arg;
	// Construct a node for the pipe operator
	pipe_op = ft_new_ast_node(curr, input, 2);
	// Add the left and right commands as children of the pipe node
	left_cmd = root->children[root->num_children - 1];
	right_cmd = ft_new_ast_node(curr, input, 0);
	*curr = (*curr)->next;
	while (*curr && (*curr)->type != PIPE)
	{
		arg = ft_new_ast_node(curr, input, 0);
		right_cmd->children = realloc(right_cmd->children, \
			(right_cmd->num_children + 1) * sizeof(t_ast_node *));
		right_cmd->children[right_cmd->num_children++] = arg;
		*curr = (*curr)->next;
	}
	pipe_op->children[0] = left_cmd;
	pipe_op->children[1] = right_cmd;
	// Replace the left command with the pipe node as a child of the root
	root->children[root->num_children - 1] = pipe_op;

	return root;
}
// ===================================================================: Parse
t_ast_node	*parser(t_lexer *head, char *input)
{
	t_ast_node	*root;
	t_lexer		*curr;
	
	root = ft_new_ast_node(0, input, 0);
	curr = head;
	while (curr)
	{
		if ((curr->type >= 0 && curr->type <= 2) || (curr->type >= 4 && curr->type <=6))
		{
			t_ast_node *cmd = parse_command(&curr, input);
			// Add the command node as a child of the root
			root->children = realloc(root->children, (root->num_children + 1) * sizeof(t_ast_node *));
			root->children[root->num_children++] = cmd;
		}
		else if (curr->type == PIPE)
			root = parse_pipe(root, &curr, input);
		else
		{
			// Handle unexpected tokens
			printf("Error: unexpected token with type: %d\n", curr->type);
			exit(1);
		}
	}
	return (root);
}
// ===================================================================: Print
void	ft_print_ast(t_ast_node *node, int indent_level)
{
	if (node == NULL)
		return;
	for (int i = 0; i < indent_level; i++)
		printf("  ");
	printf("%d", node->type);
	if (node->value != NULL)
		printf(" [%s]", node->value);
	printf("\n");
	for (int i = 0; i < node->num_children; i++) 
		ft_print_ast(node->children[i], indent_level + 1);
}
/* 
! Error
input: cat "hello" | grep "e"
output: 
		7 [program]
	  2 [cat]
	  2 [hello]
	  2 [ | grep ]
	  2 [e]

Pipe and grep are read as one token.
 */
