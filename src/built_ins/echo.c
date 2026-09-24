/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:25:27 by ruramire          #+#    #+#             */
/*   Updated: 2023/06/21 09:07:17 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_escaped_str(char *str)
{
	int		escape;

	escape = 1;
	while (str && *str)
	{
		if (*str == '\\' && escape)
			escape = 0;
		else
		{
			if (*str == '\\')
				escape = 1;
			printf("%c", *str);
		}
		str++;
	}
}

static int	is_new_line_flag(char *str)
{
	int	is_new_line;

	if (!str || *str != '-')
		return (0);
	str++;
	is_new_line = 0;
	while (str && *str)
	{
		if (*str == ' ')
			return (0);
		if (*str != 'n')
			return (0);
		is_new_line = 1;
		str++;
	}
	return (is_new_line);
}

int	run_builtin_echo(t_simple_cmd	*cmd)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (cmd && cmd->argc > 1)
	{
		while (is_new_line_flag(cmd->argv[i]))
		{
			n = 1;
			i++;
		}
		while (i < cmd->argc)
		{
			print_escaped_str(cmd->argv[i++]);
			if (i < cmd->argc)
				printf(" ");
		}
	}
	if (n == 0)
		printf("\n");
	return (OK);
}
