/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:02:41 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/20 18:04:39 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*set_token_str(t_token *token, char *str)
{
	char	quote;

	quote = *str;
	if (quote == '\'')
		token->single_quote = 1;
	else if (quote == '\"')
		token->double_quote = 1;
	if (is_token_redirection(token->type) || token->type == TOKEN_PIPE)
	{
		token->str = token_type_to_str(token->type);
		return (skip_token_str(str, token->type));
	}
	else
		token->str = extract_str(str);
	return (skip_enclosed_str(str));
}

static char	*create_token(t_list **tokens, char *str, t_token_type type)
{
	t_token	*token;

	while (str && *str && is_space(*str))
		str++;
	token = ft_malloc(sizeof(t_token));
	token->type = type;
	str = set_token_str(token, str);
	if (token->type != TOKEN_NONE)
	{
		ft_lstadd_back(tokens, ft_lstnew(token));
		if (*str && is_token_redirection(token->type))
			str = create_token(tokens, str, TOKEN_ARG);
	}
	else
		free(token);
	return (str);
}

t_token	*get_token(t_list *token_node)
{
	if (token_node && token_node->content)
		return ((t_token *)token_node->content);
	return (NULL);
}

t_list	*prompt_to_tokens(char *str)
{
	t_list	*tokens;
	int		command;

	tokens = NULL;
	command = 1;
	while (str && *str)
	{
		while (str && *str && is_space(*str))
			str++;
		if (*str == '|' || *str == '>' || *str == '<' || *str == '&')
		{
			str = create_token(&tokens, str, get_token_type(str));
			command = 1;
		}
		else if (*str)
		{
			if (command)
				str = create_token(&tokens, str, TOKEN_CMD);
			else if (*str)
				str = create_token(&tokens, str, TOKEN_ARG);
			command = 0;
		}
	}
	return (tokens);
}
