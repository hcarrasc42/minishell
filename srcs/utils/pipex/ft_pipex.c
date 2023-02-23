/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:24:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/23 12:47:40 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

void	exec(t_bonus bonus, char **cmd, char **env)
{
	char	*path;

	bonus.fd[0] = 0;
/* 	pipe(bonus.fd);
	dup2(bonus.fd[0], STDIN);
	dup2(bonus.fd[1], STDOUT); */
	if (cmd[0][0] == '/')
		path = cmd[0];
	else
		path = get_path(cmd[0], env);
	//execve(path, "ls", env);
	exit(1);
}

/* void	redir(char **argv, char **env, t_bonus bonus)
{
	pipe(bonus.fd);
	bonus.pid = fork();
	if (bonus.pid)
	{
		close(bonus.fd[1]);
		dup2(bonus.fd[0], STDIN);
		waitpid(bonus.pid, NULL, 0);
	}
	else
	{
		dup2(bonus.fd[0], STDIN);
		dup2(bonus.fd[1], STDOUT);
		if (bonus.fdin == STDIN)
			exit(1);
		else
			exec(bonus, argv, env);
	}
} */

int	ft_pipex(t_split *s, char ***spl, char **env)
{
	t_bonus	bonus;
	int		temp[2];
	int		i;

	i = 0;
	env = 0;
	bonus.fdin = open(ft_file_finder(spl, 0), O_RDONLY);
	bonus.fdout = open(ft_file_finder(spl, 1), O_WRONLY);
	if (bonus.fdin > 0)
	{
		temp[0] = dup(STDIN);
		printf("entro\n");
		printf("dup2: %d\n", bonus.fdin);
		dup2(bonus.fdin, STDIN);
		printf("albvo\n");
	}
	if (bonus.fdout > 0)
	{
		printf("entro2\n");
		temp[1] = dup(STDIN);
		dup2(bonus.fdout, STDOUT);
	}
	while (i < s->ft_len)
	{
		bonus.pid = fork();
		if (bonus.pid == 0)
			exec(bonus, spl[i], env);
		
		waitpid(bonus.pid, NULL, 0);
		i++;
	}
	dup2(temp[0], STDIN);
	dup2(temp[1], STDOUT);
	return (0);
}
