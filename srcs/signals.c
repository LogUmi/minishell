/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:48:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:48:58 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sign = 0;

void	ctrl_c(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	write (1, "\n", 1);
	g_sign = SIGINT;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	unset_signals(void)
{
	struct sigaction	sa;
	struct sigaction	sb;

	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sb.sa_handler = SIG_DFL;
	sigemptyset(&sb.sa_mask);
	sb.sa_flags = 0;
	sigaction(SIGQUIT, &sb, NULL);
}

void	silent_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
}

void	set_signals(void)
{
	struct sigaction	sa;
	struct sigaction	sb;

	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = ctrl_c;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sb.sa_flags = 0;
	sb.sa_handler = SIG_IGN;
	sigemptyset(&sb.sa_mask);
	sigaction(SIGQUIT, &sb, NULL);
}
