/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:57 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/27 16:17:20 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nc;

	nc = malloc(sizeof(t_list));
	if (nc == 0)
		return (0);
	nc->content = content;
	nc->next = 0;
	return (nc);
}
/* 
#include <stdio.h>
#include <ctype.h>

static void	ft_print(void s1)
{
	printf("chaine 1: %s ... chaine 2: %s\n", s1, s2);
	s3 = ft_strjoin(s1, s2);
	printf("chaine retour: %s ... pointeur: %p\n\n", s3, &s3);
	if (s3 != 0)
		free (s3);
}
int	main(void)
{
	tlist	*s;
	
	s = ft_lstnew(0123456);
	
	ft_print("", "789");
	ft_print("0123456", "");
	ft_print("", "");
	return (0);
} */
