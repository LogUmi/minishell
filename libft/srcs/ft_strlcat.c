/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:24:01 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/23 15:30:30 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lengh;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] != 0)
		i++;
	lengh = i;
	while ((i < (size - 1)) && (src[j] != 0))
		dst[i++] = src[j++];
	dst[i] = 0;
	while (!(src[j] == 0))
		j++;
	if (lengh > size)
		return (size + j);
	return (lengh + j);
}
/* #include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>

int	main(void)
{
	 char array [] = "0123456789";
	char arraybis [] = "98765432109876543210xx";
	char arrayter [] = "0123456789";
	char arrayqua[] = "98765432109876543210xx";
	int i = 0;
	
	array[0] = 0;
	arrayter[0] = 0;
	arraybis[0] = 0;
	arrayqua[0] = 0;
	printf("array 1 : %s \narray 2 : %s\n", array, arraybis);
	printf("Pas tienne : %zu ... ", strlcat(arraybis, array, 11));
	printf("array 1 : %s \n", arraybis);
	while (i < 22)
		printf("%d ",arraybis[i++]);					
	printf ("\n");	
	printf("Tienne : %zu ...", ft_strlcat(arrayqua, "", 11));
	printf("array 2 : %s\n",arrayqua);
	i = 0;
	while (i < 22)
		printf("%d ",arrayqua[i++]);					
	printf ("\n");
	return (0);
} */