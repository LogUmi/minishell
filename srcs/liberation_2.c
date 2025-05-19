/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:46:31 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 14:48:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_check(t_tab *t, char *msg, int ret)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (t->var)
		free(t->var);
	if (t->hrdfiles)
		free_heredoc(t);
	if (t->input)
		free(t->input);
	if (t->prompt)
		free(t->prompt);
	if (t->split != NULL)
		magic_split_free(t->split, -1);
	if (t->nsplit != NULL)
		magic_split_free(t->nsplit, -1);
	if (t->env_list != NULL)
		free_list(&t->env_list);
	if (t->tree)
		free_tree(t->tree, t);
	if (t->exp_env)
		free_list(&t->exp_env);
	if (t->env != NULL)
		magic_split_free(t->env, -1);
	unset_signals();
	exit (ret);
}

char	**magic_split_free(char **tab, int j)
{
	int	i;

	i = 0;
	if (**tab)
	{
		if (j != -1)
		{
			while (i < j)
				free(tab[i++]);
		}
		else
		{
			while (tab[i])
				free(tab[i++]);
		}
		free(tab);
	}
	return (0);
}
