/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_rfile_check_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:42:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:42:34 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	tree_cut_leaves(t_bin *tr)
{
	t_bin	*svtr;

	svtr = tr;
	while (tr->left != NULL && tr->left->type != PIP)
	{
		svtr = tr->left;
		if (tr->left != 0 && tr->dad != NULL)
		{
			tr->dad->left = tr->left;
			tr->left->dad = tr->dad;
		}
		else if (tr->left != NULL && tr->dad == NULL)
			tr->left->dad = NULL;
		else if (tr->left == NULL && tr->dad != NULL)
			tr->dad->left = NULL;
		if (tr->right != NULL)
			tree_free_right(tr->right);
		magic_split_free(tr->val, -1);
		free(tr);
		tr = svtr;
	}
	svtr->type = -1;
	if (svtr->left == NULL && svtr->dad != NULL)
		svtr->dad->left = svtr;
}

void	tree_pruning(t_tab *t)
{
	int		i;
	t_bin	*tr;
	t_bin	*trb;

	tr = last_leaf(t->tree);
	i = 0;
	while (tr != NULL)
	{
		while (tr != NULL && tr->type == PIP)
			tr = tr->left;
		trb = tr;
		while (tr != NULL && tr->type != PIP)
		{
			if (tr->type == -1)
				i++;
			tr = tr->left;
		}
		if (i != 0)
			tree_cut_leaves(trb);
		i = 0;
		if (tr != NULL)
			tr = tr->left;
	}
}

static void	tree_cut_leaf(t_bin *tr)
{
	if (tr->left != 0 && tr->dad != NULL)
	{
		tr->dad->left = tr->left;
		tr->left->dad = tr->dad;
	}
	else if (tr->left != NULL && tr->dad == NULL)
		tr->left->dad = NULL;
	else if (tr->left == NULL && tr->dad != NULL)
		tr->dad->left = NULL;
	if (tr->right != NULL)
		tree_free_right(tr->right);
	magic_split_free(tr->val, -1);
	free(tr);
}

static void	tree_reducing_io(t_bin *tr, int *i, int type)
{
	t_bin	*svtr;

	if ((*i) != 0)
	{
		while (tr != NULL && tr->type != PIP)
		{
			svtr = tr->left;
			if (tr->type == type && (*i) != 0)
				(*i) = 0;
			else if (tr->type == type && *(i) == 0)
				tree_cut_leaf(tr);
			tr = svtr;
		}
	}
}

void	tree_reducing(t_tab *t)
{
	int		i[2];
	t_bin	*tr;
	t_bin	*trb;

	tr = last_leaf(t->tree);
	i[0] = 0;
	i[1] = 0;
	while (tr != NULL)
	{
		while (tr != NULL && tr->type == PIP)
			tr = tr->left;
		trb = tr;
		while (tr != NULL && tr->type != PIP)
		{
			if (tr->type == RDIR_IN)
				i[0]++;
			else if (tr->type == RDIR_OUT)
				i[1]++;
			tr = tr->left;
		}
		tree_reducing_io(trb, &i[0], RDIR_IN);
		tree_reducing_io(trb, &i[1], RDIR_OUT);
		if (tr != NULL)
			tr = tr->left;
	}
}
