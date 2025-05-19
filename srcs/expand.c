/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:44:47 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:44:50 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	insert_var_2(t_tab *t, size_t *i, size_t j)
{
	size_t	l;
	size_t	m;
	char	*ns;

	l = ft_strlen(t->split[j]) + ft_strlen(t->temp) + 1;
	ns = (char *)ft_calloc(l, sizeof(char));
	if (!ns)
		return (free_expand(t, -1));
	l = 0;
	m = 0;
	while (l < (*i))
	{
		ns[l] = t->split[j][l];
		l++;
	}
	while ((l - (*i)) < ft_strlen(t->temp))
		ns[l++] = t->temp[m++];
	m = 0;
	while (t->split[j][(*i) + m] != 0)
		ns[l++] = t->split[j][(*i) + m++];
	ns[l] = 0;
	free(t->split[j]);
	t->split[j] = ns;
	(*i) += ft_strlen(t->temp);
	return (free_expand(t, 1));
}

static int	insert_var_1(t_tab *t, size_t *i, size_t j, char *s)
{
	char	*var;
	size_t	l;
	size_t	k;

	var = get_var_env(s, t);
	l = (*i);
	k = ft_strlen(s);
	if (t->split[j][(*i) + 1] == '?')
		k++;
	while ((l + k) < ft_strlen(t->split[j]))
	{
		t->split[j][l] = t->split[j][l + k];
		l++;
	}
	t->split[j][l] = 0;
	t->temp = var;
	return (insert_var_2(t, i, j));
}

static int	insert_var(t_tab *t, size_t *i, size_t j, size_t k)
{
	char	arg[1024];
	size_t	l;

	l = 0;
	if (t->split[j][(*i) + 1] == '\"' && t->split[j][(*i) + 2] == 0)
		return (0);
	if (t->split[j][(*i) + 1] != 0 && expban(t->split[j][(*i) + 1]) != 0)
		k = 1;
	else if (t->split[j][(*i) + 1] != 0 && expdoll(t->split[j][(*i) + 1]) != 0)
		k = 0;
	else if (t->split[j][(*i) + 1] == 0 || (t->split[j][(*i) + 1] != 0
				&& expvare(t->split[j][(*i) + 1]) == 0))
		return (0);
	else
		while (t->split[j][(*i) + 1 + k] != 0
				&& expvare(t->split[j][(*i) + 1 + k]) != 0)
			k++;
	while (l < k)
	{
		arg[l] = t->split[j][(*i) + 1 + l];
		l++;
	}
	arg[l] = 0;
	return (insert_var_1(t, i, j, &arg[0]));
}

static int	expand_1(size_t *i, int *f, t_tab *t, size_t j)
{
	char	*s;

	s = t->split[j];
	if ((*f) == 0)
	{
		if (s[(*i)] == '\\')
			return (delchar(s, i, f, 0));
		else if (s[(*i)] == t->q1)
			return (delchar(s, i, f, 1));
		else if (s[(*i)] == t->q2)
			return (delchar(s, i, f, 2));
		else if (s[(*i)] == '$')
			return (insert_var(t, i, j, 0));
	}
	else if ((*f) == 1 && s[(*i)] == t->q1)
		return (delchar(s, i, f, 0));
	else if ((*f) == 2 && s[(*i)] == t->q2)
		return (delchar(s, i, f, 0));
	else if ((*f) == 2 && s[(*i)] == '$')
		return (insert_var(t, i, j, 0));
	return (0);
}

int	expand(t_tab *t, size_t i, size_t j, int f)
{
	int	k;

	t->flag = &f;
	while (t->split[j])
	{
		if (t->var != 0 && is_heredoc(t, j - 1) != -1)
		{
			while (t->split[j][i] != 0)
			{
				k = expand_1(&i, &f, t, j);
				if (k == -1)
				{
					t->flag = NULL;
					return (-1);
				}
				else if (k == 0)
					i++;
			}
		}
		j++;
		i = 0;
	}
	t->flag = NULL;
	t->temp = NULL;
	return (0);
}
