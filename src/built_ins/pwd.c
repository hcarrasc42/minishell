/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:18:34 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/21 09:06:41 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_builtin_pwd(t_mini *state)
{
	char	**envp;
	char	*pwd;

	envp = state->envp;
	pwd = get_env(envp, "PWD");
	if (pwd)
		printf("%s\n", pwd);
	return (OK);
}
