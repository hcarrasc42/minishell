/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:15:47 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:10:36 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_node_content(void *content)
{
	t_simple_cmd	*cmd;

	cmd = content;
	if (!cmd)
		return ;
	if (cmd->argv != NULL)
		free_array(cmd->argv);
	if (cmd->argv_quoted != NULL)
		free_array(cmd->argv_quoted);
	if (cmd->redirections != NULL)
		free_redirections(cmd->redirections);
	free(cmd);
}

void	free_cmd_table(t_cmd *table)
{
	if (!table)
		return ;
	ft_lstclear(&table->cmds, free_node_content);
	free(table);
}

t_cmd	*tokens_to_cmd_table(t_list *tokens)
{
	t_cmd	*table;
	t_token	*token;

	table = ft_malloc(sizeof(t_cmd));
	while (tokens)
	{
		token = get_token(tokens);
		if (!token->ignore
			&& (token->type == TOKEN_CMD || is_token_redirection(token->type)))
			tokens = add_cmd(tokens, table);
		else
			tokens = tokens->next;
	}
	return (table);
}

void	exec_cmd_table(t_cmd *table, t_mini *state)
{
	t_list			*cmds;

	if (!table)
		return ;
	cmds = table->cmds;
	while (cmds)
	{
		exec_cmd(cmds, state);
		cmds = cmds->next;
	}
}
