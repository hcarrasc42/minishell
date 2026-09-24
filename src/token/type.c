/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:42:01 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:14:12 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	get_token_type(char *str)
{
	t_token_type	type;

	type = TOKEN_NONE;
	if (str && *str == '|')
		type = TOKEN_PIPE;
	else if (str && *str == '>' && *(str + 1) == '>')
		type = TOKEN_GREATGREAT;
	else if (str && *str == '>')
		type = TOKEN_GREAT;
	else if (str && *str == '<' && *(str + 1) == '<')
		type = TOKEN_LESSLESS;
	else if (str && *str == '<')
		type = TOKEN_LESS;
	else if (str && *str == '&')
		type = TOKEN_AMP;
	return (type);
}

char	*token_type_to_str(t_token_type type)
{
	if (type == TOKEN_PIPE)
		return (ft_strdup("|"));
	else if (type == TOKEN_GREAT)
		return (ft_strdup(">"));
	else if (type == TOKEN_GREATGREAT)
		return (ft_strdup(">>"));
	else if (type == TOKEN_AMP)
		return (ft_strdup("&"));
	else if (type == TOKEN_LESS)
		return (ft_strdup("<"));
	else if (type == TOKEN_LESSLESS)
		return (ft_strdup("<<"));
	return (ft_strdup(""));
}

int	is_token_redirection(t_token_type type)
{
	if (type == TOKEN_GREAT || type == TOKEN_GREATGREAT
		|| type == TOKEN_LESS || type == TOKEN_LESSLESS)
		return (1);
	return (0);
}
