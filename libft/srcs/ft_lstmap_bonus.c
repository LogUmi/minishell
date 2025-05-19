/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:27:55 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/27 19:50:55 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemap(t_list *lst, void (*del)(void *))
{
	t_list	*next_node;

	while (!lst)
	{
		next_node = lst->next;
		if (del)
			del(lst->content);
		free(lst);
		lst = next_node;
	}
	return ;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nwlst;
	t_list	*nwnod;
	t_list	*clst;

	if (!lst || !f)
		return (0);
	nwlst = ft_lstnew(f(lst->content));
	if (nwlst == 0)
		return (0);
	lst = lst->next;
	clst = nwlst;
	while (lst != 0)
	{
		nwnod = ft_lstnew(f(lst->content));
		if (nwnod == 0)
		{
			ft_freemap(nwlst, del);
			return (0);
		}
		ft_lstadd_back(&clst, nwnod);
		lst = lst->next;
	}
	return (nwlst);
}
