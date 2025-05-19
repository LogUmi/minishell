/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:31:58 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 16:20:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_toupper(int c)
{
	if ((c > 96 && c < 123))
		c = c - 32;
	return (c);
}
/* 
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

int	main(int argc, char *argv[])
{
	int	i;
	int j;
	
	i = argc - 1;
	j = 0;
	if (argc <= 1)
	{
		while (j < 129)
		{
			printf("%d ... Pas tienne : %d ... Tienne : %d\n", j, toupper(j),
			ft_toupper(j));
			j++;
		}
		return (0);
	}
	while (i > 0)
	{
		printf("Pas tienne : %d ... Tienne : %d\n", toupper(argv[i][0]),
		ft_toupper(argv[i][0]));
		i--;
	}
	return (0);
} */