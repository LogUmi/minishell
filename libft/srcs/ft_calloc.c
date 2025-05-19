/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:14:12 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/12 16:28:43 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*memarea;

	i = 0;
	memarea = (char *)malloc(nmemb * size * sizeof(char));
	if (memarea == 0)
		return (0);
	while (i < (nmemb * size * sizeof(char)))
		memarea[i++] = 0;
	return ((void *)memarea);
}
/* #include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>

static void	ft_print(size_t n, size_t size)
{
	char	*s1;
	size_t		i = 0;
	printf("nb membres: %zu ... taille : %zu\n", n, size);
	s1 =(char *)calloc(n, size);
	printf("Fct originale: %p ... ", s1);
	if (s1 != 0)
	{
		while (i < (n * size))
			printf("%d ", s1[i++]);
		free (s1);
	}
	printf(" \n");
	s1 = (char *) ft_calloc(n, size);
	printf ("Ta fonction  : %p ... ", s1);
	if (s1 != 0)
	{
		i = 0;
		while (i < (n * size))
			printf("%d ", s1[i++]);
		free (s1);
	}
	printf(" \n\n");
	}

int	main(void)
{
	ft_print(10, 1);
	ft_print(-1, 1000);
	ft_print(0, 1);
	ft_print(10, 0);
	ft_print(0, 0);
	ft_print(1, 20);
	return (0);
} */