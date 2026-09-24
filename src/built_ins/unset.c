/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:47:28 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/21 09:06:33 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	keys_checker(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**remove_keys_from_array(char **array, char	**keys)
{
	int		i;

	i = 0;
	while (keys && keys[i])
	{
		if (!keys_checker(keys[i]))
		{
			ft_putstr_fd("unset: '", 2);
			ft_putstr_fd(keys[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			i++;
		}
		else
		{
			array = del_str_from_array(array, keys[i]);
			i++;
		}
	}
	return (array);
}

int	run_builtin_unset(t_simple_cmd	*cmd, t_mini *state)
{
	char	**keys;
	int		i;

	if (cmd->argc < 2)
		return (ERROR);
	i = 1;
	while (i < cmd->argc)
	{
		keys = ft_split(cmd->argv[i], ' ');
		state->envp = remove_keys_from_array(state->envp, keys);
		free_array(keys);
		i++;
	}
	return (OK);
}
