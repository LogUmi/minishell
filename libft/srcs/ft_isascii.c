/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:26:48 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 15:50:33 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
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
	j = -1;
	if (argc <= 1)
	{
		while (j < 129)
		{
			printf("%d ... Pas tienne : %d ... Tienne : %d\n", j, isascii(j),
			ft_isascii(j));
			j++;
		}
		return (0);
	}
	while (i > 0)
	{
		printf("Pas tienne : %d ... Tienne : %d\n", isascii(argv[i][0]),
		ft_isascii(argv[i][0]));
		i--;
	}
	return (0);
} */