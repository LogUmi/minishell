/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:58:11 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 18:11:51 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*str_d;
	char	*str_s;
	int		i;
	int		j;

	str_d = dest;
	str_s = src;
	i = 0;
	j = 1;
	if (dest == 0 && src == 0)
		return (0);
	if (dest > src)
	{
		i = n - 1;
		j = -1;
	}
	while (n > 0)
	{
		str_d[i] = str_s[i];
		i = i + j;
		n--;
	}
	return (dest);
}
/* #include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char array [] = "0123456789";
	char arraybis [] = "0123456789";
	printf("array 1 : %s \narray 2 : %s\n",array, arraybis);
	printf("Pas tienne : %p ... ", memmove(&array[2], array, 5));
	printf("array 1 : %s \n", array);					
	printf("Tienne : %p ...", ft_memmove(&arraybis[2], arraybis, 5));
	printf("array 2 : %s\n",arraybis);
	printf("Pas tienne : %p ... ", memmove(array, &array[2], 5));
	printf("array 1 : %s \n", array);					
	printf("Tienne : %p ...", ft_memmove(arraybis, &arraybis[2], 5));
	printf("array 2 : %s\n",arraybis);
	return (0);
} */