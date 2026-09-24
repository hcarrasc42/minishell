/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:20:54 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/21 09:07:25 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_new_pwd(t_simple_cmd	*cmd, t_mini *state)
{
	char	*new_pwd;

	new_pwd = NULL;
	if (cmd->argc < 2 || !ft_strncmp(cmd->argv[1], "~", 1))
		new_pwd = get_env_dup(state->envp, "HOME");
	else if (!ft_strncmp(cmd->argv[1], "-", 1))
		new_pwd = get_env_dup(state->envp, "OLDPWD");
	else
		new_pwd = ft_strdup(cmd->argv[1]);
	return (new_pwd);
}

int	run_builtin_cd(t_simple_cmd	*cmd, t_mini *state)
{
	char	*pwd;
	char	*old_pwd;
	char	*new_pwd;
	int		result;

	result = ERROR;
	new_pwd = get_new_pwd(cmd, state);
	if (new_pwd)
	{
		old_pwd = getcwd(NULL, 0);
		if (!chdir(new_pwd))
		{
			pwd = getcwd(NULL, 0);
			state->envp = set_env(state->envp, "PWD", pwd);
			state->envp = set_env(state->envp, "OLDPWD", old_pwd);
			free(pwd);
			result = OK;
		}
		else
			printf("cd: %s: No such file or directory\n", new_pwd);
		free(new_pwd);
		free(old_pwd);
	}
	return (result);
}
