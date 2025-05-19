/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:44:23 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:44:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expban(char c)
{
	int	i;

	i = 0;
	if (c == '!' || c == '#' || c == '%' || c == '&' || c == '`' || c == '$')
		i = 1;
	if (c >= '(' && c < '+')
		i = 1;
	if (c > '+' && c < '.')
		i = 1;
	if (c >= '0' && c <= '@')
		i = 1;
	if (c == '[' || (c >= ']' && c < '^'))
		i = 1;
	if (c >= '{')
		i = 1;
	return (i);
}

int	expdoll(char c)
{
	int	i;

	i = 0;
	if (c == '\'' || c == '\"')
		i = 1;
	return (i);
}

int	expvare(char c)
{
	int	i;

	i = isalnum(c);
	if (c == '_')
		i = 1;
	return (i);
}
