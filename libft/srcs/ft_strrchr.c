/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:02:37 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/23 15:47:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	i--;
	while (i > -1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char	array [] = "012345c6789012345c6789";
	char	arraybis [] = "000000000000000000000";
	char	test = 'c';
	
	printf("array : %s ... cherche : %c\n", array, test);
	printf("Pas tienne : %p ... %s\n", strrchr(array, test), 
	strrchr(array, test));
	printf("Tienne     : %p ... %s\n", ft_strrchr(array, test), 
		ft_strrchr(array, test));
	printf("array : %s ... cherche : %c\n", arraybis, test);
	printf("Pas tienne : %p ... %s\n", strrchr(arraybis, test), 
		strrchr(arraybis, test));
	printf("Tienne     : %p ... %s\n", ft_strrchr(arraybis, test), 
		ft_strrchr(arraybis, test));
	test = 0;
	printf("array : %s ... cherche : %c\n", array, test);
	printf("Pas tienne : %p ... %s\n", strrchr(array, test), 
	strrchr(array, test));
	printf("Tienne     : %p ... %s\n", ft_strrchr(array, test), 
		ft_strrchr(array, test));
	test = 'c';
	printf("array : %s ... cherche : %c\n", "", test);
	printf("Pas tienne : %p ... %s\n", strrchr("", test), strrchr("", test));
	printf("Tienne     : %p ... %s\n", ft_strrchr("", test),
	nb ft_strrchr("", test));

	return (0);
} */