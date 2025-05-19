/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd_blade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:42:14 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:42:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	loop_1(char *s, int *flag, size_t *i, size_t *n)
{
	if (s[(*i)] == '|' && (*flag) == 0)
	{
		if (s[(*i) + 1] == '|')
			(*i)++;
		(*i)++;
		(*n)++;
	}
	else if (s[(*i)] == 96 && (*flag) == 0)
	{
		(*i)++;
		(*n)++;
	}
	else if (s[(*i)] == '&' && (*flag) == 0)
	{
		while (s[(*i) + 1] == '&' || s[(*i) + 1] == '>')
			(*i)++;
		(*i)++;
		(*n)++;
	}
	else
		loop_1_1(s, flag, i, n);
}

static void	loop_2(char *s, int *flag, size_t *ii, t_tab *t)
{
	size_t	i;
	int		f;

	i = (*ii);
	f = (*flag);
	while (loop_in_loop_2(s, i, f) == 1)
	{
		if (s[i] == t->q1)
		{
			if (f == 0)
				f = 1;
			else if (f == 1)
				f = 0;
		}
		if (s[i] == t->q2)
		{
			if (f == 0)
				f = 2;
			else if (f == 2)
				f = 0;
		}
		i++;
	}
	(*ii) = i;
	(*flag) = f;
}

static size_t	ft_nbwords(t_tab *t, char **s, size_t i, size_t n)
{
	int		f;
	size_t	j;

	j = 0;
	f = 0;
	while (s[j])
	{
		while (s[j][i] != 0)
		{
			loop_1(s[j], &f, &i, &n);
			loop_2(s[j], &f, &i, t);
			if (s[j][i - 1] != 124 && s[j][i -1] != 60 && s[j][i -1] != 62
				&& s[j][i -1] != 38 && s[j][i -1] != 59 && s[j][i -1] != 96)
				n++;
		}
		j++;
		i = 0;
	}
	return (n);
}

static char	**ft_strextr(t_tab *t, char **s, size_t i, size_t j)
{
	int		f;
	size_t	ii;

	f = 0;
	while (s[j])
	{
		while (s[j][i] != 0)
		{
			t->var[t->n_wrds] = 0;
			if (blade_loop_1(t, &f, &i, j) == NULL)
				return (NULL);
			ii = i;
			loop_2(s[j], &f, &i, t);
			if (s[j][i - 1] != 124 && s[j][i -1] != 60 && s[j][i -1] != 62
				&& s[j][i -1] != 38 && s[j][i -1] != 59 && s[j][i -1] != 96)
				if (blade_alloc(t, i - ii, ii, j) == NULL)
					return (0);
		}
		j++;
		i = 0;
	}
	t->nsplit[t->n_wrds] = 0;
	return (t->nsplit);
}

char	**scd_blade(t_tab *t)
{
	size_t	j;
	int		*nd;
	char	**ns;

	if (t->split == 0)
		return (0);
	ns = NULL;
	j = ft_nbwords(t, t->split, 0, 0);
	ns = (char **)ft_calloc(j + 1, sizeof(char *));
	if (ns == 0)
		return (0);
	nd = (int *)ft_calloc(j + 1, sizeof(int));
	if (!nd)
		return (magic_split_free(ns, -1));
	t->var = nd;
	t->nsplit = ns;
	t->n_wrds = 0;
	if (ft_strextr(t, t->split, 0, 0) == 0)
		return (0);
	magic_split_free(t->split, -1);
	t->split = ns;
	t->nsplit = 0;
	return (ns);
}
