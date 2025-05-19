/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:25:36 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/23 15:24:47 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	**ft_splitfree(char **ns, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(ns[i++]);
	free(ns);
	return (0);
}

static size_t	ft_nbwords(char const *s, char c, size_t i, size_t n)
{
	while ((unsigned char)s[i] != 0)
	{
		while ((unsigned char)s[i] != 0 && (unsigned char)s[i] == c)
			i++;
		while ((unsigned char)s[i] != 0 && (unsigned char)s[i] != c)
			i++;
		if ((unsigned char)s[i - 1] != c)
			n++;
	}
	return (n);
}

static char	**ft_strextr(char **ns, char const *s, char c, size_t j)
{
	size_t	i;
	size_t	len;

	i = 0;
	while ((unsigned char)s[i] != 0)
	{
		while ((unsigned char)s[i] != 0 && (unsigned char)s[i] == c)
			i++;
		len = 0;
		while ((unsigned char)s[i] != 0 && (unsigned char)s[i] != c)
		{
			len++;
			i++;
		}
		if ((unsigned char)s[i - 1] != c)
		{
			ns[j] = ft_substr(s, i - len, len);
			if (ns[j] == 0)
				return (ft_splitfree(ns, j));
			j++;
		}
	}
	ns[j] = 0;
	return (ns);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**ns;

	if (s == 0)
		return (0);
	j = ft_nbwords(s, c, 0, 0);
	ns = (char **)malloc((j + 1) * sizeof(char *));
	if (ns == 0)
		return (0);
	if (ft_strextr(ns, s, c, 0) == 0)
		return (0);
	return (ns);
}
/* 
#include <stdio.h>
#include <ctype.h>

static void	ft_print(char *s1, char c)
{
	char	**s2;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	printf("chaine: %s ... carac: %c\n", s1, c);
	s2 = ft_split(s1, c);
	if (s2)
	{
		printf("pointeur: %p\n", &s2);
		while (s2[i]!= 0)
		{
			printf("chaine retour: %s ... pointeur: %p ... ", s2[i], &s2[i]);	
			j = 0;
			while (s2[i][j] != 0)
				printf("%d ",s2[i][j++]);
			printf("\n");
			i++;
		}
		ft_splitfree(s2, i);
		printf(" \n\n");
	}
	else
		printf("pointeur: NULL\n\n");
}

int	main(void)
{
	int i = 0;
	
	i = ft_nbwords("aa\0bbb",'\0', 0, 0);
	i = ft_nbwords("/01234/56789/",'/', 0, 0);
	i = ft_nbwords("/01234/56789",'/', 0, 0);
	i = ft_nbwords("0/1234/56789",'/', 0, 0);
	i = ft_nbwords("", '/', 0, 0);
	i = ft_nbwords("/0123456789/",0, 0, 0);
	i = ft_nbwords("", 0, 0, 0);
	i = ft_nbwords("**abc:**",'*', 0, 0);
	i = ft_nbwords("***",'*', 0, 0);
	i = ft_nbwords("**6***6*", '*', 0, 0);
	ft_print("aa\0bbb",'\0');
	ft_print("/01234/56789/",'/');
	ft_print("/01234/56789",'/');
	ft_print("0/1234/56789",'/');
	ft_print("", '/');
	ft_print("/0123456789/",0);
	ft_print("", 0);
	ft_print("**abc:**",'*');
	ft_print("***", '*');
	return (0);
} 
  */