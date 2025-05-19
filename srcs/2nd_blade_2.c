/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd_blade_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:41:55 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:42:03 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**blade_alloc(t_tab *t, size_t len, size_t ii, size_t j)
{
	char	**ns;
	char	**s;

	ns = t->nsplit;
	s = t->split;
	ns[t->n_wrds] = ft_substr(s[j], ii, len);
	if (ns[t->n_wrds] == 0)
	{
		free(t->var);
		return (magic_split_free(t->nsplit, t->n_wrds));
	}
	t->n_wrds++;
	return (ns);
}

static void	blade_loop_1_2(t_tab *t, int *flag, size_t *i, size_t j)
{
	if (t->split[j][(*i)] == ';' && (*flag) == 0)
	{
		(*i)++;
		t->var[t->n_wrds] = SEP;
	}
	else if ((*flag) == 0 && (t->split[j][(*i)] == '<'
		|| t->split[j][(*i)] == '>'))
	{
		if (t->split[j][(*i)] == '<')
			t->var[t->n_wrds] = RDIR_IN;
		else
			t->var[t->n_wrds] = RDIR_OUT;
		(*i)++;
		while (t->split[j][(*i)] == '<' || t->split[j][(*i)] == '>')
			(*i)++;
	}
}

static void	blade_loop_1_1(t_tab *t, int *flag, size_t *i, size_t j)
{
	int	k;

	k = 0;
	if (t->split[j][(*i)] == '`' && (*flag) == 0)
	{
		(*i)++;
		t->var[t->n_wrds] = ACC;
	}
	else if (t->split[j][(*i)] > 47 && t->split[j][(*i)] < 58 && (*flag) == 0
		&& (*i) == 0)
	{
		while (t->split[j][(*i) + k] > 47 && t->split[j][(*i) + k] < 58)
			k++;
		if (t->split[j][(*i) + k] == '<' || t->split[j][(*i) + k] == '>')
		{
			k++;
			if (t->split[j][(*i) + k] == '>')
				k++;
			(*i) += k;
			t->var[t->n_wrds] = FD;
		}
	}
	else
		blade_loop_1_2(t, flag, i, j);
}

char	**blade_loop_1(t_tab *t, int *flag, size_t *i, size_t j)
{
	t->ii = (*i);
	if (t->split[j][(*i)] == '|' && (*flag) == 0)
	{
		t->var[t->n_wrds] = PIP;
		if (t->split[j][(*i) + 1] == '|')
		{
			(*i)++;
			t->var[t->n_wrds] = OR;
		}
		(*i)++;
	}
	else if (t->split[j][(*i)] == '&' && (*flag) == 0)
	{
		while (t->split[j][(*i) + 1] == '&' || t->split[j][(*i) + 1] == '>')
			(*i)++;
		(*i)++;
		t->var[t->n_wrds] = AND;
	}
	else
		blade_loop_1_1(t, flag, i, j);
	if ((*i) != t->ii)
		return (blade_alloc(t, (*i) - t->ii, t->ii, j));
	return (t->split);
}
