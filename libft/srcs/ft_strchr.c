/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:52:49 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/23 15:44:58 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
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
	printf("Pas tienne : %p ... %s\n", strchr(array, test), strchr(array, test));
	printf("Tienne     : %p ... %s\n", ft_strchr(array, test), 
		ft_strchr(array, test));
	printf("array : %s ... cherche : %c\n", arraybis, test);
	printf("Pas tienne : %p ... %s\n", strchr(arraybis, test), 
		strchr(arraybis, test));
	printf("Tienne     : %p ... %s\n", ft_strchr(arraybis, test), 
		ft_strchr(arraybis, test));
	test = 0;
	printf("array : %s ... cherche : %c\n", array, test);
	printf("Pas tienne : %p ... %s\n", strchr(array, test), strchr(array, test));
	printf("Tienne     : %p ... %s\n", ft_strchr(array, test), 
		ft_strchr(array, test));
	test = 'c';
	printf("array : %s ... cherche : %c\n", "", test);
	printf("Pas tienne : %p ... %s\n", strchr("", test), strchr("", test));
	printf("Tienne     : %p ... %s\n", ft_strchr("", test), ft_strchr("", test));

	return (0);
}  */