/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_com_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:43:40 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 18:11:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_pipe(t_bin *tr, t_tab *t, t_bin *palier)
{
	if (palier->type == PIP && t->npip == 0)
	{
		if (error_cluster(t) == -1)
			return (-1);
	}
	if ((t->fpip == 1 && t->npip >= 1))
	{
		t->pipe_in = t->npip - 1;
		t->fpip = 0;
	}
	if (t->fpip == 0 && t->npip >= 0 && palier->dad != NULL && (tr->dad != NULL
			|| tr->right != NULL))
	{
		if (pipe(t->pip[t->npip]) == -1)
		{
			perror("pipe");
			return (-1);
		}
		t->pipe_out = t->npip;
		t->npip++;
		t->fpip++;
	}
	return (0);
}

int	set_rdir(t_bin *tr, t_tab *t)
{
	if (tr->type == RDIR_IN)
		t->rf_in = tr;
	if (tr->type == RDIR_OUT && tr->val[0][0] == '>' && tr->val[0][1] != 0)
		t->rf_oout = tr;
	else if (tr->type == RDIR_OUT && tr->val[0][0] == '>'
				&& tr->val[0][1] == 0)
		t->rf_out = tr;
	return (0);
}

int	run_cmde(t_bin *tr, t_tab *t)
{
	if (tr->type == CMD)
	{
		t->pide[t->npid] = fork();
		if (t->pide[t->npid] == 0)
			exec_cmd(tr, t, 0);
		t->npid++;
	}
	else if (tr->type == BUI)
	{
		if (t->npip == 0)
			exec_builtin(t, tr->val);
		else if (t->npip > 0)
			exec_builtin_pipe(t, tr->val);
	}
	if (t->pipe_in != -1 && t->npip >= 1)
	{
		close(t->pip[t->pipe_in][0]);
		t->pip[t->pipe_in][0] = -1;
		close(t->pip[t->pipe_in][1]);
		t->pip[t->pipe_in][1] = -1;
	}
	return (0);
}

void	svr_stdio(t_tab *t, int way)
{
	if (way == 0)
	{
		t->stdin_sav = dup(STDIN_FILENO);
		t->stdout_sav = dup(STDOUT_FILENO);
	}
	else if (way == 1)
	{
		dup2(t->stdin_sav, STDIN_FILENO);
		dup2(t->stdout_sav, STDOUT_FILENO);
		close(t->stdin_sav);
		close(t->stdout_sav);
	}
	else if (way == 2)
	{
		t->stdin_sav = dup(STDIN_FILENO);
		t->stdout_sav = dup(STDOUT_FILENO);
	}
}

void	redir_init(t_tab *t)
{
	t->rf_in = NULL;
	t->rf_out = NULL;
	t->rf_oout = NULL;
	t->pipe_in = -1;
	t->pipe_out = -1;
}
