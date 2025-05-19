/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:55:31 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 14:55:40 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_plus_sign(char	*str)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	i = 1;
	j = 0;
	if (str[0] == '+')
	{
		len = ft_strlen(str);
		new = malloc(sizeof(char) * len);
		while (str[i])
		{
			new[j] = str[i];
			i++;
			j++;
		}
		new[j] = '\0';
		free(str);
		str = new;
		return (new);
	}
	return (str);
}
