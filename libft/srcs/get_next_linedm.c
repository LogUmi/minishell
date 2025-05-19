/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:38 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/30 15:27:33 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static char	*ft_getinit(char *buffer, char *str, int *k, int way)
{
	char	*line;

	line = 0;
	if (way == 1)
	{
		while ((*k) < GNL_BUFFER_SIZE)
			buffer[(*k)++] = 0;
		(*k) = 0;
		while (str[(*k)] != 0)
			(*k)++;
	}
	if (way == 2)
	{
		line = malloc(((*k) + 2) * sizeof(char));
		if (!line)
			return (0);
		line = ft_strncpygnl(&str[0], line, (*k) + 1, 1);
	}
	if (way == 0)
		while (way < GNL_STATIC_SIZE)
			str[way++] = 0;
	return (line);
}

static int	ft_readfile(int fd, char *buffer, char *str, int i[])
{
	int	rd;

	rd = read(fd, buffer, GNL_BUFFER_SIZE);
	if (rd < 0)
	{
		ft_getinit(str, str, &i[0], 0);
		return (-1);
	}
	if (rd != 0)
	{
		ft_strncpygnl(buffer, &str[i[0]], rd, 0);
		i[0] = i[1] - 1;
		i[1] += rd;
	}
	return (rd);
}

char	*get_next_linedm(int fd)
{
	static char	str[1025][GNL_STATIC_SIZE] = {{'\0'}};
	char		buffer[GNL_BUFFER_SIZE];
	int			i[2];
	int			rd;

	i[0] = 0;
	i[1] = 0;
	rd = -2;
	if (fd < 0 || GNL_BUFFER_SIZE == 0 || GNL_STATIC_SIZE == 0 || fd > 1025)
		return (0);
	ft_getinit(&buffer[0], &str[fd][0], &i[1], 1);
	while (str[fd][i[0]] != '\n' && rd != 0)
	{
		if (str[fd][i[0]] == 0)
			rd = ft_readfile(fd, &buffer[0], &str[fd][0], i);
		if (rd == -1)
			return (0);
		if (rd != 0)
			i[0]++;
	}
	if (rd == 0 && i[0] == 0 && str[fd][i[0]] == 0)
		return (0);
	if (str[fd][i[0]] == 0)
		i[0]--;
	return (ft_getinit(&str[fd][0], &str[fd][0], &i[0], 2));
}
/* 
int main (void)
{
	int		fd;
	char	*s;
	int		i;
	
	i = 0;
	fd = open("one_line_no_nl.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i++ < 100)
	{
		s = get_next_line(fd);
		if(!s)
		{
			close(fd);
			return (0);
		}
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
} */
