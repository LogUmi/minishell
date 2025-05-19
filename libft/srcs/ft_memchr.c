/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:28:02 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/19 21:56:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ss;

	i = 0;
	ss = (const unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
			return ((void *)((char *)s + i));
		i++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
#include <ctype.h>

static void	ft_print(char *s1, int c, size_t n)
{
	printf("chaine : %s ... cherche : %c ... longueur : %zu\n", s1, c, n);
	printf("Pas tienne : %p ... %s\n", memchr(s1, c, n), 
		(char *)memchr(s1, c, n));
	printf("Tienne     : %p ... %s\n\n", ft_memchr(s1, c, n), 
		(char *)ft_memchr(s1, c, n));
}

int	main(void)
{
	char	s1 [] = "01234567890123456789";
	char	c = 'c';
	int		n = 5;
	
	ft_print(s1, c, n);
	n = 22;
	ft_print(s1, c, n);
	n = 20;
	ft_print(s1, c, n);
	c = '7';
	n = 8;
	ft_print(s1, c, n);
	n = 30;
	ft_print(s1, c, n);
	n = 20;
	ft_print(s1, c, n);
	ft_print("", c ,n);
	s1[0] = 0;
	ft_print(s1, c, n);
	s1[0] = '0';
	c = 0;
	ft_print(s1, c, n);
	n = 0;
	ft_print(s1, c, n);
	return (0);
} */