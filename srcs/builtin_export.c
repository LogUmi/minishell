/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:56:03 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 14:56:05 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_exp_list(t_tab *t)
{
	t_lst	*tmp;
	char	*swp;
	int		size;

	size = 0;
	tmp = t->exp_env;
	swp = NULL;
	while (tmp->next)
	{
		if (ft_strlen(tmp->content) >= ft_strlen(tmp->next->content))
			size = ft_strlen(tmp->content);
		else
			size = ft_strlen(tmp->next->content);
		if (ft_strncmp(tmp->content, tmp->next->content, size) > 0)
		{
			swp = tmp->content;
			tmp->content = tmp->next->content;
			tmp->next->content = swp;
			tmp = t->exp_env;
		}
		else
			tmp = tmp->next;
	}
}

void	add_export_format(t_lst *exp_lst)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;
	int		d;

	i = -1;
	j = 0;
	d = 0;
	len = ft_strlen(exp_lst->content);
	tmp = malloc(sizeof(char) * len + 3);
	while (++i, exp_lst->content[i])
	{
		tmp[j++] = exp_lst->content[i];
		if (exp_lst->content[i] == '=' && d == 0)
		{
			tmp[j++] = '\"';
			d = 1;
		}
	}
	tmp[j++] = '\"';
	tmp[j] = '\0';
	free(exp_lst->content);
	exp_lst->content = tmp;
}

int	exec_export(t_tab *t, char **val)
{
	int		i;
	t_lst	*tmp_var;

	i = 1;
	t->ex_status = 0;
	while (val[i])
	{
		if (!check_export_input(val[i]))
		{
			tmp_var = malloc(sizeof(t_lst));
			tmp_var->content = ft_strdup(val[i]);
			ft_setenv(t, tmp_var);
			free(tmp_var->content);
			free(tmp_var);
		}
		else
			t->ex_status = 1;
		i++;
	}
	sort_exp_list(t);
	if (!val[1])
		print_export_list(t->exp_env);
	init_tab_env(t, t->env_list, 0, NULL);
	return (t->ex_status);
}

int	check_export_input(char *args)
{
	int		i;
	char	**var;

	i = 1;
	if (!check_dash(args))
	{
		if (ft_isalpha(args[0]) || args[0] == '_')
		{
			while (args[i] && args[i] != '=')
			{
				if (!ft_isalnum(args[i]))
					return (1);
				i++;
			}
			return (0);
		}
	}
	var = ft_split(args, '=');
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(var[0], 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	free_t_tab(var);
	return (1);
}

void	init_export_list(t_tab *t)
{
	t_lst	*tmp;
	t_lst	*exp_lst;

	tmp = t->env_list;
	while (tmp)
	{
		if (strncmp(tmp->content, "_", 1))
			ft_lst_back(&t->exp_env, ft_listnew(tmp->content));
		tmp = tmp->next;
	}
	exp_lst = t->exp_env;
	while (exp_lst)
	{
		add_export_format(exp_lst);
		exp_lst = exp_lst->next;
	}
	sort_exp_list(t);
}
