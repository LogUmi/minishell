/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:49:10 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:49:52 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tree_free_right(t_bin *leave)
{
	if (leave->right != 0)
		tree_free_right(leave->right);
	leave->dad->right = NULL;
	leave->dad = NULL;
	if (leave->left != 0)
		tree_free_left(leave->left);
	magic_split_free(leave->val, -1);
	free(leave);
}

void	free_tree(t_bin **root, t_tab *t)
{
	t_bin	*troot;
	t_bin	*sroot;

	troot = *root;
	while (troot)
	{
		sroot = troot->dad;
		if (troot->right != 0)
			tree_free_right(troot->right);
		magic_split_free(troot->val, -1);
		free(troot);
		troot = sroot;
	}
	free(t->tree);
	t->tree = NULL;
}

t_bin	*tree_newleave(t_tab *t, char **ntab, int ntype)
{
	t_bin	*nl;

	nl = malloc(sizeof(t_bin));
	if (nl == 0)
		return (0);
	nl->dad = NULL;
	nl->left = NULL;
	nl->right = NULL;
	nl->val = ntab;
	nl->type = ntype;
	if (t->tree == NULL)
	{
		t->tree = malloc(sizeof(t_bin *));
		if (!t->tree)
			return (0);
		*(t->tree) = NULL;
	}
	return (nl);
}

void	tree_add_dad(t_bin **root, t_bin *new)
{
	t_bin	*troot;

	if (!root || !new)
		return ;
	troot = *root;
	if (*root == 0)
	{
		*root = new;
		return ;
	}
	while (troot->dad != 0)
		troot = troot->dad;
	troot->dad = new;
	troot->dad->left = troot;
	return ;
}

void	tree_add_right(t_bin **root, t_bin *new)
{
	t_bin	*troot;

	if (!root || !new)
		return ;
	troot = *root;
	if (*root == 0)
	{
		*root = new;
		return ;
	}
	while (troot->dad != 0)
		troot = troot->dad;
	troot->right = new;
	troot->right->dad = troot;
	return ;
}
