/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:10:08 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/13 16:38:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strjoin_len(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ns;

	i = 0;
	j = ft_strjoin_len((char *)s1, (char *)s2);
	ns = (char *)malloc((j + 1) * sizeof(char));
	if (ns == 0)
		return (0);
	while (s1[i] != 0)
	{
		ns[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ns[i] = s2[j];
		i++;
		j++;
	}
	ns[i] = 0;
	free((char *)s1);
	return (ns);
}
/* #include <stdio.h>
#include <ctype.h>

static void	ft_print(char *s1, char *s2)
{
	char	*s3;
	printf("chaine 1: %s ... chaine 2: %s\n", s1, s2);
	s3 = ft_strjoin(s1, s2);
	printf("chaine retour: %s ... pointeur: %p\n\n", s3, &s3);
	if (s3 != 0)
		free (s3);
}
int	main(void)
{
	ft_print("0123456","789" );
	ft_print("", "789");
	ft_print("0123456", "");
	ft_print("", "");
	return (0);
} */
