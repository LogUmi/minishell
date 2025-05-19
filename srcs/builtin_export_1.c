/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:56:14 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 14:56:17 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export_list(t_lst *list)
{
	while (list)
	{
		ft_printf("declare -x %s\n", (list->content));
		list = list->next;
	}
	return ;
}

int	check_dash(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (arg[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

t_lst	*in_env(t_lst *list, t_lst *var)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (var->content[i] && var->content[i] != '=')
		i++;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, var->content, i) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	add_var_in_list(t_tab *t, t_lst *var, t_lst *tmp_exp, t_lst *tmp_env)
{
	if (tmp_exp && !tmp_env)
	{
		free(tmp_exp->content);
		tmp_exp->content = ft_strdup(var->content);
		add_export_format(tmp_exp);
		ft_lst_back(&t->env_list, ft_listnew(var->content));
	}
	else if (tmp_env && tmp_exp)
	{
		free(tmp_exp->content);
		tmp_exp->content = ft_strdup(var->content);
		add_export_format(tmp_exp);
		free(tmp_env->content);
		tmp_env->content = ft_strdup(var->content);
	}
	else if (tmp_exp == NULL)
	{
		ft_lst_back(&t->env_list, ft_listnew(var->content));
		add_export_format(var);
		ft_lst_back(&t->exp_env, ft_listnew(var->content));
	}
}
