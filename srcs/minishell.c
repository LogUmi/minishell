/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:01:39 by cgregoir          #+#    #+#             */
/*   Updated: 2025/05/15 15:01:42 by cgregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_ms_0(t_tab *t)
{
	t->hrdfiles = NULL;
	t->nlhd = 0;
	t->fd_hrd = -1;
	t->npid = 0;
	t->fpip = 0;
	t->npip = 0;
	t->ex_status = 0;
	set_signals();
}

static void	init_ms(t_tab *t, char **env)
{
	t->split = NULL;
	t->nsplit = NULL;
	t->input = NULL;
	t->prompt = NULL;
	t->temp = NULL;
	t->var = NULL;
	t->flag = NULL;
	t->env_list = NULL;
	t->exp_env = NULL;
	t->temp = NULL;
	t->var = NULL;
	t->flag = NULL;
	t->env_list = NULL;
	t->tree = NULL;
	t->hrdoc[0] = NULL;
	t->env = NULL;
	t->c = 32;
	t->c1 = 9;
	t->q1 = 39;
	t->q2 = 34;
	init_export_env(t, env);
	init_ms_0(t);
}

char	*ft_trim_start(char *str, char *set)
{
	int		i;
	int		j;
	char	*s;
	size_t	len_str;

	len_str = ft_strlen(str);
	i = 0;
	j = 0;
	while (str[i] == set[i] && str[i])
		i++;
	s = malloc(len_str - i + 1);
	while (str[i])
	{
		s[j] = str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*ft_prompt(t_lst *env_list)
{
	char	*prompt;
	char	*user;
	char	*dir;
	char	*tdir;
	char	*home;

	home = ft_getenv(env_list, "HOME=");
	if (!home)
		home = ft_strdup("..");
	user = ft_getenv(env_list, "USER=");
	if (!user)
		user = ft_strdup("..");
	dir = ft_getenv(env_list, "PWD=");
	if (!dir)
		dir = ft_strdup("..");
	tdir = ft_trim_start(dir, home);
	prompt = ft_strdup(user);
	prompt = ft_strjoin(prompt, ":~");
	prompt = ft_strjoin(prompt, tdir);
	prompt = ft_strjoin(prompt, "$ ");
	prompt = add_prompt_color(prompt);
	return (free(dir), free(home), free(user), free(tdir), prompt);
}

int	main(int argc, char **argv, char **env)
{
	t_tab	t;

	(void) argc;
	(void) argv;
	init_ms(&t, env);
	set_shlvl(&t);
	init_tab_env(&t, 0, 0, 0);
	ft_init_history(&t, NULL, 0, 0);
	main_loop(&t);
	ft_close_history(&t);
	exit_check(&t, "exit", 0);
	return (0);
}
