/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:36:49 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/12 17:13:34 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*dup;

	i = 0;
	size = 0;
	while (s[size] != 0)
		size++;
	size++;
	dup = (char *)malloc(size * sizeof(char));
	if (dup == 0)
		return (0);
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
/* #include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>

static void	ft_print(char *s1)
{
	char	*s2;
	size_t		i = 0;
	printf("chaine: %s\n", s1);
	s2 = strdup(s1);
	printf("Fct originale: %s ... ", s2);
	if (s2 != 0)
	{
		while (s2[i] != 0)
			printf("%d ", s1[i++]);
		printf("%d", s2[i]);
		free (s2);
	}
	printf(" \n");
	s2 = ft_strdup(s1);
	printf ("Ta fonction  : %s ... ", s2);
	if (s2 != 0)
	{
		i = 0;
		while (s2[i] != 0)
			printf("%d ", s1[i++]);
		printf("%d", s2[i]);
		free (s2);
	}
	printf(" \n\n");
}

int	main(void)
{
	ft_print("abcdefghi");
	ft_print("");	
	return (0);
} */