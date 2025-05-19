/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:19:14 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 15:47:23 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	str = s;
	i = 0;
	while (n > 0)
	{
		str[i++] = 0;
		n--;
	}
}
/* 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	char array [] = "0123456789";
	int j;
		
	j = 0;
	while (j < 10)
			{
				printf("/%d",array[j]);
				j++;
			}
	printf("\n");
	j = 0;
	printf("Pas tienne : ");
	bzero(array, 5);
	while (j < 10)
	{
		printf("/%d",array[j]);
		j++;
	}
	j = 0;
	printf(" ... Tienne : ");
	ft_bzero(array, 10);
	while (j < 10)
	{
		printf("/%d",array[j]);
		j++;
	}
	printf("\n");
		return (0);
} */