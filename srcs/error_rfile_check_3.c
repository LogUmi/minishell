/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_rfile_check_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:42:40 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:42:43 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err_file(t_tab *t)
{
	int	i;

	i = 0;
	if (t->nsplit != NULL)
	{
		while (t->nsplit[i] != 0 && i < 255)
			i++;
		while (i > 0)
			ft_printf("%s", t->nsplit[--i]);
		magic_split_free(t->nsplit, -1);
		t->nsplit = NULL;
	}
}

int	prt_errf(char *s, char *msg, int flag, t_tab *t)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s) + ft_strlen(msg) + 16;
	if (flag != 1)
	{
		if (t->nsplit == NULL)
		{
			t->nsplit = ft_calloc(256, sizeof(char *));
			if (!t->nsplit)
				return (1);
		}
		while (t->nsplit[i] != 0 && i < 255)
			i++;
		t->nsplit[i] = ft_calloc(len, sizeof(char));
		ft_strlcat(t->nsplit[i], "minishell: ", 12);
		ft_strlcat(t->nsplit[i], s, ft_strlen(s) + 12);
		ft_strlcat(t->nsplit[i], ": ", ft_strlen(s) + 14);
		ft_strlcat(t->nsplit[i], msg, ft_strlen(s) + ft_strlen(msg) + 14);
		ft_strlcat(t->nsplit[i], "\n", ft_strlen(s) + ft_strlen(msg) + 15);
		t->nsplit[i + 1] = 0;
	}
	return (1);
}

int	set_err_rdir(t_bin *tr)
{
	tr->type = -1;
	return (1);
}

void	do_redir_out(t_bin *tr)
{
	int	fd;

	fd = 0;
	while (tr != NULL && tr->type != PIP)
	{
		if (tr->type == RDIR_OUT)
		{
			fd = open(tr->val[1], O_RDWR | O_CREAT | O_APPEND, 0666);
			close(fd);
		}
		tr = tr->dad;
	}
}

int	filename_size(t_bin *tr)
{
	char	**filenames;
	int		i;
	int		err;

	i = 0;
	err = 0;
	if (ft_strlen(tr->val[0]) > 1 && tr->val[0][0] == '<'
			&& tr->val[0][1] == '<')
		return (0);
	if (ft_strlen(tr->val[1]) > 4064)
		return (1);
	filenames = ft_split(tr->val[1], '/');
	if (!filenames)
		return (0);
	while (filenames[i] != 0)
	{
		if (ft_strlen(filenames[i++]) > 255)
			err = 1;
	}
	magic_split_free(filenames, -1);
	return (err);
}
