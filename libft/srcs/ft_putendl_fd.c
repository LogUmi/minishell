/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:24:51 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 12:31:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	if (fd > -1)
	{
		while (s[i] != 0)
			write(fd, &s[i++], 1);
		write(fd, "\n", 1);
	}
	return ;
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	ft_putendl_fd("bonjour", 1);
	ft_putendl_fd(" Salut a toi !", 1);
	ft_putendl_fd(" Salut a toi !", -1);
	ft_putendl_fd(" Salut a toi !", 0);
	ft_putendl_fd(" Salut a toi !", 2);
	ft_putendl_fd("", 1);
	return (0);
} */