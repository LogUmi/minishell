/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:44:31 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 11:51:43 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_expand(t_tab *t, int ret)
{
	if (t->temp != 0)
	{
		free(t->temp);
		t->temp = NULL;
	}
	return (ret);
}

char	*get_var_env(char *s, t_tab *t)
{
	char	*var;
	int		i;

	i = 0;
	if (s[0] == '?')
	{
		var = ft_itoa(t->ex_status);
	}
	else
	{
		while (s[i] != 0)
			i++;
		s[i++] = '=';
		s[i] = 0;
		var = ft_getenv(t->env_list, s);
	}
	return (var);
}

int	is_heredoc(t_tab *t, int j)
{
	if (j < 0)
		return (0);
	if (t->var[j] == RDIR_IN && ft_strlen(t->split[j]) == 2
		&& t->split[j][0] == '<' && t->split[j][1] == '<')
		return (-1);
	return (0);
}

int	delchar(char *s, size_t *i, int *f, size_t flag)
{
	size_t	k;

	k = (*i);
	while (k < ft_strlen(s))
	{
		s[k] = s[k + 1];
		k++;
	}
	(*f) = flag;
	return (1);
}
