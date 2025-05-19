/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:44:15 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:44:19 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_com_c0(t_tab *t, t_bin *tr, int rang, int err)
{
	t_bin	*palier;
	t_bin	*trr;

	palier = tr;
	trr = palier;
	redir_init(t);
	if (rang == 1)
		palier = palier->dad;
	if (palier->dad != 0)
		trr = palier->dad;
	while (trr != NULL && trr->dad != NULL && trr->type != PIP)
		trr = trr->dad;
	if (trr != NULL)
	{
		if (trr->type == PIP || trr->dad == NULL)
			err = set_pipe(trr, t, palier);
		while (trr != palier)
		{
			if (trr->type == RDIR_IN || trr->type == RDIR_OUT)
				err = set_rdir(trr, t);
			trr = trr->left;
		}
	}
	err = run_cmde(tr, t);
	return (err);
}

static int	exec_com_1(t_tab *t, t_bin *tr, int rang)
{
	int		err;

	err = 0;
	if (tr->type == 0 || tr->type == 1)
		err = exec_com_c0(t, tr, rang, 0);
	else if (tr->type == PIP)
		err = exec_com_1(t, tr->right, ++rang);
	return (err);
}

static int	exec_com_0(t_tab *t, t_bin *tr)
{
	int		err;

	err = 0;
	silent_signals();
	stdin_to_terminal();
	while (tr)
	{
		err = exec_com_1(t, tr, 0);
		tr = tr->dad;
		while (tr != NULL && tr->dad != 0 && tr->type != PIP)
			tr = tr->dad;
	}
	check_pipe(t);
	wait_children(t);
	set_signals();
	return (err);
}

int	exec_com(t_tab *t)
{
	t_bin	*tr;
	t_bin	*palier;

	tr = last_leaf(t->tree);
	palier = tr;
	while (tr)
	{
		if (tr->type == -1)
		{
			palier = tr->dad;
			break ;
		}
		else if (tr->left == 0)
			palier = tr;
		tr = tr->left;
	}
	if (palier != 0)
		return ((exec_com_0(t, palier)));
	return (0);
}
