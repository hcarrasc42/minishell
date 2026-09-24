/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:57:42 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:10:30 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parent_pipe(t_list *cmds)
{
	t_simple_cmd	*cmd;
	t_simple_cmd	*next_cmd;

	cmd = get_cmd(cmds);
	next_cmd = get_cmd(cmds->next);
	if (next_cmd)
	{
		next_cmd->fd_in = cmd->pipe_fds[FD_IN];
		close(cmd->pipe_fds[FD_OUT]);
	}
}

static int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		perror("Error");
	return (pid);
}

void	create_pipe(t_list *cmds, t_mini *state)
{
	t_simple_cmd	*cmd;

	cmd = get_cmd(cmds);
	if (get_cmd(cmds->next))
	{
		if (pipe(cmd->pipe_fds) == -1)
			exit_with_error(state, "Error calling pipe()");
		cmd->fd_out = cmd->pipe_fds[FD_OUT];
	}
}

void	wait_for_child(pid_t pid)
{
	int				status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	setup_sigquit_signal();
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		g_exec_ret = 128 + WTERMSIG(status);
	else
		g_exec_ret = WEXITSTATUS(status);
	setup_parent_signals();
}

void	exec_cmd(t_list *cmds, t_mini *state)
{
	t_simple_cmd	*cmd;

	cmd = get_cmd(cmds);
	create_pipe(cmds, state);
	if (is_parent_builtin(cmd->builtin_type))
	{
		parent_pipe(cmds);
		g_exec_ret = run_builtin(cmds, state);
	}
	else
	{
		cmd->pid = ft_fork();
		if (cmd->pid == 0)
			child_pipe(cmds, state);
		else
		{
			parent_pipe(cmds);
			wait_for_child(cmd->pid);
		}
	}
}
