/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:47:36 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/27 19:35:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

static void	ft_getupper(unsigned int i, char *c)
{
	if (i >= 0)
    	*c = ft_toupper(*c);
}

static void	ft_print(char *s1)
{
	char 	*s2;
	int		i = 0;
	
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while(s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	printf("chaine: %s\n", s1);
	ft_striteri(s2, ft_getupper);
	if (s2 != 0)
	{
		printf("Ta fonction: %s\n\n", s2);
		free(s2);
	}
	else
		printf("Ta fonction: NULL\n\n");
}

int	main(void)
{
	ft_print("bonjour");
	ft_print(" Salut a toi !");
	ft_print("");
	return (0);
}*/