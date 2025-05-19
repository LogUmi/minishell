/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:35:01 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 13:15:16 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbrrec_fd(int n, int fd)
{
	char	c;

	c = 48;
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		if (n >= 10)
		{
			ft_putnbrrec_fd(n / 10, fd);
			c = n % 10 + 48;
			write (fd, &c, 1);
		}
		if (n < 10)
		{
			c = n + 48;
			write(fd, &c, 1);
		}
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd > -1)
		ft_putnbrrec_fd(n, fd);
	return ;
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(2147483647, -1);
	write(1, "\n", 1);
	ft_putnbr_fd(800, 0);
	write(1, "\n", 1);
	ft_putnbr_fd(-4646548, 2);
	write(1, "\n", 1);
	return (0);
} */