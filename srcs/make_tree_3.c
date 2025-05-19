/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:48:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:48:07 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tree_check_arg(t_tab *t, size_t j, size_t *k)
{
	if (t->split[j + (*k)] != 0 && t->var[j + (*k)] == 0 && (t->var[j] > 2
			&& t->var[j] < 5))
		(*k)++;
}

int	*dup_tab_int(int *d, int len, char **ns)
{
	int	*nd;
	int	i;

	i = 0;
	nd = (int *)ft_calloc(len + 1, sizeof(int));
	if (!nd)
	{
		ft_freetabs_ocmd(ns, NULL);
		return (NULL);
	}
	while (i < len)
	{
		nd[i] = d[i];
		i++;
	}
	return (nd);
}
