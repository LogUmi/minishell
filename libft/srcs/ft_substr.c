/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:24:02 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/29 12:00:54 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ns;

	i = 0;
	j = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ns = (char *)malloc((len + 1) * sizeof(char));
	if (ns == 0)
		return (0);
	while (s[j] != 0)
		j++;
	if (start < j)
		j = start;
	while (i < len && s[i + j] != 0)
	{
		ns[i] = s[i + start];
		i++;
	}
	while (i <= len)
		ns[i++] = 0;
	return (ns);
}
/* #include <stdio.h>
#include <ctype.h>

static void	ft_print(char *s1, unsigned int start, size_t len)
{
	size_t		i = 0;
	char		*s2 = "";
	printf("chaine: %s ... start: %u ... lengh: %zu\n", s1, start, len);
	s2 = ft_substr(s1, start, len);
	printf("chaine retour: %s ... pointeur: %p ...", s2, &s2);
	if (s2 != 0)
	{
		while (i < len)
			printf("%d ", s2[i++]);
		printf("%d", s2[i]);
		free (s2);
	}
	printf(" \n\n");
}

int	main(void)
{
	ft_print("01234", 10, 10);
	ft_print("abc0123456", 3, 4);
	ft_print("", 3, 4);
	ft_print("abc0123456", 0, 4);
	ft_print("abc0123456", 0, 0);
	ft_print("abc0123", 3, 10);
	return (0);
} */