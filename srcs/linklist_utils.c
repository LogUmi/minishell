/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:57:08 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 14:57:11 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*ft_listnew(char *content)
{
	t_lst	*nc;

	nc = malloc(sizeof(t_lst));
	if (nc == 0)
		return (0);
	nc->content = ft_strdup(content);
	nc->next = 0;
	return (nc);
}

t_lst	*ft_lst_back(t_lst **lst, t_lst *new)
{
	t_lst	*tlst;

	if (!lst || !new)
		return (NULL);
	tlst = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return (new);
	}
	while (tlst->next != 0)
		tlst = tlst->next;
	tlst->next = new;
	return (new);
}

void	print_list(t_lst *list)
{
	while (list)
	{
		ft_printf("%s\n", ((char *)list->content));
		list = list->next;
	}
	return ;
}

void	free_list(t_lst **list)
{
	t_lst	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
}

void	free_node(t_lst *list)
{
	free(list->content);
	free(list);
}
