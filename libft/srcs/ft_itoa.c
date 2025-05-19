/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:39:16 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/22 20:11:15 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	ft_convstr(char *num, long n, int i)
{
	char	c;

	c = '0';
	if (n < 0)
	{
		num[i++] = '-';
		n *= -1;
	}
	if (n >= 10)
	{
		i = ft_convstr(num, n / 10, i);
		n = n % 10;
		c = c + n;
		num[i++] = c;
	}
	else
	{
		c = c + n;
		num[i++] = c;
	}
	return (i);
}

static	size_t	ft_lenint(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n > 9)
	{
		n /= 10;
		i++;
		return (ft_lenint(n) + i);
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	long	nn;

	i = 0;
	nn = (long)n;
	num = (char *)malloc((ft_lenint(nn) + 1) * sizeof(char));
	if (num == 0)
		return (0);
	num[ft_convstr(num, nn, i)] = 0;
	return (num);
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	ft_print(s1)
{
	char	*s2 = ft_itoa(s1);
	
	printf("valeur: %d\n", s1);
	if (s2 != 0)
	{
		printf("Ta fonction: %s\n\n", s2);
		free(s2);
	}
	else
		printf("Ta fonction: NULL");
}

int	main(void)
{
	
 	ft_print(12345);
	ft_print(10);
	ft_print(-10);
	ft_print(-12345);
	ft_print(012345);
	ft_print(2147483647);
	ft_print(0x14748);
	ft_print(-2147483648);
	return (0);
} */