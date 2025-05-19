/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:43:28 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:43:31 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	synt_error_test_3(t_bin *tr, char *s, size_t len)
{
	if (tr->type == RDIR_OUT && len > 3)
	{
		if ((s[1] == '<' && s[2] == '>') || (s[1] == '>' && s[2] == '<'
				&& s[3] == '>'))
		{
			ft_printf("minishell: syntax error near unexpected token `<>'\n");
			return (-1);
		}
		else if ((s[1] == '>' && s[2] == '<' && s[3] == '<'))
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
	return (synt_error_test_4(tr, s, len));
}

static int	synt_error_test_2(t_bin *tr, char *s, size_t len)
{
	if (tr->type == RDIR_IN && len == 3)
	{
		if (s[1] == '>' && (s[2] == '>' || s[2] == '<'))
		{
			ft_printf("minishell: syntax error near unexpected token `");
			ft_printf("%c'\n", s[2]);
			return (-1);
		}
	}
	if (tr->type == RDIR_OUT && len > 3)
	{
		if (s[1] == '<' && s[2] == '<' && s[3] == '<')
		{
			ft_printf("minishell: syntax error near unexpected token `<<<'\n");
			return (-1);
		}
		else if (s[1] == '<' && s[2] == '<' && s[3] == '>')
		{
			ft_printf("minishell: syntax error near unexpected token `<<'\n");
			return (-1);
		}
	}
	return (synt_error_test_3(tr, s, len));
}

static int	synt_error_test_1(t_bin *tr, char *s, size_t len)
{
	if (tr->type == RDIR_IN && len == 2 && tr->val[1] != NULL
		&& tr->dad != NULL)
	{
		if (s[1] == '>')
		{
			ft_printf("minishell: unsupported token error `<>'\n");
			return (-1);
		}
	}
	if (tr->type == RDIR_OUT && len == 3)
	{
		if (s[1] == '<' && s[2] == '<')
		{
			ft_printf("minishell: syntax error near unexpected token `<<'\n");
			return (-1);
		}
		else if (s[1] == '<' && s[2] == '>')
		{
			ft_printf("minishell: syntax error near unexpected token `<>'\n");
			return (-1);
		}
	}
	return (synt_error_test_2(tr, s, len));
}

static int	synt_error_test_0(t_bin *tr, char *s, size_t len)
{
	if (tr->type > RDIR_OUT)
	{
		ft_printf("minishell: unsupported instruction or token error ");
		ft_printf("`%s'\n", tr->val[0]);
		return (-1);
	}
	if (tr->type == PIP && (tr->left == NULL || (tr->right == NULL
				&& (tr->dad == NULL || (tr->dad != NULL
						&& tr->dad->type == 2))) || (tr->left != NULL
				&& tr->left->type < 5 && tr->left->type > 2
				&& tr->left->val[1] == 0)))
	{
		ft_printf("minishell: syntax error near unexpected token `|'\n");
		return (-1);
	}
	if (tr->type == RDIR_OUT && len == 2)
	{
		if (s[1] == '<')
		{
			ft_printf("minishell: syntax error near unexpected token `<'\n");
			return (-1);
		}
	}
	return (synt_error_test_1(tr, s, len));
}

int	synt_error_test(t_tab *t)
{
	t_bin	*tr;
	int		err;

	tr = *t->tree;
	err = 0;
	while (tr != NULL)
	{
		err = synt_error_test_0(tr, tr->val[0], ft_strlen(tr->val[0]));
		if (err != 0)
			return (-1);
		tr = tr->dad;
	}
	if (get_heredocs(t, (*t->tree), (*t->tree), 0) == 2)
		return (-1);
	err = error_rfile_check(t, 0, 0, 0);
	if (err != 0)
		tree_pruning(t);
	tree_reducing(t);
	return (0);
}
