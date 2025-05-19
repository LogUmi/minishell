/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:12:56 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 16:19:21 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((little[0] == 0 && big[0] == 0) || little[0] == 0)
		return ((char *)big);
	while (i < len && big[i] != 0)
	{
		while (little[j] == big[i + j] && little[j] != 0)
			j++;
		if (little[j] == 0)
		{
			if ((j + i) > len)
				return (0);
			return ((char *)&big[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
/* #include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>

static void	ft_print(char *s1, char *s2, size_t n)
{
	printf("chaine : %s ... cherche : %s ... longueur : %zu\n", s1, s2, n);
	printf("Pas tienne : %p ... %s\n", strnstr(s1, s2, n), strnstr(s1, s2, n));
	printf("Tienne     : %p ... %s\n\n", ft_strnstr(s1, s2, n), 
		ft_strnstr(s1, s2, n));
}

int	main(void)
{
	char	s1 [] = "01234567890123456789";
	char	s2 [] = "456";
	int		n = 20;
	
	ft_print(s1, s2, n);
	n = 30;
	ft_print(s1, s2, n);
	n = 0;
	ft_print(s1, s2, n);
	n = 5;
	ft_print(s1, s2, n);
	n = 6;
	ft_print(s1, s2, n);
	n = 7;
	ft_print(s1, s2, n);
	n = 8;
	ft_print(s1, s2, n);
	ft_print("", s2, n);
	ft_print(s1, "", n);
	ft_print("", "" ,n);
	ft_print("", "", 0);
	s1[0] = 0;
	ft_print(s1, s1, n);
	return (0);
} */