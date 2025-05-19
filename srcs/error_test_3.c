/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_test_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:43:20 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:43:24 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_in_redir(char *s, size_t i, size_t j, size_t len)
{
	int		k;
	char	c;

	k = j;
	c = s[0];
	if (s[0] == '<' && s[1] == '>')
		return (0);
	while (s[i] != 0 && s[i] == c && j-- != 0)
		i++;
	if (i != len)
	{
		j = k;
		c = s[i];
		ft_printf("minishell: syntax error near unexpected token `");
		while (s[i] != 0 && s[i] == c && j-- != 0)
			ft_printf("%c", s[i++]);
		ft_printf("'\n");
		return (-1);
	}
	return (0);
}

void	check_next_redir(char *s, size_t i, size_t j, size_t len)
{
	char	c;

	while (s[len] != 0)
		len++;
	if (len > 1 && s[0] == '<' && s[1] == '>')
	{
		ft_printf("minishell: syntax error near unexpected token `<>'\n");
		return ;
	}
	c = s[0];
	j = 2;
	if (c == '<')
		j = 3;
	ft_printf("minishell: syntax error near unexpected token `");
	while (s[i] != 0 && s[i] == c && j-- != 0)
		ft_printf("%c", s[i++]);
	ft_printf("'\n");
}
