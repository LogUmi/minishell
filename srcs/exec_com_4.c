/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_com_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:44:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/16 16:48:55 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin_pipe(t_tab *t, char **val)
{
	t->pide[t->npid] = fork();
	if (t->pide[t->npid] == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		exec_pipe(t);
		exec_builtin(t, val);
		check_pipe(t);
		exit_check(t, NULL, 0);
	}
	else
		t->npid++;
}

void	stdin_to_terminal(void)
{
	int	tty;

	if (!isatty(STDIN_FILENO))
	{
		tty = open("/dev/tty", O_RDWR);
		if (tty == -1)
		{
			perror("open /dev/tty");
			return ;
		}
		if (dup2(tty, STDIN_FILENO) == -1)
			perror("dup2 /dev/tty to stdin");
		close(tty);
	}
}

void	stdout_to_terminal(void)
{
	int	tty;
	
	if (!isatty(STDOUT_FILENO))
	{
		tty = open("/dev/tty", O_RDWR);
		if (tty == -1)
		{
			perror("open /dev/tty");
			return ;
		}
		if (dup2(tty, STDOUT_FILENO) == -1)
			perror("dup2 /dev/tty to stdout");
		close(tty);
	}
}

int	error_cluster(t_tab *t)
{
	if (pipe(t->pip[t->npip]) == -1)
	{
		perror("pipe");
		return (-1);
	}
	t->pipe_in = t->npip;
	t->npip++;
	return (0);
}
