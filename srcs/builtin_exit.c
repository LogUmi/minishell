/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:55:08 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 14:55:15 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long int	ft_atol(const char *nptr)
{
	long int	sign;
	long int	num;
	int			i;

	sign = 1;
	num = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

static size_t	int_len(long int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
	}
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char	*ft_ltoa(long int n, char *nb, unsigned long nbr)
{
	size_t		len;

	len = 0;
	if (n > 0)
		nbr = (unsigned long)n;
	else
	{
		nbr = -(unsigned long)n;
		if (nbr != 9223372036854775808UL)
			len = 1;
	}
	len += int_len(nbr);
	nb = malloc(sizeof(char) * (len + 1));
	nb[len] = '\0';
	while (len--)
	{
		nb[len] = '0' + (nbr % 10);
		nbr /= 10;
		if (nbr == 0 && n < 0 && len > 0)
		{
			nb[--len] = '-';
			break ;
		}
	}
	return (nb);
}

static int	valid_exit_arg(char *arg)
{
	long	nb;
	char	*nbr;
	int		i;

	i = 0;
	if (arg[0] == '-')
		i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	nb = ft_atol(arg);
	nbr = ft_ltoa(nb, NULL, 0);
	if (ft_strncmp(arg, nbr, ft_strlen(arg)) != 0)
	{
		free(nbr);
		return (0);
	}
	free(nbr);
	return (1);
}

int	builtin_exit(t_tab *t, char **val)
{
	if (val[1])
	{
		val[1] = remove_plus_sign(val[1]);
		if (val[2] != NULL)
		{
			ft_putstr_fd("exit\nminishel: exit: too many arguments\n", 2);
			return (t->ex_status = 1);
		}
		else if (!valid_exit_arg(val[1]))
		{
			ft_putstr_fd("exit\nminishell: exit: ", 2);
			ft_putstr_fd(val[1], 2);
			ft_putstr_fd(": numeric argument required", 2);
			exit_check(t, NULL, t->ex_status = 2);
		}
		else
		{
			if (ft_atol(val[1]) >= 0)
				exit_check(t, "exit", t->ex_status = ft_atol(val[1]) % 256);
			else if (ft_atol(val[1]) < 0)
				exit_check(t, "exit",
					t->ex_status = -((-ft_atol(val[1])) % 256));
		}
	}
	exit(exit_check(t, "exit", t->ex_status = 0));
}
