/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:04:23 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/21 11:48:15 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	handle_signal(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exec_ret = 1;
	}
	else if (signum == SIGQUIT)
	{
		write(1, "Quit: 3", 7);
	}
}

static	void	setup_signal_handler(int signum)
{
	struct sigaction	signal_action;

	ft_memset(&signal_action, 0, sizeof(struct sigaction));
	memset(&signal_action, 0, sizeof(struct sigaction));
	signal_action.sa_handler = handle_signal;
	sigaction(signum, &signal_action, NULL);
}

void	setup_sigquit_signal(void)
{
	setup_signal_handler(SIGQUIT);
}

void	setup_parent_signals(void)
{
	setup_signal_handler(SIGINT);
	signal(SIGQUIT, SIG_IGN);
}
