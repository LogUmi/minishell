/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:20:35 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/27 14:42:35 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tlst;
	t_list	*slst;

	tlst = *lst;
	while (tlst != 0)
	{
		slst = tlst->next;
		del(tlst->content);
		free(tlst);
		tlst = slst;
	}
	*lst = 0;
	return ;
}
