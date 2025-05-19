/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:57:29 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 14:57:31 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_option(char *arg)
{
	int	i;

	i = 1;
	if (arg[0] == '-')
	{
		while (arg[i])
		{
			if (arg[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int	builtin_echo(char **args, t_tab *t)
{
	int	i;

	i = 1;
	if (args[1] && is_valid_option(args[1]))
	{
		while (++i, args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	else
	{
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putchar_fd('\n', 1);
	}
	return (t->ex_status = 0);
}
