/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:53:01 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/05 17:33:35 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(int argc, char *argv[])
{
	int	i;
	int j;
	
	i = argc - 1;
	j = 0;
	if (argc <= 1)
		return (0);
	while (i > 0)
	{
		printf("%s ...Pas tienne : %lu ... Tienne : %lu\n", 
		argv[i], strlen(argv[i]),
		ft_strlen(argv[i]));
		i--;
	}
	return (0);
}  */