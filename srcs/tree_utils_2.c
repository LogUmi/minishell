/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:49:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:49:06 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bin	*last_leaf(t_bin **tr)
{
	t_bin	*lf;

	lf = *tr;
	while (lf->dad != NULL)
		lf = lf->dad;
	return (lf);
}

void	tree_free_left(t_bin *leave)
{
	if (leave->left != 0)
		tree_free_left(leave->left);
	leave->dad->left = NULL;
	leave->dad = NULL;
	if (leave->right != 0)
		tree_free_right(leave->right);
	magic_split_free(leave->val, -1);
	free(leave);
}
