/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:45:25 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 15:26:53 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hrd_send_to_file_1(char *s, char *file, t_tab *t, size_t i)
{
	char	c;

	t->fd_hrd = open(file, O_RDWR | O_APPEND);
	if (t->fd_hrd == -1)
		return (-1);
	while (s[i] != 0)
	{
		while (s[i] != 0 && s[i] != '$')
			i++;
		c = s[i];
		s[i] = 0;
		write(t->fd_hrd, &s[0], ft_strlen(s));
		s[i] = c;
		if (c == '$')
			hrd_expand(s, &i, t, 0);
	}
	write(t->fd_hrd, "\n", 1);
	close(t->fd_hrd);
	t->fd_hrd = -1;
	return (0);
}

int	hrd_send_to_file_0(char *s, char *file, t_tab *t)
{
	t->fd_hrd = open(file, O_RDWR | O_APPEND);
	if (t->fd_hrd == -1)
	{
		perror("open");
		return (-1);
	}
	write(t->fd_hrd, s, ft_strlen(s));
	write(t->fd_hrd, "\n", 1);
	close(t->fd_hrd);
	t->fd_hrd = -1;
	return (0);
}

void	hrd_get_rid_file(char *file)
{
	struct stat	finfo;

	if (stat(file, &finfo) == 0)
	{
		if (unlink(file) != 0)
			ft_printf("minishell: heredoc temporary file issue\n");
	}
}

static void	treat_status(t_tab *t, int status)
{
	t->ex_status = status;
	if ((status & 0x7f) == 0)
		t->ex_status = (status >> 8) & 0xff;
	else if ((status & 0x7f) != 0 && (status & 0x7f) != 0x7f)
		t->ex_status = 128 + (status & 0x7f);
	else if ((status & 0x7f) == 0x7f)
		t->ex_status = 128 + ((status >> 8) & 0xff);
}

int	hrd_child(t_tab *t, t_bin *tr[], int status, int i)
{
	pid_t	pid;
	pid_t	pidret;

	silent_signals();
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		exit(get_heredocs_1(t, tr, 0, 0));
	}
	else
	{
		pidret = waitpid(pid, &status, 0);
		treat_status(t, status);
		if (pidret != pid)
			ft_printf ("unappropiate hrd pid returned: %d, %d", pid, pidret);
		while (tr[i] != NULL)
		{
			free(tr[i]->val[1]);
			tr[i]->val[1] = ft_strdup(t->hrdfiles[i]);
			i++;
		}
		set_signals();
	}
	return (status);
}
