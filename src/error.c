/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:46:50 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/20 15:43:09 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_with_code(t_mini *state, int code)
{
	if (state->readline)
		free(state->readline);
	free_prompt(&state->prompt);
	free_array(state->envp);
	memset(state, 0, sizeof(t_mini));
	exit(code);
}

int	exit_with_error(t_mini *state, char *message_error)
{
	printf("%s", message_error);
	exit_with_code(state, ERROR);
	return (0);
}

int	exit_with_error_code(t_mini *state, int exit_code)
{
	exit_with_code(state, exit_code);
	return (0);
}

int	exit_with_memory_error(t_mini *state)
{
	return (exit_with_error(state, "Not enough memory"));
}

int	exit_without_error(t_mini *state)
{
	exit_with_code(state, OK);
	return (0);
}
