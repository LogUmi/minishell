/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_test_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:43:12 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:43:16 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	synt_error_test_7(t_bin *tr, char *s, size_t len)
{
	(void)s;
	(void)len;
	if ((tr->type == RDIR_OUT || tr->type == RDIR_IN) && tr->dad == NULL
		&& tr->val[1] == NULL)
	{
		ft_printf("minishell: syntax error near unexpected token `newline'\n");
		return (-1);
	}
	return (0);
}

static int	synt_error_test_6(t_bin *tr, char *s, size_t len)
{
	if (tr->type == RDIR_IN && len > 0)
	{
		if (check_in_redir(s, 0, 3, len) != 0)
			return (-1);
		else if (tr->val == NULL && tr->dad != NULL
			&& (tr->dad->type == RDIR_OUT || tr->dad->type == RDIR_IN))
		{
			check_next_redir(tr->dad->val[0], 0, 0, 0);
			return (-1);
		}
		if (len == 3 && s[0] == '<' && s[1] == '<' && s[2] == '<')
		{
			ft_printf("minishell: unsupported token error `<<<'\n");
			return (-1);
		}
	}
	return (synt_error_test_7(tr, s, len));
}

static int	synt_error_test_5(t_bin *tr, char *s, size_t len)
{
	if (tr->type == RDIR_IN && len > 4)
	{
		if (s[1] == '>' && s[2] == '<' && s[3] == '<' && s[4] == '<')
		{
			ft_printf("minishell: syntax error near unexpected token `<<<'\n");
			return (-1);
		}
	}
	if (tr->type == RDIR_OUT && len > 0)
	{
		if (check_in_redir(s, 0, 2, len) != 0)
			return (-1);
		else if (tr->val[1] == NULL && tr->dad != NULL
			&& (tr->dad->type == RDIR_OUT || tr->dad->type == RDIR_IN))
		{
			check_next_redir(tr->dad->val[0], 0, 0, 0);
			return (-1);
		}
	}
	return (synt_error_test_6(tr, s, len));
}

int	synt_error_test_4(t_bin *tr, char *s, size_t len)
{
	if (tr->type == RDIR_IN && len == 4)
	{
		if (s[1] == '>' && s[2] == '<' && s[3] == '>')
		{
			ft_printf("minishell: syntax error near unexpected token `<>'\n");
			return (-1);
		}
		else if ((s[1] == '>' && s[2] == '<' && s[3] == '<' ))
		{
			ft_printf("minishell: syntax error near unexpected token `<<'\n");
			return (-1);
		}
		else if ((s[1] == '>' && s[2] == '>' && s[3] == '<'))
		{
			ft_printf("minishell: syntax error near unexpected token `>'\n");
			return (-1);
		}
		else if ((s[1] == '>' && s[2] == '>' && s[3] == '>'))
		{
			ft_printf("minishell: syntax error near unexpected token `>>'\n");
			return (-1);
		}
	}
	return (synt_error_test_5(tr, s, len));
}
