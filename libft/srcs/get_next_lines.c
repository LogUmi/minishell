/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:38 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/06 18:49:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static char	*ft_getinit(char *buffer, char *str, int i[], int way)
{
	char	*line;

	line = 0;
	if (way == 1)
	{
		i[0] = 0;
		i[1] = 0;
		while (i[1] < GNL_BUFFER_SIZE)
			buffer[i[1]++] = 0;
		i[1] = 0;
		while (str[i[1]] != 0)
			i[1]++;
	}
	if (way == 2)
	{
		line = &str[(GNL_STATIC_SIZE / 2) - 1];
		line = ft_strncpygnl(&str[0], line, i[0] + 1, 1);
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

char	*get_next_lines(int fd)
{
	static char	str[GNL_STATIC_SIZE] = "\0\0\0\0\0";
	char		buffer[GNL_BUFFER_SIZE];
	int			i[2];
	int			rd;

	rd = -2;
	if (fd < 0 || GNL_BUFFER_SIZE == 0 || GNL_STATIC_SIZE == 0)
		return (0);
	ft_getinit(&buffer[0], &str[0], i, 1);
	while (str[i[0]] != '\n' && rd != 0 && i[0] < (GNL_STATIC_SIZE / 2) - 1)
	{
		if (str[i[0]] == 0)
			rd = ft_readfile(fd, &buffer[0], &str[0], i);
		if (rd == -1)
			return (0);
		if (rd != 0)
			i[0]++;
	}
	if (rd == 0 && i[0] == 0 && str[i[0]] == 0)
		return (0);
	if (i[0] == (GNL_STATIC_SIZE / 2) - 1)
		return (0);
	if (str[i[0]] == 0)
		i[0]--;
	return (ft_getinit(&str[0], &str[0], i, 2));
}
/* 
int main (void)
{
	int		fd;
	char	*s;
	int		i;
	
	i = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i++ < 100)
	{
		s = get_next_lines(fd);
		if(!s)
		{
			close(fd);
			return (0);
		}
		printf("%s", s);
	}
	close(fd);
	return (0);
}
 */