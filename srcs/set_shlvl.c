/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:03:03 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 15:03:05 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_shlvl(t_tab *t)
{
	t_lst	*tmp_var;
	char	*shlvl;
	char	*tmp_slvl;
	int		lvl;

	tmp_var = malloc(sizeof(t_lst));
	shlvl = ft_getenv(t->env_list, "SHLVL=");
	if (!shlvl)
		shlvl = ft_strdup("0");
	lvl = ft_atoi(shlvl);
	lvl++;
	free(shlvl);
	shlvl = ft_itoa(lvl);
	tmp_slvl = ft_strdup("SHLVL=");
	tmp_slvl = ft_strjoin(tmp_slvl, shlvl);
	tmp_var->content = ft_strdup(tmp_slvl);
	ft_setenv(t, tmp_var);
	free(tmp_var->content);
	free(tmp_var);
	free(tmp_slvl);
	free(shlvl);
}
