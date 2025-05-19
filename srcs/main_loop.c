/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:02:15 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 15:02:17 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_loop(t_tab *t)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		t->prompt = ft_prompt(t->env_list);
		t->input = readline(t->prompt);
		if (!t->input)
			i = 1;
		else
		{
			if (*t->input)
			{
				i = get_cmde(t);
			}
			free(t->input);
		}
		free(t->prompt);
		t->prompt = 0;
	}
}

void	init_export_env(t_tab *t, char **env)
{
	t_lst	*env_list;

	env_list = NULL;
	init_env(&env_list, env);
	t->env_list = env_list;
	init_export_list(t);
}

char	*add_prompt_color(char *prompt)
{
	char	*color_init;
	char	*color_reset;
	char	*tmp;

	color_init = ft_strdup("\001\033[36m\002");
	color_reset = ft_strdup("\001\033[0m\002");
	tmp = ft_strjoin(color_init, prompt);
	free(prompt);
	prompt = ft_strjoin(tmp, color_reset);
	free(color_reset);
	return (prompt);
}
