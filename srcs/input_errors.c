/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:58:17 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/16 16:25:14 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_nf(char *argv)
{
	ft_printf("minishell: ");
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	file_error(char *file)
{
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

void	synthax_error(void)
{
	ft_putstr_fd("minishell: synthax error", 2);
	return ;
}
