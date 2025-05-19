/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:44:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 14:58:03 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_spaces(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if ((s[i] > 8 && s[i] < 14) || s[i] == 32)
			j++;
		i++;
	}
	return (i - j);
}

int	unclosed_quotes(char *str)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '\'' && flag == 0)
			flag = 1;
		else
		{
			if (str[i] == '\'' && flag == 1)
				flag = 0;
		}
		if (str[i] == '"' && flag == 0)
			flag = 2;
		else
		{
			if (str[i] == '"' && flag == 2)
				flag = 0;
		}
		i++;
	}
	return (flag);
}

int	get_cmde_1(t_tab *t)
{
	if (make_tree(t, 0, 0) == -1)
	{
		ft_printf("minishell: memory allocation issue during tree creation\n");
		return (newloop_free(t));
	}
	if (synt_error_test(t) != 0)
		return (newloop_free(t));
	exec_com(t);
	return (newloop_free(t));
}

int	get_cmde(t_tab *t)
{
	ft_write_history(t);
	if (only_spaces(t->input) == 0)
		return (0);
	if (unclosed_quotes(t->input) != 0)
	{
		ft_printf("minishell: unclosed quote error\n");
		return (0);
	}
	if (!magic_split(t))
	{
		ft_printf("minishell: memory allocation issue during magic split\n");
		return (0);
	}
	if (!scd_blade(t))
	{
		ft_printf("minishell: memory allocation issue during 2nd blade\n");
		return (newloop_free(t));
	}
	if (expand(t, 0, 0, 0) == -1)
	{
		ft_printf("minishell: memory allocation issue during expansion\n");
		return (newloop_free(t));
	}
	return (get_cmde_1(t));
}
