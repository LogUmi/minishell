/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:06 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:47:21 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_heredoc(t_tab *t)
{
	int	i;

	i = 0;
	if (t->hrdfiles != 0)
	{
		while (t->hrdfiles[i] != NULL)
		{
			if (unlink(t->hrdfiles[i++]) != 0)
				ft_printf("minishell: heredoc temporary file issue\n");
		}
		magic_split_free(t->hrdfiles, -1);
		t->hrdfiles = NULL;
	}
}

int	newloop_free(t_tab *t)
{
	if (t->hrdfiles)
		free_heredoc(t);
	if (t->var)
	{
		free(t->var);
		t->var = NULL;
	}
	if (t->split)
	{
		magic_split_free(t->split, -1);
		t->split = NULL;
	}
	if (t->nsplit)
	{
		magic_split_free(t->nsplit, -1);
		t->nsplit = NULL;
	}
	if (t->tree)
	{
		free_tree(t->tree, t);
		t->tree = NULL;
	}
	return (0);
}

int	**error_tab(t_tab *t, int way, int **kk)
{
	int	**k;

	k = kk;
	if (way == 0)
	{
		k = ft_calloc(4, sizeof(int *));
		k[0] = ft_calloc(ft_strlen(t->input) + 1, sizeof(int));
		k[1] = ft_calloc(ft_strlen(t->input) + 1, sizeof(int));
		k[2] = ft_calloc(ft_strlen(t->input) + 1, sizeof(int));
		k[3] = 0;
	}
	if (way == 1)
	{
		free(k[0]);
		free(k[1]);
		free(k[2]);
		free(k);
	}
	return (k);
}
