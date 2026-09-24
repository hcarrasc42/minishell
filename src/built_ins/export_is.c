/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:47:10 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/21 09:06:57 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_var_name(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

static int	syntax_error(char *str)
{
	ft_putstr_fd("export: '", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	return (0);
}

int	is_valid_export(char *variables)
{
	char	**variable_split;
	int		result;

	result = 1;
	if (result == 1 && ft_strlen(variables))
	{
		if (variables[0] == '=' && variables[1] == '\0')
		{
			syntax_error(variables);
			result = 0;
		}
		else
		{
			variable_split = ft_split(variables, '=');
			if (!is_valid_var_name(variable_split[0]))
			{
				syntax_error(variable_split[0]);
				result = 0;
			}
			free_array(variable_split);
		}
	}
	return (result);
}
