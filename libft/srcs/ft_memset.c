/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:04:24 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 15:52:47 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	char	b;
	int		i;

	b = c;
	str = s;
	i = 0;
	while (n > 0)
	{
		str[i++] = b;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char array [] = "0123456789";
	int i;
	int j;
	
	i = 4098;
	j = 0;
	while (j < 10)
			{
				printf("/%d",array[j]);
				j++;
			}
	printf("\n");
	while (i == 4098)
	{
		j = 0;
		printf("%d ... Pas tienne : %p  ", i, memset(array, i, 5));
		while (j < 10)
		{
			printf("/%d",array[j]);
			j++;
		}
		j = 0;
		printf(" ... Tienne : %p  ", ft_memset(array, i, 5));
		while (j < 10)
		{
			printf("/%d",array[j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
} */