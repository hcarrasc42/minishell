/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msh_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:10:54 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/23 13:31:45 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/main.h"

//path = get_path(spl[0][0], env);
//execve(path, spl[0], env);

char	*ft_cmd_finder(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] != '<' && cmd[i][0] != '>')
			return (ft_strdup(cmd[i]));
		i++;
	}
	return (0);
}

void	ft_exceve(t_bonus b, char **spl, char **env)
{
	char	*path;
	char	**cmd;

	cmd = ft_strremover(spl);
	path = get_path(cmd[0], env);
	printf("path: %s\n", path);
	execve(path, cmd, env);
}

int	ft_msh_pipex(t_split *s, char ***spl, char **env)
{
	t_bonus	b;
	int		i;
	int		tmp[1];

	i = 0;
	tmp[0] = dup(STDIN);
	b.fdin = open(ft_file_finder(spl, 0), O_RDONLY);
	if (b.fdin > 0)
		dup2(b.fdin, STDIN);
	while (i < 1)
	{
		ft_exceve(b, spl[i], env);
		i++;
	}
	dup2(tmp[0], STDIN);
	return (0);
}
