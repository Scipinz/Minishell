/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 16:26:02 by kblok         #+#    #+#                 */
/*   Updated: 2023/05/03 17:19:00 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ignore_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static void	signal_handling_exec(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		g_shell.exit_code = 130;
	}
	if (signal == SIGQUIT)
	{
		write(1, "Quit: 3\n", 8);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_shell.exit_code = 131;
	}
}

static void	signal_handling(int i)
{
	if (i == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_display();
	}
}

void	init_signals(void)
{
	struct termios	ter;

	tcgetattr(STDIN_FILENO, &ter);
	ter.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &ter);
	signal(SIGINT, signal_handling);
	signal(SIGQUIT, signal_handling);
}
