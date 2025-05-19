/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:15:33 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 17:20:22 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* #include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char	s1 [] = "test\200";
	char	s2 [] = "test\0";
	char	s3 [] = "aaaaaaaaaaaa";
	char	s4 [] = "";
	char	s5 [] = "012";
	char	s6 [] = "0z";
	int			n = 6;
	
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s1, s2, n);
	printf("Pas tienne : %d\n", strncmp(s1, s2, n));
	printf("Tienne     : %d\n", ft_strncmp( s1, s2, n));
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s2, s1, n);
	printf("Pas tienne : %d\n", strncmp(s2, s1, n));
	printf("Tienne     : %d\n", ft_strncmp( s2, s1, n));
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s1, s3, n);
	printf("Pas tienne : %d\n", strncmp(s1, s3, n));
	printf("Tienne     : %d\n", ft_strncmp( s1, s3, n));
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s1, s4, n);
	printf("Pas tienne : %d\n", strncmp(s1, s4, n));
	printf("Tienne     : %d\n", ft_strncmp( s1, s4, n));
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s1, s5, n);
	printf("Pas tienne : %d\n", strncmp(s1, s5, n));
	printf("Tienne     : %d\n", ft_strncmp( s1, s5, n));
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s4, s2, n);
	printf("Pas tienne : %d\n", strncmp(s4, s2, n));
	printf("Tienne     : %d\n", ft_strncmp( s4, s2, n));
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s4, s4, n);
	printf("Pas tienne : %d\n", strncmp(s4, s4, n));
	printf("Tienne     : %d\n", ft_strncmp( s4, s4, n));
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s5, s6, n);
	printf("Pas tienne : %d\n", strncmp(s5, s6, n));
	printf("Tienne     : %d\n", ft_strncmp( s5, s6, n));
	n = 0;
	printf("chaine 1: %s ...  chaine 2: %s .... n : %d\n", s1, s2, n);
	printf("Pas tienne : %d\n", strncmp(s1, s2, n));
	printf("Tienne     : %d\n", ft_strncmp( s1, s2, n));	 
	return (0);
} */
