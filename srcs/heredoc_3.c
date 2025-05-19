/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:45:16 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 15:24:44 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	hrd_expand_2(size_t *i, t_tab *t, char *s)
{
	int	j;

	j = 0;
	write(t->fd_hrd, "$", 1);
	(*i)++;
	while (s[(*i) + j] != 0)
	{
		s[j] = s[(*i) + j];
		j++;
	}
	s[j] = 0;
	(*i) = 0;
	return (0);
}

static int	hrd_expand_1(size_t *i, char *s, char *arg, t_tab *t)
{
	size_t	j;
	size_t	k;

	t->temp = get_var_env(arg, t);
	j = 0;
	k = ft_strlen(arg);
	write(t->fd_hrd, t->temp, ft_strlen(t->temp));
	if (s[(*i) + 1] == '?')
		k++;
	(*i) += k;
	while (s[(*i) + j] != 0)
	{
		s[j] = s[(*i) + j];
		j++;
	}
	s[j] = 0;
	(*i) = 0;
	t->temp = NULL;
	return (0);
}

int	hrd_expand(char *s, size_t *i, t_tab *t, size_t k)
{
	char	arg[1024];
	size_t	l;

	l = 0;
	if (s[(*i) + 1] == '\"' && s[(*i) + 2] == 0)
		return (0);
	if (s[(*i) + 1] != 0 && expban(s[(*i) + 1]) != 0)
		k = 1;
	else if (s[(*i) + 1] != 0 && expdoll(s[(*i) + 1]) != 0)
		k = 0;
	else if (s[(*i) + 1] == 0 || (s[(*i) + 1] != 0
			&& expvare(s[(*i) + 1]) == 0))
		return (hrd_expand_2(i, t, s));
	else
		while (s[(*i) + 1 + k] != 0
			&& expvare(s[(*i) + 1 + k]) != 0)
			k++;
	while (l < k)
	{
		arg[l] = s[(*i) + 1 + l];
		l++;
	}
	arg[l] = 0;
	return (hrd_expand_1(i, s, &arg[0], t));
}

int	hrd_is_quote(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[i] != 0)
	{
		if (s[i] == '\'' || s[i] == '\"')
			j = 0;
		i++;
	}
	return (j);
}
