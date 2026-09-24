/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:52:18 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/21 09:07:10 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_builtin_env(t_mini *state)
{
	char	**envp;
	int		i;
	int		j;

	envp = state->envp;
	i = 0;
	while (envp && envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				printf("%s\n", envp[i]);
				break ;
			}
			j++;
		}
		i++;
	}
	return (OK);
}
