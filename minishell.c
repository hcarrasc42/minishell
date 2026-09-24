/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:10:27 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/20 14:07:07 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char **envp)
{
	t_mini		state;

	(void) argv;
	if (argc != 1)
	{
		printf("Error: solo se permite ./minishell\n");
		return (0);
	}
	if (!initvar(&state, envp))
		return (exit_with_error(&state, "Error initializing"));
	setup_parent_signals();
	while (1)
	{
		ft_read(&state);
		free(state.readline);
		state.readline = NULL;
	}
	exit_without_error(&state);
	return (0);
}

int	initvar(t_mini *state, char **envp)
{
	memset(state, 0, sizeof(t_mini));
	state->envp = duplicate_array(envp);
	return (1);
}
