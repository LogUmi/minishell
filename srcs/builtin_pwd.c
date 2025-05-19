/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:56:51 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 14:56:53 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(void)
{
	char	cwd[PATH_MAX];

	if (!getcwd(cwd, PATH_MAX))
		return (1);
	ft_putendl_fd(cwd, 1);
	return (0);
}
