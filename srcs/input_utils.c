/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:02:46 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/16 16:24:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_tab(char **tab)
{
	char	**tmp;

	tmp = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(tmp);
}

char	*get_cmd(char *argv)
{
	char	*cmd;
	char	**argv_tab;

	argv_tab = ft_split(argv, ' ');
	if (!argv_tab)
		return (NULL);
	cmd = ft_strdup(argv_tab[0]);
	free_t_tab(argv_tab);
	return (cmd);
}

char	**get_opt(char *argv)
{
	char	**opt;
	char	**argv_tab;
	int		i;
	int		count;

	count = 0;
	i = -1;
	opt = NULL;
	argv_tab = ft_split(argv, ' ');
	if (!argv_tab)
		return (NULL);
	while (argv_tab[count])
		count++;
	opt = (char **)malloc(sizeof(char *) * (count + 1));
	if (!opt)
	{
		free_t_tab(argv_tab);
		return (NULL);
	}
	while (++i, i < count)
		opt[i] = ft_strdup(argv_tab[i]);
	opt[i] = NULL;
	free_t_tab(argv_tab);
	return (opt);
}

char	*get_path(t_tab *t, char *input)
{
	char	*env_path;
	char	*path;
	char	**t_path;

	path = NULL;
	env_path = ft_getenv(t->env_list, "PATH=");
	if (env_path)
	{
		t_path = ft_split(env_path, ':');
		free(env_path);
		path = set_path(t_path, input, path);
		if (!path)
			path = ft_strdup("");
		return (path);
	}
	else
		return (NULL);
}

char	*set_path(char **t_path, char *argv, char *path)
{
	int		j;
	char	*cmd;

	j = 0;
	cmd = get_cmd(argv);
	while (t_path[j])
	{
		t_path[j] = ft_strjoin(t_path[j], "/");
		t_path[j] = ft_strjoin(t_path[j], cmd);
		if (access(t_path[j], X_OK) == 0)
		{
			path = ft_strdup(t_path[j]);
			return (free(t_path[j]), free(t_path), free(cmd), path);
		}
		free(t_path[j]);
		j++;
	}
	return (free(t_path), free(cmd), path);
}
