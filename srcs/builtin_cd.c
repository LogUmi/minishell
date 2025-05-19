/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:01:05 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 15:01:08 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_updatewd(t_lst **env_list, char *var, char *value)
{
	t_lst	*tmp;
	int		varlen;
	char	*tvar;

	tmp = *env_list;
	tvar = ft_strdup(var);
	varlen = ft_strlen(var);
	while (tmp)
	{
		if (ft_strncmp(tmp->content, var, varlen) == 0)
		{
			free(tmp->content);
			tmp->content = ft_strjoin(tvar, value);
			return ;
		}
		tmp = tmp->next;
	}
	ft_lst_back(env_list, ft_listnew((char *)ft_strjoin(tvar, value)));
}

static char	*find_path(t_lst *env_list, char *path)
{
	if (!path || path[0] == '~')
	{
		free(path);
		path = ft_getenv(env_list, "HOME=");
		if (!path)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), path);
	}
	else
	{
		free(path);
		path = ft_getenv(env_list, "OLDPWD=");
		if (!path)
			return (ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2), path);
	}
	return (path);
}

static void	cd_update_env(t_tab *t, char *oldpwd)
{
	char	newpwd[PATH_MAX];

	if (oldpwd)
	{
		ft_updatewd(&t->env_list, "OLDPWD=", oldpwd);
		ft_updatewd(&t->exp_env, "OLDPWD=", oldpwd);
	}
	if (getcwd(newpwd, sizeof(newpwd)))
	{
		ft_updatewd(&t->env_list, "PWD=", newpwd);
		ft_updatewd(&t->exp_env, "PWD=", newpwd);
	}
}

int	builtin_cd(t_tab *t, char **val)
{
	char	*path;
	char	*oldpwd;

	path = NULL;
	if (val[1])
	{
		if (val[2])
			return (ft_putstr_fd("minishell: cd: too many arguments\n", 2),
				t->ex_status = 1);
		path = ft_strdup(val[1]);
	}
	oldpwd = ft_getenv(t->env_list, "PWD=");
	if (!path || path[0] == '~' || path[0] == '-')
	{
		path = find_path(t->env_list, path);
		if (!path)
			return (t->ex_status = 1);
	}
	if (chdir(path) != 0)
		return (free(oldpwd), free(path), perror("cd"), t->ex_status = 1);
	cd_update_env(t, oldpwd);
	free(oldpwd);
	if (path)
		free(path);
	return (t->ex_status = 0);
}
