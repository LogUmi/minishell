/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_com_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:43:55 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:43:57 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_error_cmde_0(char *s, int way)
{
	if (way == 0)
		ft_printf("minishell: %s: No such file or directory\n", s);
	return (127);
}

int	check_error_cmde(char *s, int way, int err)
{
	struct stat	finfo;

	if (stat(s, &finfo) == 0)
	{
		if (S_ISDIR(finfo.st_mode))
		{
			err = 126;
			if (way == 0)
				ft_printf("minishell: %s: Is a directory\n", s);
		}
		else
		{
			if (access(s, X_OK) == -1)
			{
				err = 126;
				if (way == 0)
					ft_printf("minishell: %s: Permission denied\n", s);
			}
		}
	}
	else
		return (check_error_cmde_0(s, way));
	return (err);
}

int	exec_rdir(t_tab *t)
{
	int	fd;

	if (t->rf_in != 0)
	{
		fd = open(t->rf_in->val[1], O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close (fd);
	}
	if (t->rf_oout != 0)
	{
		fd = open(t->rf_oout->val[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(fd, STDOUT_FILENO);
		close (fd);
	}
	else if (t->rf_out != 0)
	{
		fd = open(t->rf_out->val[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
		close (fd);
	}
	return (0);
}

int	exec_pipe(t_tab *t)
{
	if (t->pipe_in != -1)
	{
		dup2(t->pip[t->pipe_in][0], STDIN_FILENO);
		close(t->pip[t->pipe_in][0]);
		t->pip[t->pipe_in][0] = -1;
		close(t->pip[t->pipe_in][1]);
		t->pip[t->pipe_in][1] = -1;
	}
	if (t->pipe_out != -1)
	{
		dup2(t->pip[t->pipe_out][1], STDOUT_FILENO);
		close(t->pip[t->pipe_out][1]);
		t->pip[t->pipe_out][1] = -1;
		close(t->pip[t->pipe_out][0]);
		t->pip[t->pipe_out][0] = -1;
	}
	return (0);
}

void	error_execve(t_bin *tr, t_tab *t)
{
	ft_printf("minishell: %s: ", tr->val[0]);
	perror("");
	exit_check(t, NULL, 1);
}
