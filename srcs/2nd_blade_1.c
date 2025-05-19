/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd_blade_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:41:38 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:41:49 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_1_2(char *s, int *flag, size_t *i, size_t *n)
{
	if ((*flag) == 0 && (s[(*i)] == '<' || s[(*i)] == '>'))
	{
		(*i)++;
		while (s[(*i)] == '<' || s[(*i)] == '>')
			(*i)++;
		(*n)++;
	}
}

void	loop_1_1(char *s, int *flag, size_t *i, size_t *n)
{
	int	k;

	k = 0;
	if (s[(*i)] == ';' && (*flag) == 0)
	{
		(*i)++;
		(*n)++;
	}
	else if (s[(*i)] > 47 && s[(*i)] < 58 && (*flag) == 0 && (*i) == 0)
	{
		while (s[(*i) + k] > 47 && s[(*i) + k] < 58)
			k++;
		if (s[(*i) + k] == '<' || s[(*i) + k] == '>')
		{
			k++;
			if (s[(*i) + k] == '>')
				k++;
			(*i) += k;
			(*n)++;
		}
	}
	else
		loop_1_2(s, flag, i, n);
}

int	loop_in_loop_2(char *s, size_t i, int f)
{
	if (s[i] != 0 && !((s[i] == 124 || s[i] == 60 || s[i] == 62 || s[i] == 38
				|| s[i] == 59 || s[i] == 96) && f == 0))
		return (1);
	else
		return (0);
}
