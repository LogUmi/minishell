/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:44:47 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 12:06:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd > -1)
		write(fd, &c, 1);
	return ;
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	ft_print(char *s1)
{
	int	i = 0;
	
	while (s1[i] !=0)
		ft_putchar_fd(s1[i++], 1);
		
	write(1, "\n", 1);
}

int	main(void)
{
	ft_print("bonjour");
	ft_print(" Salut a toi !");
	ft_print("");
	return (0);
} */