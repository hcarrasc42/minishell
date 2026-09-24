/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:06:42 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:16:55 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_array(char **array)
{
	int	count;

	count = 0;
	while (array && array[count])
	{
		printf("%s\n", array[count]);
		count++;
	}
}

static char	**heredoc_get_lines(t_list	*redirections)
{
	char			*line;
	char			**lines;
	t_redirection	*redirection;

	lines = NULL;
	redirection = get_redirection(redirections);
	line = readline("");
	while (line
		&& ft_strncmp(line, redirection->file, ft_strlen(redirection->file)))
	{
		if (ft_strlen(line))
		{
			lines = add_str_to_array(lines, line);
		}
		free(line);
		line = readline("");
	}
	if (line)
		free(line);
	return (lines);
}

static void	apply_heredoc_redirection(t_list *redirections, t_mini *state)
{
	pid_t			pid;
	int				fd[2];
	char			**lines;

	lines = heredoc_get_lines(redirections);
	if (pipe(fd) == -1)
		exit_with_error(state, "Error calling pipe()");
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		close(fd[FD_IN]);
		dup2(fd[FD_OUT], STDOUT_FILENO);
		close(fd[FD_OUT]);
		display_array(lines);
		free_array(lines);
		exit_without_error(state);
	}
	free_array(lines);
	close(fd[FD_OUT]);
	dup2(fd[FD_IN], STDIN_FILENO);
	close(fd[FD_IN]);
}

static int	get_open_flags(t_redirection *redirection)
{
	if (!redirection)
		return (O_RDONLY);
	if (redirection->type == TOKEN_GREAT)
		return (O_CREAT | O_WRONLY | O_TRUNC);
	if (redirection->type == TOKEN_GREATGREAT)
		return (O_CREAT | O_WRONLY | O_APPEND);
	if (redirection->type == TOKEN_LESS)
		return (O_RDONLY);
	if (redirection->type == TOKEN_LESSLESS)
		return (O_RDONLY);
	return (O_RDONLY);
}

void	apply_redirections(t_list *redirections, t_mini *state)
{
	t_redirection	*redirection;

	while (redirections)
	{
		redirection = get_redirection(redirections);
		if (redirection->type == TOKEN_LESSLESS)
			apply_heredoc_redirection(redirections, state);
		else
		{
			redirection->fd = open(redirection->file,
					get_open_flags(redirection),
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			if (redirection->type == TOKEN_GREAT
				|| redirection->type == TOKEN_GREATGREAT)
				dup2(redirection->fd, STDOUT_FILENO);
			else if (redirection->type == TOKEN_LESS)
				dup2(redirection->fd, STDIN_FILENO);
			close(redirection->fd);
		}
		redirections = redirections->next;
	}
}
