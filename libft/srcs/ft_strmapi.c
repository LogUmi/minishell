/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:28:50 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/21 18:21:12 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ns;
	unsigned int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != 0)
		i++;
	ns = (char *)malloc((i + 1) * sizeof(char));
	if (ns == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		ns[i] = f(i, s[i]);
		i++;
	}
	ns[i] = 0;
	return (ns);
}
/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	ft_getupper(unsigned int i, char c)
{
	if (i >= 0)
		c = ft_toupper(c);
	return (c);
}

static void	ft_print(char *s1)
{
	char	*s2 = ft_strmapi(s1, ft_getupper);
	
	printf("chaine: %s\n", s1);
	if(s2 != 0)
	{
		printf("Ta fonction  : %s\n\n", s2);
		free(s2);
	}
	else
		printf("Ta chaine: NULL \n\n");
}

int	main(void)
{
	ft_print("bonjour");
	ft_print(" Salut a toi !");
	ft_print("");
	return (0);
} */