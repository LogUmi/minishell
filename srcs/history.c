/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:46:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/16 18:04:15 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	*name_history(t_tab *t)
{
	char	*filename;
	char	*shlvl;

	filename = ft_strdup("history_");
	shlvl = ft_getenv(t->env_list, "SHLVL=");
	filename = ft_strjoin(filename, shlvl);
	free(shlvl);
	ft_strlcpy(&t->file_h[0], filename, ft_strlen(filename) + 1);
	free(filename);
	return (0);
}

void	ft_init_history(t_tab *t, char *s, int i, int j)
{
	name_history(t);
	t->fd_history = open(&t->file_h[0], O_RDWR | O_CREAT | O_APPEND, 0666);
	if (t->fd_history == -1)
		return ;
	while (i == 0)
	{
		s = get_next_lines(t->fd_history);
		if (!s)
			i = 1;
		else
		{
			j = 0;
			while (s[j] != '\n')
				j++;
			s[j] = 0;
			add_history(s);
		}
	}
	close(t->fd_history);
	t->fd_history = -1;
}

void	ft_close_history(t_tab *t)
{
	if (t->fd_history != -1)
		close(t->fd_history);
	t->fd_history = -1;
}

void	ft_write_history(t_tab *t)
{
	add_history(t->input);
	if (t->fd_history == -1)
	{
		t->fd_history = open(&t->file_h[0], O_RDWR | O_CREAT | O_APPEND, 0666);
		if (t->fd_history == -1)
			return ;
	}
	write(t->fd_history, t->input, ft_strlen(t->input));
	write(t->fd_history, "\n", 1);
	close(t->fd_history);
	t->nlhd++;
	t->fd_history = -1;
}
