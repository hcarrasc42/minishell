/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msh_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:10:54 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/03/02 14:20:14 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	ft_file_open(t_pipex *p)
{
	p->infi = ft_file_finder(p, p->spl, 0);
	if (p->infi && p->max == 1)
		p->fdin = open(p->infi, O_RDONLY);
	if (p->infi && p->max > 1)
	{
		ft_here_doc(p->infi);
		p->fdin = open("tmp.txt", O_RDONLY);
		unlink("tmp.txt");
	}
	p->outfi = ft_file_finder(p, p->spl, 1);
	if (p->outfi && p->min == 1)
		p->fdout = open(p->outfi, O_WRONLY | O_TRUNC
				| O_CREAT, 0777);
	if (p->outfi && p->min > 1)
		p->fdout = open(p->outfi, O_WRONLY | O_APPEND
				| O_CREAT, 0777);
	if (p->infi)
		free(p->infi);
	if (p->outfi)
		free(p->outfi);
}

void	ft_close(t_pipex *p, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		close(p->fd[i][0]);
		close(p->fd[i][1]);
		i++;
	}
}

void	ft_exceve(t_pipex *p, char **spl, int i, char **env)
{
	char	*path;
	char	**cmd;

	cmd = ft_strremover(spl);
	path = get_path(cmd[0], env);
	if (i != 0)
		dup2(p->fd[i - 1][0], STDIN);
	if (i != p->len)
		dup2(p->fd[i][1], STDOUT);
	ft_close(p, p->len);
	execve(path, cmd, env);
	ft_print_exit("command not found");
}

int	ft_msh_pipex(t_pipex *p, char **env)
{
	int		i;
	int		tmp[2];

	i = 0;
	tmp[0] = dup(STDIN);
	tmp[1] = dup(STDOUT);
	ft_file_open(p);
	if (p->fdin > 0)
		dup2(p->fdin, STDIN);
	if (p->fdout > 0)
		dup2(p->fdout, STDOUT);
	while (i < p->len + 1)
	{
		p->pid = fork();
		if (p->pid == 0)
			ft_exceve(p, p->spl[i], i, env);
		ft_close(p, i);
		waitpid(p->pid, NULL, 0);
		i++;
	}
	dup2(tmp[0], STDIN);
	dup2(tmp[1], STDOUT);
	return (0);
}

void	ft_genereal(t_pipex *p, char **env)
{
	int	i;

	i = 0;
	p->len = ft_triplen(p->spl);
	p->fd = (int **)malloc(sizeof(int *) * p->len);
	while (i < p->len)
	{
		p->fd[i] = (int *)malloc(sizeof(int) * 2);
		pipe(p->fd[i]);
		i++;
	}
	ft_msh_pipex(p, env);
}
