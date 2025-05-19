/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_com_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:43:48 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/19 15:37:53 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_tab *t, char **val)
{
	exec_rdir(t);
	if (ft_strcmp(val[0], "env") == 0)
		print_list(t->env_list);
	else if (ft_strcmp(val[0], "export") == 0)
		exec_export(t, val);
	else if (ft_strcmp(val[0], "unset") == 0 && val[1])
	{
		ft_unsetenv(&t->env_list, val, t, 0);
		ft_unsetenv(&t->exp_env, val, t, 0);
	}
	else if (ft_strcmp(val[0], "cd") == 0)
		builtin_cd(t, val);
	else if (ft_strcmp(val[0], "pwd") == 0)
		builtin_pwd();
	else if (ft_strcmp(val[0], "exit") == 0)
		builtin_exit(t, val);
	else if (ft_strcmp(val[0], "echo") == 0)
		builtin_echo(val, t);
	stdin_to_terminal();
	stdout_to_terminal();
}

static void	exec_cmd_0(t_bin *tr, t_tab *t)
{
	char	*path;
	int		i;

	i = 1;
	path = get_path(t, tr->val[0]);
	if (path == NULL)
	{
		i = 0;
		free(path);
		path = ft_strdup(tr->val[0]);
	}
	if (check_error_cmde(path, i, 0) != 0)
	{
		if (i == 1)
			cmd_nf(tr->val[0]);
		free(path);
		exit_check(t, NULL, 127);
	}
	if (execve(path, tr->val, t->env) == -1)
	{
		free(path);
		error_execve(tr, t);
	}
}

void	exec_cmd(t_bin *tr, t_tab *t, int err)
{
	char	*path;

	(void)t;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	exec_pipe(t);
	exec_rdir(t);
	if (ft_strrchr(tr->val[0], '/'))
	{
		path = tr->val[0];
		err = check_error_cmde(path, 0, 0);
		if (err != 0)
		{
			exit_check(t, NULL, err);
		}
		if (execve(path, tr->val, t->env) == -1)
			error_execve(tr, t);
	}
	else
		exec_cmd_0(tr, t);
}

void	wait_children(t_tab *t)
{
	int		i;
	int		status;

	i = 0;
	while (i < t->npid)
	{
		status = 0;
		waitpid(t->pide[i], &status, 0);
		t->ex_status = status;
		if ((status & 0x7f) == 0)
			t->ex_status = (status >> 8) & 0xff;
		else if ((status & 0x7f) != 0 && (status & 0x7f) != 0x7f)
			t->ex_status = 128 + (status & 0x7f);
		else if ((status & 0x7f) == 0x7f)
			t->ex_status = 128 + ((status >> 8) & 0xff);
		i++;
	}
	t->npid = 0;
}

void	check_pipe(t_tab *t)
{
	int		i;

	i = 0;
	while (i < t->npip)
	{
		if (t->pip[i][0] != -1)
		{
			close(t->pip[i][0]);
			t->pip[i][0] = -1;
		}
		if (t->pip[i][1] != -1)
		{
			close(t->pip[i][1]);
			t->pip[i][1] = -1;
		}
		i++;
	}
	t->npip = 0;
}
