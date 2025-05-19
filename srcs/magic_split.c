/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:27 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:47:37 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	loop_1(char *s, int f, size_t *ii, t_tab *t)
{
	size_t	i;
	char	c;

	c = t->c;
	i = (*ii);
	while (s[i] != 0 && ((s[i] == c || (s[i] > 8 && s[i] < 14)) && f == 0))
		i++;
	(*ii) = i;
}

static void	loop_2(char *s, int *flag, size_t *ii, t_tab *t)
{
	size_t	i;
	int		f;

	i = (*ii);
	f = (*flag);
	while (s[i] != 0 && !((s[i] == t->c || (s[i] > 8 && s[i] < 14)) && f == 0))
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

static size_t	ft_nbwords(t_tab *t, char *s, size_t i, size_t n)
{
	int	f;

	f = 0;
	while (s[i] != 0)
	{
		loop_1(s, f, &i, t);
		loop_2(s, &f, &i, t);
		if (!((s[i - 1] == t->c || (s[i -1] > 8 && s[i - 1] < 14)) && f == 0))
			n++;
	}
	return (n);
}

static char	**ft_strextr(t_tab *t, char **ns, char *s, size_t j)
{
	size_t	i;
	size_t	len;
	int		f;
	int		ii;

	i = 0;
	f = 0;
	while (s[i] != 0)
	{
		loop_1(s, f, &i, t);
		ii = i;
		loop_2(s, &f, &i, t);
		len = 0 + i - ii;
		if (!((s[i - 1] == t->c || (s[i -1] > 8 && s[i - 1] < 14)) && f == 0))
		{
			ns[j] = ft_substr(s, i - len, len);
			if (ns[j] == 0)
				return (magic_split_free(ns, j));
			j++;
		}
	}
	ns[j] = 0;
	return (ns);
}

char	**magic_split(t_tab *t)
{
	size_t	j;
	char	**ns;

	if (t->input == 0)
		return (0);
	ns = NULL;
	j = ft_nbwords(t, t->input, 0, 0);
	t->n_wrds = j;
	ns = (char **)ft_calloc(j + 1, sizeof(char *));
	if (ns == 0)
		return (0);
	if (ft_strextr(t, ns, t->input, 0) == 0)
		return (0);
	t->split = ns;
	return (ns);
}
