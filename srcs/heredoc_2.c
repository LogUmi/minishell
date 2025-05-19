/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:45:02 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:45:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d_hrd(t_tab *t, t_bin *tr)
{
	ft_printf("minishel: warning: here-document at line %i ", t->nlhd);
	ft_printf("delimited by end-of-file (wanted `%s", tr->val[1]);
	ft_printf("')\n");
}

void	hrd_set_flag(char c, t_tab *t, int *f)
{
	if (c == t->q1)
	{
		if ((*f) == 0)
			(*f) = 1;
		else if ((*f) == 1)
			(*f) = 0;
	}
	if (c == t->q2)
	{
		if ((*f) == 0)
			(*f) = 2;
		else if ((*f) == 2)
			(*f) = 0;
	}
}

void	hrd_sup_char(char *s, size_t i)
{
	while (s[i] != 0)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[i] = 0;
}

void	hrd_ignore_bs(char **s, t_tab *t)
{
	int	i;
	int	f;
	int	k;

	i = 0;
	f = 0;
	while (s[1][i] != 0)
	{
		hrd_set_flag(s[1][i], t, &f);
		if (s[1][i] == '\\' && f == 0)
		{
			k = 0;
			while (s[i + k] != 0)
			{
				s[i + k] = s[i + k + 1];
				k++;
			}
			s[i + k] = 0;
		}
		else
			i++;
	}
}

void	hrd_sup_quotes(char **s, t_tab *t)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (s[1][i] != 0)
	{
		hrd_set_flag(s[1][i], t, &f);
		if (s[1][i] == t->q1 && f == 0)
			hrd_sup_char(s[1], i);
		else if (s[1][i] == t->q1 && f == 1)
			hrd_sup_char(s[1], i);
		else if (s[1][i] == t->q2 && f == 0)
			hrd_sup_char(s[1], i);
		else if (s[1][i] == t->q2 && f == 2)
			hrd_sup_char(s[1], i);
		else
			i++;
	}
}
