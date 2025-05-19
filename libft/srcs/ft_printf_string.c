/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:50:11 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/29 17:47:46 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_strlenf(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_putstrf(const char *str, int *nsp)
{
	int	i;
	int	j;

	j = 0;
	if (!str)
		return (0);
	i = ft_strlenf(str);
	while (j < (*nsp) - i)
	{
		write(1, " ", 1);
		j++;
	}
	(*nsp) = 0;
	write(1, str, i);
	return (i + j);
}

int	ft_putcf(int i, int n)
{
	unsigned char	c;
	int				j;

	c = (unsigned char)(i);
	j = 0;
	while (j < n)
	{
		write(1, &c, 1);
		j++;
	}
	return (j);
}

int	ft_printstr(const char *str, int *nsp)
{
	if ((*nsp) < 0)
		(*nsp) = 0;
	if (!str)
		return (ft_putstrf("(null)", nsp));
	return (ft_putstrf(str, nsp));
}

int	ft_putccf(int i, int n, int *nsp)
{
	unsigned char	c;
	int				j;
	int				k;

	c = (unsigned char)(i);
	j = 0;
	k = 0;
	if ((*nsp) < 0)
		(*nsp) = 0;
	while (j < (*nsp) - n)
	{
		write(1, " ", 1);
		j++;
	}
	while (k < n)
	{
		write(1, &c, 1);
		k++;
	}
	return (j + k);
}
