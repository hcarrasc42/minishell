/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:22:45 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/20 18:37:42 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sanitize_token_strings(t_list *tokens)
{
	while (tokens)
	{
		tokens = tokens->next;
	}
}

int	free_prompt(t_prompt *prompt)
{
	if (prompt->prompt)
		free(prompt->prompt);
	if (prompt->pwd)
		free(prompt->pwd);
	memset(prompt, 0, sizeof(t_prompt));
	return (1);
}

static void	process_readline(char *str, t_mini *state)
{
	t_list	*tokens;
	t_cmd	*cmd_table;

	tokens = prompt_to_tokens(str);
	if (!tokens)
		return ;
	expand_token_strings(tokens, state);
	sanitize_token_strings(tokens);
	if (validate_syntax_tokens(tokens))
	{
		cmd_table = tokens_to_cmd_table(tokens);
		exec_cmd_table(cmd_table, state);
		free_cmd_table(cmd_table);
	}
	else
		printf("syntax error unexpected token\n");
	free_tokens(tokens);
}

char	*ft_read(t_mini *state)
{
	state->prompt.prompt = ft_strdup("minishell$> ");
	state->readline = readline(state->prompt.prompt);
	if (!state->readline)
	{
		printf("exit\n");
		exit_without_error(state);
	}
	if (ft_strlen(state->readline))
	{
		add_history(state->readline);
		process_readline(state->readline, state);
	}
	free_prompt(&state->prompt);
	return (state->readline);
}
