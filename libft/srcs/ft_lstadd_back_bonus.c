/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:30:51 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/27 20:01:14 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tlst;

	if (!lst || !new)
		return ;
	tlst = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (tlst->next != 0)
		tlst = tlst->next;
	tlst->next = new;
	return ;
}
