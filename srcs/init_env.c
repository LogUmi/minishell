/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:58:04 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 14:58:07 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_lst **env_list, char **env)
{
	char	**env_tab;
	int		i;

	i = 0;
	env_tab = env;
	while (env_tab[i])
	{
		ft_lst_back(env_list, ft_listnew(env_tab[i]));
		i++;
	}
	return ;
}

char	*ft_getenv(t_lst *env_list, char *str)
{
	int	len;

	len = ft_strlen(str);
	while (env_list)
	{
		if (ft_strncmp((char *)env_list->content, str, len) == 0)
			return (ft_trim_start((char *)env_list->content, str));
		env_list = env_list->next;
	}
	return (NULL);
}

void	ft_setenv(t_tab *t, t_lst *var)
{
	t_lst	*tmp_exp;
	t_lst	*tmp_env;

	tmp_exp = in_env(t->exp_env, var);
	tmp_env = in_env(t->env_list, var);
	if (ft_strchr(var->content, '='))
		add_var_in_list(t, var, tmp_exp, tmp_env);
	else
	{
		if (tmp_exp)
			return ;
		else
			ft_lst_back(&t->exp_env, ft_listnew(var->content));
	}
}

int	ft_unsetenv(t_lst **env_list, char **var, t_tab *t, int i)
{
	t_lst	*tmp;
	t_lst	*prev;
	int		varlen;

	while (++i, var[i])
	{
		varlen = ft_strlen(var[i]);
		tmp = *env_list;
		prev = NULL;
		while (tmp)
		{
			if (ft_strncmp(tmp->content, var[i], varlen) == 0)
			{
				if (prev)
					prev->next = tmp->next;
				else
					*env_list = tmp->next;
				free_node(tmp);
				break ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
	return (t->ex_status = 0);
}

char	**init_tab_env(t_tab *t, t_lst *lst, int i, char **tab)
{
	if (t->env != NULL)
		magic_split_free(t->env, -1);
	t->env = NULL;
	lst = t->env_list;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	lst = t->env_list;
	tab = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (lst)
	{
		tab[i] = ft_strdup(lst->content);
		if (!tab[i])
			return (magic_split_free(tab, i));
		i++;
		lst = lst->next;
	}
	t->env = tab;
	return (tab);
}
