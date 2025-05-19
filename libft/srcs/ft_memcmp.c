/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:56:44 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 17:23:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ss1;
	char	*ss2;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	if (n < 1)
		return (0);
	while (n != i && ss1[i] == ss2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}
/* #include <stdio.h>
#include <string.h>
#include <ctype.h>

static void	ft_print(char *s1, char *s2, size_t n)
{
	printf("chaine 1: %s ... chaine 2: %s ... nb char : %zu\n", s1, s2, n);
	printf("Pas tienne : %d\n", memcmp(s1, s2, n));
	printf("Tienne     : %d\n", ft_memcmp( s1, s2, n));
}

int	main(void)
{
	char	s1 [] = "012345";
	char	s2 [] = "012345";
	char	s3 [] = "aaaaaaaaaaaa";
	char	s4 [] = "";
	char	s5 [] = "012";
	char	s6 [] = "0z";
	int			n = 5;
	
	ft_print(s1, s2, n);
	ft_print(s2, s1, n);
	ft_print(s1, s3, n);
	ft_print(s1, s4, n);
	ft_print(s1, s5, n);
	ft_print(s4, s2, n);
	ft_print(s4, s4, n);
	ft_print(s5, s6, n);
	ft_print(s1, s2, 0);
	ft_print("", s2, n);
	ft_print(s1, "", n);
	ft_print("", "", n);
	
	return (0);
} */