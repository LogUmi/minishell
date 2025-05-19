/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:48:35 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/16 16:33:57 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_stroccur(char const *s1, char const *set, int way, int pos)
{
	int	i;
	int	j;

	i = pos;
	j = 0;
	if (i > -1 && s1[i] != 0)
	{
		while (set[j] != 0)
		{
			if (s1[i] == set[j++])
				return (ft_stroccur(s1, set, way, pos + way) + 1);
		}
	}
	return (0);
}

static int	ft_strtrim_cor(int len, int i, int j)
{
	if ((i + j) >= len)
		return (1);
	else
		return (len - i - j + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*ns;

	i = 0;
	j = 0;
	len = 0;
	while (s1[len] != 0)
		len++;
	i = ft_stroccur(s1, set, 1, 0);
	j = ft_stroccur(s1, set, -1, len - 1);
	ns = (char *)malloc(ft_strtrim_cor(len, i, j) * sizeof(char));
	if (ns == 0)
		return (0);
	len = len - j;
	j = 0;
	while (i < len)
	{
		ns[j] = s1[i];
		j++;
		i++;
	}
	ns[j] = 0;
	return (ns);
}

/* #include <stdio.h>
#include <ctype.h>

static void	ft_print(char *s1, char *set)
{
	char		*s2 = "";
	printf("chaine: %s ... set: %s\n", s1, set);
	s2 = ft_strtrim(s1, set);
	printf("chaine retour: %s ... pointeur: %p ...", s2, &s2);
	if (s2 != 0)
		free (s2);
	printf(" \n\n");
}

int	main(void)
{
	ft_print(" /0123456789 /"," /");
	ft_print("", " /");
	ft_print(" /0123456789 /","");
	ft_print("", "");
	ft_print("**:abc:**","*:");
	ft_print("***", "*");
	return (0);
} */