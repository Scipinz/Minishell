/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:01:32 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/18 10:19:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/libft.h"

//=========================================================: Enum
typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

//=========================================================: CMD & Args
// Describe a simple command and arguments
typedef struct s_command
{
    char    command;
    int     arg_count;
    char    **arguments;
    char    **options;
} t_command;


//=========================================================: CMD Table
// Describes a complete command with the multiple pipes 
// if any and input/output redirection if any.
typedef struct s_table
{
    char        *in_file;
    char        *out_file;
    char        *err_file;
    int         cmd_count;
    t_command   *command;
} t_table;

#endif
