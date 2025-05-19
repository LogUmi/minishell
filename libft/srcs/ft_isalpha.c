/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:24:26 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 15:50:21 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1024);
	return (0);
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
			printf("%d ... Pas tienne : %d ... Tienne : %d\n", j, isalpha(j),
			ft_isalpha(j));
			j++;
		}
		return (0);
	}
	while (i > 0)
	{
		printf("Pas tienne : %d ... Tienne : %d\n", isalpha(argv[i][0]),
		ft_isalpha(argv[i][0]));
		i--;
	}
	return (0);
} */