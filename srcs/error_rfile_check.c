/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_rfile_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:42:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:43:01 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_rfile_check2(t_bin *tr)
{
	int			i;
	struct stat	finfo;

	i = ft_strlen(tr->val[1]) - 1;
	while (i != -1 && tr->val[1][i] != '/')
		i--;
	if (i > -1)
		tr->val[1][i] = '\0';
	if (!(stat(tr->val[1], &finfo) == 0 && S_ISDIR(finfo.st_mode)))
	{
		if (i > -1)
			tr->val[1][i] = '/';
		else
			return (0);
		return (1);
	}
	else if (i > 0)
		tr->val[1][i] = '/';
	return (0);
}

static int	error_rfile_check1(t_bin *tr, int f, t_tab *t)
{
	struct stat	finfo;

	if (stat(tr->val[1], &finfo) == 0)
	{
		if (S_ISDIR(finfo.st_mode))
		{
			return (prt_errf(tr->val[1], "Is a directory", f, t));
		}
		else
		{
			if (!(finfo.st_mode & S_IWUSR))
				return (prt_errf(tr->val[1], "Permission denied", f, t));
		}
	}
	else
	{
		if (error_rfile_check2(tr) == 1)
			return (prt_errf(tr->val[1], "No such file or directory", f, t));
	}
	return (0);
}

static int	error_rfile_check0(t_bin *tr, int f, t_tab *t)
{
	struct stat	finfo;

	if (filename_size(tr) != 0)
		return (prt_errf(tr->val[1], "File name too long", f, t));
	if (tr->type == RDIR_OUT)
		return (error_rfile_check1(tr, f, t));
	if (tr->val[0][0] == '<' && tr->val[0][1] == '\0')
	{
		if (stat(tr->val[1], &finfo) == 0)
		{
			if (S_ISDIR(finfo.st_mode))
				return (0);
			else
			{
				if (!(finfo.st_mode & S_IRUSR))
					return (prt_errf(tr->val[1], "Permission denied", f, t));
			}
		}
		else
			return (prt_errf(tr->val[1], "No such file or directory", f, t));
	}
	return (0);
}

static int	cluster_rcheck(t_bin *tr, t_tab *t, int *flag)
{
	int	err;
	int	err_cmp;

	err = 0;
	while (tr != NULL && tr->type != PIP)
	{
		if (tr->type == RDIR_IN || tr->type == RDIR_OUT)
		{
			err_cmp = err;
			err += error_rfile_check0(tr, (*flag), t);
			if (err != err_cmp)
				(*flag) = set_err_rdir(tr);
		}
		tr = tr->dad;
	}
	return (err);
}

int	error_rfile_check(t_tab *t, int err, t_bin *palier, int flag)
{
	t_bin	*tr;

	tr = (*t->tree);
	palier = tr;
	while (tr != NULL)
	{
		while (palier->dad != NULL && palier->type != PIP)
			palier = palier->dad;
		palier = palier->dad;
		if (cluster_rcheck(tr, t, &flag) == 0)
			do_redir_out(tr);
		else
			err = 1;
		tr = palier;
		flag = 0;
	}
	if (err != 0)
		print_err_file(t);
	return (err);
}
