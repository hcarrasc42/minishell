/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:58:12 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/21 09:07:04 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_arg(char	*str)
{
	int	has_any_digit;
	int	has_any_sign;

	has_any_digit = 0;
	has_any_sign = 0;
	while (str && *str)
	{
		has_any_digit = ft_isdigit(*str);
		if (*str == '-' || *str == '+')
		{
			if (has_any_sign)
				return (0);
			has_any_sign = 1;
		}
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (has_any_digit);
}

int	run_builtin_exit(t_simple_cmd	*cmd, t_mini *state)
{
	if (cmd->argc > 1)
	{
		if (!is_valid_arg(cmd->argv[1]))
		{
			printf("exit\nexit: %s: numeric argument required\n",
				cmd->argv[1]);
			return (exit_with_error_code(state, 255));
		}
		if (cmd->argc > 2)
		{
			printf("exit: too many arguments\n");
			return (ERROR);
		}
		printf("exit\n");
		return (exit_with_error_code(state, ft_atoi(cmd->argv[1])));
	}
	printf("exit\n");
	return (exit_without_error(state));
}
