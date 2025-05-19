/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:42:06 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/23 15:37:55 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str;
	const char	*srcc;
	int			i;

	str = dest;
	srcc = src;
	i = 0;
	if (str == 0 && srcc == 0)
		return (0);
	while (n > 0)
	{
		str[i] = srcc[i];
		i++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char array [] = "0123456789";
	char arraybis [] = "----------";
	char arrayter [] = "__________";
	printf("array 1 : %s \narray 2 : %s\narray 3 : %s\n",array,
	 arraybis, arrayter);
	printf("Pas tienne : %p \n", memcpy(arraybis, array, 5));
	printf("array 1 : %s \narray 2 : %s\narray 3 : %s\n",array,
	 arraybis, arrayter);					
	printf("Tienne : %p \n", ft_memcpy(arrayter, array, 10));
	printf("array 1 : %s \narray 2 : %s\narray 3 : %s\n",array,
	 arraybis, arrayter);
	return (0);
} */