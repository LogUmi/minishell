/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:57:59 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 16:19:58 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_tolower(int c)
{
	if ((c > 64 && c < 91))
		c = c + 32;
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
			printf("%d ... Pas tienne : %d ... Tienne : %d\n", j, tolower(j),
			ft_tolower(j));
			j++;
		}
		return (0);
	}
	while (i > 0)
	{
		printf("Pas tienne : %d ... Tienne : %d\n", tolower(argv[i][0]),
		ft_tolower(argv[i][0]));
		i--;
	}
	return (0);
} */