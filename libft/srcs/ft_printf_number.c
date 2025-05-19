/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:39:29 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/29 17:49:30 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_len(long long i, int nbase, int u)
{
	unsigned long long	nh;
	unsigned long long	nbh;
	long long			nb;

	nh = (unsigned long long)i;
	nbh = (unsigned long long)nbase;
	nb = (long long)nbase;
	if (u == 0)
	{
		if (i > (nb - 1))
			return (ft_len((i / nb), nbase, u) + 1);
		else
			return (1);
	}
	else
	{
		if (nh > (nbh - 1))
			return (ft_len((nh / nbh), nbase, u) + 1);
		else
			return (1);
	}
}

int	ft_putint(int i, int *ndig)
{
	int	j;

	j = (*ndig);
	if (i == -2147483648)
		return (ft_putstrf("-2147483648", ndig));
	if (i < 0)
	{
		i *= -1;
		(*ndig) += 1;
		if ((*ndig) > 0)
		{
			j = j - ft_len(i, 10, 0) - 1;
			(*ndig = 0);
			return (ft_putcf(32, j) + ft_putcf(45, 1) + ft_putint(i, ndig));
		}
		return (ft_putcf(45, 1) + ft_putint(i, ndig));
	}
	(*ndig) += 1;
	if (((*ndig) - 1) * -1 > ft_len(i, 10, 0) && (*ndig - 1) < 0)
		return (ft_putcf(48, 1) + ft_putint((i), ndig));
	if (i > 9)
		return (ft_putint((i / 10), ndig) + ft_putcf((i % 10) + 48, 1));
	else
		return (ft_putcf(i + 48, 1));
}

int	ft_putnsbase(unsigned int i, char *bs, int *ndig)
{
	int	nb;
	int	j;

	nb = ft_strlenf(bs);
	j = (*ndig) - ft_len(i, nb, 1);
	if ((*ndig) > 0)
	{
		(*ndig) = 0;
		if (j > 0)
			return (ft_putcf(32, j) + ft_putnsbase(i, bs, ndig));
	}
	if ((*ndig) < 0)
	{
		j = ((*ndig) * -1) - ft_len(i, nb, 1);
		(*ndig) = 0;
		if (j > 0)
			return (ft_putcf(48, j) + ft_putnsbase(i, bs, ndig));
	}
	if (i > (unsigned int)(nb -1))
		return (ft_putnsbase(i / nb, bs, ndig) + ft_putcf(bs[i % nb], 1));
	else
		return (ft_putcf(bs[i], 1));
}

int	ft_putnbrullbase(unsigned long long i, char *bs)
{
	int	nb;

	nb = ft_strlenf(bs);
	if (i > (unsigned long long)(nb - 1))
		return (ft_putnbrullbase((i / nb), bs) + ft_putcf(bs[i % nb], 1));
	else
		return (ft_putcf(bs[i % nb], 1));
}

int	ft_printpointer(void *p, char *bs, int *ndig)
{
	unsigned long long	i;

	if (!p)
		return (ft_printstr("(nil)", ndig));
	i = (unsigned long long)p;
	if ((*ndig) > 0)
	{
		(*ndig) = (*ndig) - (ft_len(i, ft_strlenf(bs), 1));
		return (ft_putstrf("0x", ndig) + ft_putnbrullbase(i, bs));
	}
	else
	{
		write(1, "0x", 2);
		(*ndig) = ((*ndig) * -1) - (ft_len(i, ft_strlenf(bs), 1));
		return (2 + ft_putcf(48, (*ndig)) + ft_putnbrullbase(i, bs));
	}
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int i = 0;

	i = printf("%p", (void *)0);
	printf("... %d\n", i);
	i = ft_printpointer((void *)0, "0123456789abcdef");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("... %d\n", i);
	i = ft_printpointer((void *)LONG_MIN, "0123456789abcdef");
	printf("  %i\n", i);
	i = ft_printpointer((void *)LONG_MAX, "0123456789abcdef");
	printf("  %i\n\n", i);
	i = printf(" %p %p ", (void *)ULONG_MAX,(void *)-ULONG_MAX);
	printf("... %d\n", i);
	i = ft_printpointer((void *)ULONG_MAX, "0123456789abcdef");
	printf("  %i\n", i);
	i = ft_printpointer((void *)-ULONG_MAX, "0123456789abcdef");
	printf("  %i\n\n", i);
	i = printf(" %p ", &i);
	printf("... %d\n", i);
	i = ft_printpointer(&i, "0123456789abcdef");
	printf("  %i\n\n", i);
	i = ft_printint(0);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(0, "0123456789");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(-2147483648);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(-2147483648, "0123456789");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(-2147483648, "0123456789abcdef");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(2147483647);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(2147483648, "0123456789");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(2147483648, "0123456789ABCDEF");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(255);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(255, "0123456789");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(255, "0123456789ABCDEF");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(800);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(-4646548);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	if (i == 0)
		return (0);
	return(0);
} */