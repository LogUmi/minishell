/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:45:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 11:44:00 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	hrd_is_eof(char *s, char *ef)
{
	int	i;
	int	c;
	int	retv;

	i = 0;
	retv = 1;
	if (ft_strlen(s) == 0)
		return (1);
	while (s[i] != 0)
		i++;
	c = s[i - 1];
	if (c == '\n')
		s[i - 1] = 0;
	if (ft_strlen(s) == ft_strlen(ef) && ft_strcmp(s, ef) == 0)
		retv = 0;
	s[i - 1] = c;
	return (retv);
}

static int	get_heredocs_2(t_tab *t, t_bin *tr[], size_t i, int *expd)
{
	char	*new_input;
	int		retv;

	retv = 0;
	new_input = readline("> ");
	if (!new_input)
	{
		ctrl_d_hrd(t, tr[i]);
		(*expd) = -1;
		return (-1);
	}
	if (hrd_is_eof(new_input, tr[i]->val[1]) != 0)
	{
		if ((*expd) == 0)
			hrd_send_to_file_0(new_input, t->hrdfiles[i], t);
		else
			hrd_send_to_file_1(new_input, t->hrdfiles[i], t, 0);
	}
	else
		retv = 1;
	free(new_input);
	return (retv);
}

int	get_heredocs_1(t_tab *t, t_bin *tr[], size_t i, int expd)
{
	int	j;

	j = 0;
	while (tr[i] != NULL)
	{
		hrd_ignore_bs(tr[i]->val, t);
		expd = hrd_is_quote(tr[i]->val[1]);
		hrd_sup_quotes(tr[i]->val, t);
		while (get_heredocs_2(t, tr, i, &expd) == 0)
			j++;
		if (expd == -1)
		{
			while (tr[i] != NULL)
				i++;
		}
		else
			i++;
	}
	j = 0;
	return (j);
}

static int	get_heredocs_0(t_tab *t, t_bin *tr[], int nfhd, int fd)
{
	size_t	i;
	char	*num;

	i = 0;
	t->hrdfiles = ft_calloc(nfhd + 1, sizeof(char *));
	if (!t->hrdfiles)
		return (1);
	while (tr[i] != NULL)
	{
		t->hrdfiles[i] = ft_strdup("heredoc_");
		num = ft_itoa(i);
		t->hrdfiles[i] = ft_strjoin(t->hrdfiles[i], num);
		t->hrdfiles[i] = ft_strjoin(t->hrdfiles[i], ".tmp");
		t->hrdfiles[i + 1] = NULL;
		free(num);
		hrd_get_rid_file(t->hrdfiles[i]);
		fd = open(t->hrdfiles[i], O_RDWR | O_CREAT | O_APPEND, 0666);
		if (fd == -1)
			return (1);
		close(fd);
		i++;
	}
	return (hrd_child(t, tr, 0, 0));
}

int	get_heredocs(t_tab *t, t_bin *palier, t_bin *tr, size_t i)
{
	while (tr != NULL)
	{
		while (palier->dad != NULL && palier->type != PIP)
			palier = palier->dad;
		palier = palier->dad;
		while (tr != NULL && tr->type != PIP)
		{
			if (tr->type == RDIR_IN && ft_strlen(tr->val[0]) > 1
				&& tr->val[0][0] == '<' && tr->val[0][1] == '<')
			{
				t->hrdoc[i] = tr;
				i++;
			}
			tr = tr->dad;
		}
		tr = palier;
	}
	t->hrdoc[i] = NULL;
	if (i == 0)
		return (0);
	else
		return (get_heredocs_0(t, t->hrdoc, i, 0));
}
