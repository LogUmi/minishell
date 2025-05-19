/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:48:12 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/16 17:27:06 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_builtin(char *s)
{
	if (ft_strncmp(s, "echo", 4) == 0 && ft_strlen(s) == 4)
		return (BUI);
	if (ft_strncmp(s, "cd", 2) == 0 && ft_strlen(s) == 2)
		return (BUI);
	if (ft_strncmp(s, "pwd", 3) == 0 && ft_strlen(s) == 3)
		return (BUI);
	if (ft_strncmp(s, "export", 6) == 0 && ft_strlen(s) == 6)
		return (BUI);
	if (ft_strncmp(s, "unset", 5) == 0 && ft_strlen(s) == 5)
		return (BUI);
	if (ft_strncmp(s, "env", 3) == 0 && ft_strlen(s) == 3)
		return (BUI);
	if (ft_strncmp(s, "exit", 4) == 0 && ft_strlen(s) == 4)
		return (BUI);
	return (CMD);
}

static int	check_affect(t_tab *t, size_t j, int k)
{
	order_cmdes(t);
	while (t->split[j])
	{
		if (t->var[j] > 1)
			j++;
		else if (t->var[j] == CMD)
		{
			k = check_builtin(t->split[j]);
			t->var[j++] = k;
			while (t->split[j] && t->var[j] == CMD)
				t->var[j++] = k;
		}
		else
			j++;
	}
	return (0);
}

char	**tab_tree(char **s, size_t start, size_t nlign, size_t i)
{
	char	**ns;
	int		l;

	l = 0;
	ns = ft_calloc(nlign + 1, sizeof(char *));
	if (!ns)
		return (NULL);
	while (i < nlign)
	{
		ns[i] = ft_calloc(ft_strlen(s[start + i]) + 1, sizeof(char));
		if (!ns[i])
			return (magic_split_free(ns, i));
		l = 0;
		while (s[start + i][l] != 0)
		{
			ns[i][l] = s[start + i][l];
			l++;
		}
		ns[i][l] = 0;
		i++;
	}
	ns[i] = 0;
	return (ns);
}

t_bin	*init_tree(t_tab *t, char **ns, size_t j)
{
	t_bin	*nl;

	nl = tree_newleave(t, ns, t->var[j]);
	if (!nl)
	{
		magic_split_free(ns, -1);
		return (NULL);
	}
	if (*(t->tree) == NULL)
		*(t->tree) = nl;
	else if (t->var[j] > 1 && t->var[j] < 10)
		tree_add_dad(t->tree, nl);
	else if (t->var[j] == 0 || t->var[j] == 1)
		tree_add_right(t->tree, nl);
	return (nl);
}

int	make_tree(t_tab *t, size_t j, size_t k)
{
	char	**ns;
	t_bin	*nl;

	ns = NULL;
	nl = NULL;
	if (check_affect(t, 0, 0) != 0)
		return (-1);
	while (t->split[j])
	{
		k = 0;
		while (t->split[j + k + 1] && t->var[j + k] == t->var[j + k + 1]
			&& t->var[j + k] < 2)
			k++;
		k++;
		tree_check_arg(t, j, &k);
		ns = tab_tree(t->split, j, k, 0);
		if (!ns)
			return (-1);
		nl = init_tree(t, ns, j);
		if (!nl)
			return (-1);
		while (k-- != 0)
			j++;
	}
	return (0);
}
