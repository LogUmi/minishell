/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:14:21 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/19 21:59:43 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int	ft_printspecs(const char *str, va_list *args, int *nd, int nchar)
{
	char	*d;
	char	*h;
	char	*hm;

	d = "0123456789";
	h = "0123456789abcdef";
	hm = "0123456789ABCDEF";
	if (str[0] == '%')
		nchar = ft_putccf(37, 1, nd);
	else if (str[0] == 'c')
		nchar = ft_putccf(va_arg((*args), int), 1, nd);
	else if (str[0] == 's')
		nchar = ft_printstr(va_arg((*args), char *), nd);
	else if (str[0] == 'i' || str[0] == 'd')
		nchar = ft_putint(va_arg((*args), int), nd);
	else if (str[0] == 'u')
		nchar = ft_putnsbase(va_arg((*args), unsigned int), d, nd);
	else if (str[0] == 'x')
		nchar = ft_putnsbase(va_arg((*args), unsigned int), h, nd);
	else if (str[0] == 'X')
		nchar = ft_putnsbase(va_arg((*args), unsigned int), hm, nd);
	else if (str[0] == 'p')
		nchar = ft_printpointer(va_arg((*args), void *), h, nd);
	return (nchar);
}

static int	ft_printselect(const char *str, va_list *args, int *len)
{
	static int	nd = 0;
	int			i;

	i = 0;
	nd = 0;
	if (str[0] == 48)
		i++;
	if (i == 1)
		nd = 1;
	while (str[i] > 47 && str[i] < 58)
		i++;
	if (i == 0)
		return (ft_printspecs(&str[0], args, &nd, 0));
	(*len) += i;
	if (nd != 0)
		nd = ft_atoi(&str[1]) * -1;
	else
		nd = ft_atoi(&str[0]);
	return (ft_printspecs(&str[i], args, &nd, 0));
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;
	int			nchar;

	va_start (args, str);
	len = 0;
	nchar = 0;
	while (str[len] != 0)
	{
		if ((unsigned char)str[len] != '%')
			nchar += ft_putcf(str[len], 1);
		else
			nchar += ft_printselect(&str[++len], &args, &len);
		len++;
	}
	va_end(args);
	return (nchar);
}
/* 
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	char	*s = "coucou";

	
	i = printf(" %014d ", -9);
	printf(" ... %i\n", i);
	i = ft_printf(" %014d ", -9);
	printf(" ... %i\n", i);
	i = printf(" %5d ", -1);
	printf(" ... %i\n", i);
	i = ft_printf(" %5d ", -1);
	printf(" ... %i\n", i);
	i = printf(" %10s ", s);
	printf(" ... %i\n", i);
	i = ft_printf(" %10s ", s);
	printf(" ... %i\n", i);
	i = printf("01234\t , %%, %c, %s, %s:, %d, %i, %u, %x, %p end", 'O',
	"56789%s", "",-2147483647, -2147483647, 2147483647, 255, s);
	printf("... %d\n", i);
	i = ft_printf("01234\t , %%, %c, %s, %s:, %d, %i, %u, %x, %p end", 'O',
	 "56789%s", "", -2147483648, -2147483647, 2147483648, 255, s);
	printf("... %d\n", i);
	printf("\n");
	i = printf("|%5x - %05X", 255, 255);
	printf("... %d\n", i);
	i = ft_printf("|%5x - %05X", 1255, 255);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("... %d\n", i);
	i = ft_printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %25p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("... %d\n", i);
	i = ft_printf(" %25p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %p %p ", (void *)ULONG_MAX,(void *)-ULONG_MAX);
	printf("... %d\n", i);
	i = ft_printf(" %p %p ",(void *)ULONG_MAX,(void *)-ULONG_MAX);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %p %p ", (void *)0, (void *)0);
	printf("... %d\n", i);
	i = ft_printf(" %p %p ", (void *)0, (void *)0);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" NULL %s NULL ", (char *)NULL);
	printf("... %d\n", i);
	i = ft_printf(" NULL %s NULL ", (char *)NULL);
	printf("... %d\n", i);
	i = ft_printf(" %s, %s:end\n", "56789%s", "");
	i = printf(" %5c %c %c ", (int)'0', (int)0, (int)'1');
	printf("... %d\n", i);
	i = ft_printf(" %5c %c %05c ", (int)'0', (int)0, (int)'1');
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %c %c %c ", (int)'1', (int)'2', (int)'3');
	printf("... %d\n", i);
	i = ft_printf(" %c %c %c ", (int)'1', (int)'2', (int)'3');
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %c %c %c ", '2', '1', 0);
	printf("... %d\n", i);
	i = ft_printf(" %c %c %c ", '2', '1', 0);
	printf("... %d\n", i);
	printf("\n");
	if (argc < 2)
		return (0);
	while (j < argc)
	{
		i = printf("%s" ,argv[j]);
		printf("... %d\n", i);
		i = ft_printf("%s", argv[j++]);
		printf("... %d", i);
		printf("\n\n");
	}
	 return (0);
 } */