/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:17:34 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/28 14:22:25 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	val;
	int	sign;

	i = 0;
	val = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		val = (val * 10);
		val = val + (nptr[i] - 48);
		i++;
	}
	val = val * sign;
	return (val);
}
/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	ft_print(char *s1)
{
	printf("chaine: %s\n", s1);
	printf("fct originale: %d\n", atoi(s1));
	printf("Ta fonction  : %d\n\n", ft_atoi(s1));
}

int	main(void)
{
	char s1[] ="      4568654";
	
	s1[0] = 9;
	s1[1] = 10;
	s1[2] = 11;
	s1[3] = 12;
	s1[4] = 13;
	ft_print(s1);
	ft_print(" +012345[]]");
	ft_print("- 012345dsd");
	ft_print(" -012345dsd");
	ft_print("-2147483648");
	ft_print("--2147483648");
	ft_print("+-2147483648");
	ft_print("2147483648");
	ft_print("-42147483648");
	ft_print("25644147483648");
	ft_print("0x147483648");
	ft_print("");
	return (0);
} */