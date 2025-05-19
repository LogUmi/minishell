/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:20:36 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 15:51:04 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (2048);
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
			printf("%d ... Pas tienne : %d ... Tienne : %d\n", j, isdigit(j),
			ft_isdigit(j));
			j++;
		}
		return (0);
	}
	while (i > 0)
	{
		printf("Pas tienne : %d ... Tienne : %d\n", isdigit(argv[i][0]),
		ft_isdigit(argv[i][0]));
		i--;
	}
	return (0);
}*/