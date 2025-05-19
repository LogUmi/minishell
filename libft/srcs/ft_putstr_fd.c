/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:10:25 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/05 19:06:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if (fd > -1)
	{
		while (s[i] != 0)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return ;
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	ft_putstr_fd("bonjour", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" Salut a toi !", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" Salut a toi !", -1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" Salut a toi !", 0);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" Salut a toi !", 2);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("", 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
 */